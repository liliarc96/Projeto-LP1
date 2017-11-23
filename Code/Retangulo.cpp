//C++: void rectangle(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
//Fonte: https://stackoverflow.com/questions/40120433/draw-rectangle-in-opencv-by-c

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int main(){
Mat img=imread("myImage.jpg");

Rect r=Rect(10,20,40,60);
//create a Rect with top-left vertex at (10,20), of width 40 and height 60 pixels.

rectangle(img,r,Scalar(255,0,0),1,8,0);
//draw the rect defined by r with line thickness 1 and Blue color

imwrite("myImageWithRect.jpg",img);


return 0;
}
