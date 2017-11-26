#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Imagem.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace cv;

int Imagem::reconhecerCor(){
  int j;

  for(j = 0; j < 5; j++){
    GeraCor::SortearCor();

    VideoCapture cap(0); //capture the video from webcam

    if ( !cap.isOpened() ){
         cout << "Falha ao abrir a camera" << endl;
         return -1;
    }

    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

    int iLowH = 170;
    int iHighH = 179;

    int iLowS = 150;
    int iHighS = 255;

    int iLowV = 60;
    int iHighV = 255;

    //Create trackbars in "Control" window
    /*MATRIZ
    - Matriz Amarelo (22-38)
    - Matriz Azul (75-130)
    - Matriz Branco(255-255)
    - Matriz Preto(0-0)
    - Matriz Verde (38-75)
    - Matriz Vermelho (160-179)*/

    createTrackbar("LowH", "Control", &iLowH, 179);
    createTrackbar("HighH", "Control", &iHighH, 179);

    /*SATURAÇÃO*/
    createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    createTrackbar("HighS", "Control", &iHighS, 255);

    /*VALOR*/
    createTrackbar("LowV", "Control", &iLowV, 255);//Value (0 - 255)
    createTrackbar("HighV", "Control", &iHighV, 255);

    int iLastX = -1;
    int iLastY = -1;

    //Capture a temporary image from the camera
    Mat imgTmp;
    cap.read(imgTmp);

    //Create a black image with the size as the camera output
    Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );;


    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal);

        if (!bSuccess) { //se não funcionar o while é fechado
             cout << "Nao e possivel ler o video" << endl;
             break;
        }

        Mat imgHSV;

        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

        Mat imgThresholded;

        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

        //morphological opening (removes small objects from the foreground)
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        //morphological closing (removes small holes from the foreground)
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        //Calculate the moments of the thresholded image
        Moments oMoments = moments(imgThresholded);

        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;

        // if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero
        if (dArea > 10000){
          //calculate the position of the ball
          int posX = dM10 / dArea;
          int posY = dM01 / dArea;

          if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0){
            //Draw a red line from the previous point to the current point
            line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
          }

          iLastX = posX;
          iLastY = posY;
        }

        imshow("Thresholded Image", imgThresholded); //show the thresholded image

        imgOriginal = imgOriginal + imgLines;
        imshow("Original", imgOriginal); //show the original image

        if (waitKey(30) == 27){ //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
          cout << "esc key is pressed by user" << endl;
          break;
        }
      }
  }

  return 1;
}
