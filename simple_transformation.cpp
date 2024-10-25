#include <opencv2/opencv.hpp>


int main(int argc, char** argv){

     cv::Mat img = cv::imread(argv[1],-1);
     if( img.empty()) return -1;

     cv::namedWindow("In", cv::WINDOW_AUTOSIZE);
     cv::namedWindow("out", cv::WINDOW_AUTOSIZE);
     
     cv::imshow("In", img);

     cv::Mat out;

     //smoothing
     cv::GaussianBlur(img, out, cv::Size(5,5), 3,3);
     cv::GaussianBlur(out, out, cv::Size(5,5), 3,3);

     cv::imshow("Out", out);

     cv::waitKey(0);



     return 0;
}