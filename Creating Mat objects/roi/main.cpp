
#include "opencv2/opencv.hpp" 
using namespace cv;
using namespace std;
 
int main( int argc, char** argv )
{
        Mat img = imread("image01.jpg"); 
        Rect r( 100, 50, 200, 150 ); // Создание региона

        Mat img2;
        // Копирование региона в отдельное изображение
        img( r ).copyTo( img2 ); 
        img2 += CV_RGB(0,0,255); // Добавляем синего к изображению
        
        // Изменение части изображения
        img( r ) *= 0.5; // Понижение яркости

        imwrite( "image01_res6.jpg", img2 );
        imwrite( "image01_res7.jpg", img );
        imshow("img", img );
        imshow("img2", img2 );
        waitKey(0);
    return 0;
}