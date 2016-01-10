
#include "opencv2/opencv.hpp" 
using namespace cv;
using namespace std;
 
int main( int argc, char** argv )
{
       Mat img = imread("image01.jpg"); // Открытие файла

        // Отобразить на изображении белую пунктирную сетку
        for( int i = 0; i < img.rows; i++ )
                for( int j = 0; j < img.cols; j++ )
                        if ( ( i % 20 == 10 && j % 2 == 1 ) ||
                                 ( j % 50 == 25 && i % 2 == 1 ) )
                        {
                                img.at<Vec3b>(i,j)[0]= 255;
                                img.at<Vec3b>(i,j)[1]= 255;
                                img.at<Vec3b>(i,j)[2]= 255;
                        }
        imshow("image01_res.jpg", img );
        waitKey(0);
    return 0;
}