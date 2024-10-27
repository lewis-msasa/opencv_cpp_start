#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char* argv[]){

    cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);

    cv::VideoCapture capture(argv[1]);

    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(
        (int)capture.get(cv::CAP_PROP_FRAME_WIDTH),
        (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)
    );

    cv::VideoWriter writer;
    writer.open(argv[2], cv::VideoWriter::fourcc('M','J','P','G'), fps, size);

    cv::Mat logpolar_frame, bgr_frame;

    for(;;){
        capture >> bgr_frame;
        if(bgr_frame.empty()) break;

        cv::imshow("Example", bgr_frame);

        cv::logPolar(
            bgr_frame, //input color frame
            logpolar_frame, // output log-polar frame
            cv::Point2f(
                bgr_frame.cols/2, //centerpoint for log-polar transformation, x, y
                bgr_frame.rows/2
            ),
            40,   // Magniture (scale parameter)
            cv::WARP_FILL_OUTLIERS //fill outliers with 'zero'
        );

        cv::imshow("Log_Polar", logpolar_frame);
        writer << logpolar_frame;

        char c = cv::waitKey(10);
        if(c == 27) break;
    }



    return 0;

}