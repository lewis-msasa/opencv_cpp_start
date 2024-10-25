#include <opencv2/opencv.hpp>


using namespace cv;

int main(int argc, char** argv){

    Mat img = cv::imread(argv[1],-1);
    if( img.empty()) return -1;

    namedWindow("example", WINDOW_AUTOSIZE);
    imshow("example", img);
    waitKey(0);
    destroyWindow("Example");
    
    return 0; 
}