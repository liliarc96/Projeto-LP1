#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Imagem.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace cv;

int Imagem::reconhecerCor(){
  int j;
  int pontostotais; //Pontuação da rodada
  int p; //Ponto por core

  for(j = 0; j < 5; j++){
    //abrir camera
    VideoCapture cap(0); //Captura imagem da webcam
    if(!cap.isOpened()){
      cout << "Falha ao abrir camera" << endl;
      return -1; // Se a camera não abri o programa vai fechar
    }
    //camera ligada
    namedWindow("Control", CV_WINDOW_AUTOSIZE); //Abri janela chamada "Control"
  /*int iLowH = 170;
    int iHighH = 179;

    int iLowS = 150;
    int iHighS = 255;

    int iLowV = 60;
    int iHighV = 255;*/

    /*Criando trackbars na janela "Control": Matrizes das Cores
    - Matriz Amarelo (22-38)
    - Matriz Azul (75-130)
    - Matriz Branco(255-255)
    - Matriz Preto(0-0)
    - Matriz Verde (38-75)
    - Matriz Vermelho (160-179)*/

    createTrackbar("LowH", "Control", &iLowH, 179);
    createTrackbar("HighH", "Control", &iHighH, 179);
    //Saturação
    createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    createTrackbar("HighS", "Control", &iHighS, 255);
    //Valor
    createTrackbar("LowV", "Control", &iLowV, 255);//Value (0 - 255)
    createTrackbar("HighV", "Control", &iHighV, 255);

    int iLastX = -1;
    int iLastY = -1;
    //Capturando imagem
    Mat imgTmp;
    cap.read(imgTmp);
    //Criando outra imagem
    Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );;

    while (true){ //Começo do while
      Mat imgOriginal;
      bool bSuccess = cap.read(imgOriginal);

      if (!bSuccess) { //se não funcionar o while é fechado
          cout << "Nao e possivel ler o video" << endl;
          break;
      }

      Mat imgHSV;
      cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Converter o frame de BGR para HSV

      Mat imgThresholded;
      inRange(imgHSV, Scalar(170, 150, 60), Scalar(179, 255, 255), imgThresholded); //Threshold the image

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
            //Desenha uma linha vermelha por onde o objeto passar
            line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
         }

         iLastX = posX;
         iLastY = posY;
       }

      imshow("Thresholded Image", imgThresholded); //show the thresholded image

      imgOriginal = imgOriginal + imgLines;
      imshow("Original", imgOriginal); //show the original image

      if (waitKey(30) == 27){ //Se o esc for pressionado quebra o loop
          cout << "Tecla Esc foi pressionada pelo usuario" << endl;
          break;
       }
   } // Fim do while
 } //Fim do laço for


  return 1;
}
