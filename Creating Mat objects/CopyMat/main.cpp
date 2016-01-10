
#include "opencv2/opencv.hpp" 
using namespace cv;
using namespace std;
 
int main( int argc, char** argv )
{

        Mat img = imread( "image01.jpg"); // Открытие файла
        
        Mat img2;
        img.copyTo( img2 );
        img2 = img2 * 2; // Увеличение яркости в 2 раза

        Mat img3;
        img.copyTo( img3 );
        img3 = img3 * 0.25; // Уменьшение яркости в 4 раза

        imwrite("img2.jpg",img2);
        imwrite("img3.jpg",img3);

        imshow("img", img);
        imshow("img2", img2);
        imshow("img3", img3);

        waitKey(0);
    return 0;
}