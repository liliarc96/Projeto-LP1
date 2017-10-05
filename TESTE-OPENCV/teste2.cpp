#include <iostream> 
 
using namespace std;
 
#include "cv.h"
#include "highgui.h"
 
int main(int argc, char** argv){
 
    IplImage* pImg;
 
    if((pImg = cvLoadImage("imagem.jpg",1)) != 0){
        cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
        cvShowImage("Image",pImg);
        cvWaitKey(0);
        cvDestroyWindow("Image");
        cvReleaseImage(&amp;pImg);
        return 0;
    }
    return -1;
}
