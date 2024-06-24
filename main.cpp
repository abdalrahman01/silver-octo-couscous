#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>
#include <unistd.h>   

int main() {
    cv::String url = "rtsp://807e9439d5ca.entrypoint.cloud.wowza.com:1935/app-rC94792j/068b9c9a_stream2";
    // Create a VideoCapture object to capture video from the RTSP stream
    cv::VideoCapture cap(url);

    // Check if camera opened successfully
    if(!cap.isOpened()) {
        std::cout << "Error: Could not open stream." << std::endl;
        return -1;
    }

    cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);
    std::vector<uint8_t> input_image;
    int i = 0;
    while(true) {
        cv::Mat frame;
        // Read the current frame from the stream
        bool ret = cap.read(frame);

        // If frame is empty, break immediately
        if (!ret) {
            std::cout << "Failed to capture frame from video stream" << std::endl;
            break;
        }

         // Convert Mat to vector of shape (1, w, h, 3)
        std::vector<cv::Mat> frameVector(1, frame);
        if (frame.isContinuous()) {
        input_image.assign(frame.data, frame.data + frame.total() * frame.channels());
        } else {
            for (int i = 0; i < frame.rows; ++i) {
                input_image.insert(input_image.end(), frame.ptr<uint8_t>(i), frame.ptr<uint8_t>(i) + frame.cols * frame.channels());
            }
        }
        std::cout << "myvector contains: " << input_image.size();
        std::cout << '\n';

        i++;
        sleep( 1 ); 
        // Display the frame in a window named "Webcam"
        // cv::imshow("title", frame);

        // // Break the loop if the 'q' key is pressed
        // if (cv::waitKey(1) == 'q') {
        //     break;
        // }
    }

    


    // Release the VideoCapture object and close the window
    cap.release();
    cv::destroyAllWindows();

    return 0;
}