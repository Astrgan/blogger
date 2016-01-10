
#include "opencv2/opencv.hpp" 
using namespace cv;
using namespace std;
 
int main( int argc, char** argv )
{
      Mat img = imread( "image01.jpg"); // Открытие файла

        for( int i = 0; i < img.rows; i++ )
                for( int j = 0; j < img.cols; j++ )
                        if ( img.at<Vec3b>(i,j)[0] < img.at<Vec3b>(i,j)[1] - 10 && 
                                 img.at<Vec3b>(i,j)[2] < img.at<Vec3b>(i,j)[1] - 10 &&
                                 img.at<Vec3b>(i,j)[1] > 64 )
                        {
                                img.at<Vec3b>(i,j)[0]= 0;
                                img.at<Vec3b>(i,j)[1]= 0;
                                img.at<Vec3b>(i,j)[2]= 255;
                        }
        imshow("image01_res.jpg", img );
        waitKey(0);
    return 0;
}