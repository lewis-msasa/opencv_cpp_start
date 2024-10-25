#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>


using namespace cv;


int main(int argc, char** argv){

     namedWindow("Example Video", WINDOW_AUTOSIZE );
     VideoCapture cap;
    
     if (!cap.open(std::string(argv[1]))) {
        std::cerr << "Error opening video file." << std::endl;
        return -1; // Ensure proper error handling
    }
     //frame to hold video
     Mat frame;

     for(;;){
        cap >> frame;
        if (frame.empty()) break;

        cv::imshow("example video", frame);
        //wait for 33ms. If user hits a key after that, exist the read loop
        if(cv::waitKey(33) >= 0) break;
     }


    
    return 0;
}