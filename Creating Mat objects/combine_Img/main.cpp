
#include "opencv2/opencv.hpp" 
using namespace cv;
using namespace std;
 
int main( int argc, char** argv )
{
        // Отобразить на изображении белую пунктирную сетку
        Mat img = imread( "img2.jpg"); 
        Mat img2 = imread( "img3.jpg");              
        
        img2 = img2 + img; // Сложение матриц
        imshow("res",img2);
        imwrite( "Res.jpg", img2 );

        waitKey(0);
    return 0;
}