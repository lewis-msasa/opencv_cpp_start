#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
    cv::Mat img1, img2;

    cv::namedWindow("Image1", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Image2", cv::WINDOW_AUTOSIZE);

    img1 = cv::imread(argv[1]);
    cv::imshow("Image1", img1);

    //this runs a high-pass filter to prevent aliasing
    cv::pyrDown(img1, img2);
    cv::imshow("Image2", img2);

    cv::waitKey(0);

    return 0;
}