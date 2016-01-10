#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

struct userdata{
    Mat im;
    vector<Point2f> points;
};


void mouseHandler(int event, int x, int y, int flags, void* data_ptr)
{
    if  ( event == EVENT_LBUTTONDOWN )
    {
        userdata *data = ((userdata *) data_ptr);
        circle(data->im, Point(x,y),3,Scalar(0,0,255), 5, CV_AA);
        imshow("Image", data->im);
        if (data->points.size() < 4)
        {
            data->points.push_back(Point2f(x,y));
        }
    }
    
}



int main( int argc, char** argv)
{

    // Чтения исходного изображения
    Mat im_src = imread("../data/book1.jpg");

    // Относительные размеры книги 3/4
    Size size(300,400);
    Mat im_dst = Mat::zeros(size,CV_8UC3);

    
    // Вектор место назначения
    vector<Point2f> pts_dst;
    
    pts_dst.push_back(Point2f(0,0));
    pts_dst.push_back(Point2f(size.width - 1, 0));
    pts_dst.push_back(Point2f(size.width - 1, size.height -1));
    pts_dst.push_back(Point2f(0, size.height - 1 ));
    
    // Набор данных для событий мыши
    Mat im_temp = im_src.clone();
    userdata data;
    data.im = im_temp;

    cout << "Нажмите на 4 стороны книги" << endl
    << "и нажмите ENTER" << endl;
    
    // Показать изображения и ожидать 4 кликов. 
    imshow("Image", im_temp);
    // Функция обратного вызова для любого сочитания клавиш
    setMouseCallback("Image", mouseHandler, &data);
    waitKey(0);
    
    // Расчитываем омограф
    Mat h = findHomography(data.points, pts_dst);
    
    // диформируем изображения
    warpPerspective(im_src, im_dst, h, size);
    
    // Показать результат
    imshow("Image", im_dst);
    waitKey(0);

    return 0;
}
