//
// Created by GoForBroke on 21.09.17.
//

#include <dlib/image_processing/frontal_face_detector.h>
//#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/image_io.h>

using namespace dlib;
using namespace std;

int main(int argc, char **argv) {
    try {
        if (argc == 1) {
            cout << "Call this program like this:" << endl;
            cout << "./face_detect_cpp_demo_1 shape_predictor_68_face_landmarks.dat faces/*.jpg" << endl;
            return 0;
        }

        frontal_face_detector detector = get_frontal_face_detector();
        shape_predictor sp;
        deserialize(argv[1]) >> sp;

//        image_window win, win_faces;
        for (int i = 2; i < argc; ++i) {
            cout << "processing image " << argv[i] << endl;
            array2d<rgb_pixel> img;
            load_image(img, argv[i]);
            pyramid_up(img);

            std::vector<rectangle> dets = detector(img, 0);
            cout << argv[i] << " - number of faces detected: " << dets.size() << endl;

//            std::vector<full_object_detection> shapes;
            for (unsigned long j = 0; j < dets.size(); ++j) {
                const full_object_detection& d = sp(img, dets[j]);
//                cout << "number of parts: " << shape.num_parts() << endl;
//                cout << "pixel position of first part:  " << shape.part(0) << endl;
//                cout << "pixel position of second part: " << shape.part(1) << endl;
//                shapes.push_back(shape);

//                const full_object_detection& d = dets[i];

                cout << "Left eye: ";
                for (unsigned long k = 37; k <= 41; ++k)
                    cout << d.part(k) << " " << d.part(k - 1) << " ";
                cout << endl;

                cout << "Right eye: ";
                for (unsigned long k = 43; k <= 47; ++k)
                    cout << d.part(k) << " " << d.part(k - 1) << " ";
                cout << endl;
            }

//            win.clear_overlay();
//            win.set_image(img);
//            win.add_overlay(render_face_detections(shapes));
//
//            dlib::array<array2d<rgb_pixel> > face_chips;
//            extract_image_chips(img, get_face_chip_details(shapes), face_chips);
//            win_faces.set_image(tile_images(face_chips));

            cout << "Hit enter to process the next image..." << endl;
            cin.get();
        }
    } catch (exception &e) {
        cout << "\nexception thrown!" << endl;
        cout << e.what() << endl;
    }
}