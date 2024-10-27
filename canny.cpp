#include <opencv2/opencv.hpp>


int main( int argc, char** argv){

    cv::Mat img_rgb, img_gry, img_cny;

    cv::namedWindow("Gray", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Canny", cv::WINDOW_AUTOSIZE);

    img_rgb = cv::imread(argv[1]);


    cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
    cv::imshow("Gray", img_gry);

    cv::Canny(img_gry, img_cny, 10, 100, 3, true);
    cv::imshow("Canny", img_cny);

    cv::waitKey(0);

    return 0;

}