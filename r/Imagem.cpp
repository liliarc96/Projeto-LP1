#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/cvconfig.h"
#include "Imagem.h"
#include <iostream>
#include <stdlib.h>

//Fonte do código para detectar cor: https://opencv-srf.blogspot.com.br/2010/09/object-detection-using-color-seperation.html

using namespace std;
using namespace cv;

void Imagem::setA(int a){
    this->a = a;
}

int Imagem::getA(){
    return a;
}

void Imagem::reconhecerAmarelo(int a){
    Mat frame;
    a = 0; //confirmação de captura de cor
    Cor::mostrarAmarelo();
    VideoCapture cap(0); //Captura imagem da webcam
    if(!cap.isOpened()){
      cout << "Falha ao abrir camera" << endl;
      exit(1); // Se a camera não abri o programa vai fechar
    }
    //camera ligada
    namedWindow("Control", CV_WINDOW_AUTOSIZE); //Abri janela chamada "Control"

    /*Criando trackbars na janela "Control": Matrizes das Cores
    - Matriz Amarelo (22-38)
    - Matriz Azul (75-130)
    - Matriz Branco(255-255)
    - Matriz Preto(0-0)
    - Matriz Verde (38-75)
    - Matriz Vermelho (160-179)*/

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
        //
        inRange(imgHSV, Scalar(22, 38, 60), Scalar(179, 255, 255), imgThresholded); //Threshold the image

        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        Moments oMoments = moments(imgThresholded);

        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;


        if (dArea > 10000){
            //Calcula a posição da cor
            int posX = dM10 / dArea;
            int posY = dM01 / dArea;

            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0){
                //Desenha uma linha vermelha por onde o objeto passar
                line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
                setA(a++);
            } /* else {
                cout << "Cor não detectada" << endl;

                setA(0);
            }*/

            iLastX = posX;
            iLastY = posY;
        }

        imshow("Thresholded Image", imgThresholded); //mostra a imagem thresholded

        imgOriginal = imgOriginal + imgLines;
        imshow("Original", imgOriginal);

        if (waitKey(30) == 27){ //Se o esc for pressionado quebra o loop
            cout << "Tecla Esc foi pressionada pelo usuario" << endl;
            break;
        }
    } // Fim do while

    //return a;
}

void Imagem::reconhecerAzul(int a){
    a = 0; //confirmação de captura de cor
    Cor::mostrarAzul();
    VideoCapture cap(0); //Captura imagem da webcam
    if(!cap.isOpened()){
      cout << "Falha ao abrir camera" << endl;
      exit(1); // Se a camera não abri o programa vai fechar
    }
    //camera ligada
    namedWindow("Control", CV_WINDOW_AUTOSIZE); //Abri janela chamada "Control"

    /*Criando trackbars na janela "Control": Matrizes das Cores
    - Matriz Amarelo (22-38)
    - Matriz Azul (75-130)
    - Matriz Branco(255-255)
    - Matriz Preto(0-0)
    - Matriz Verde (38-75)
    - Matriz Vermelho (160-179)*/

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
        //Valores para cor
        inRange(imgHSV, Scalar(75, 130, 60), Scalar(179, 255, 255), imgThresholded); //Threshold imagem

        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );


        Moments oMoments = moments(imgThresholded);

        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;


        if (dArea > 10000){
            //calcula a posição
            int posX = dM10 / dArea;
            int posY = dM01 / dArea;

            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0){
                //Desenha uma linha vermelha por onde o objeto passar
                line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
                setA(a++);
            } /*else {
                cout << "Cor não detectada" << endl;

                setA(0);
            }*/

            iLastX = posX;
            iLastY = posY;
        }

        imshow("Thresholded Image", imgThresholded); //mostrar a imagem thresholded

        imgOriginal = imgOriginal + imgLines;
        imshow("Original", imgOriginal); //

        if (waitKey(30) == 27){ //Se o esc for pressionado quebra o loop
            cout << "Tecla Esc foi pressionada pelo usuario" << endl;
            break;
        }
    } // Fim do while

}

void Imagem::reconhecerBranco(int a){
    a = 0; //confirmação de captura de cor
    Cor::mostrarBranco();
    VideoCapture cap(0); //Captura imagem da webcam
    if(!cap.isOpened()){
      cout << "Falha ao abrir camera" << endl;
      exit(1); // Se a camera não abri o programa vai fechar
    }
    //camera ligada
    namedWindow("Control", CV_WINDOW_AUTOSIZE); //Abri janela chamada "Control"

    /*Criando trackbars na janela "Control": Matrizes das Cores
    - Matriz Amarelo (22-38)
    - Matriz Azul (75-130)
    - Matriz Branco(255-255)
    - Matriz Preto(0-0)
    - Matriz Verde (38-75)
    - Matriz Vermelho (160-179)*/

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
        //Valores para cor
        inRange(imgHSV, Scalar(255, 255, 60), Scalar(179, 255, 255), imgThresholded); //Threshold the image

        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        Moments oMoments = moments(imgThresholded);

        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;


        if (dArea > 10000){
            //calcula a posição
            int posX = dM10 / dArea;
            int posY = dM01 / dArea;

            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0){
                //Desenha uma linha vermelha por onde o objeto passar
                line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
                setA(a++);
            } /*else {
                cout << "Cor não detectada" << endl;

                setA(0);
            }*/


            iLastX = posX;
            iLastY = posY;
        }

        imshow("Thresholded Image", imgThresholded); //mostrar a imagem thresholded

        imgOriginal = imgOriginal + imgLines;
        imshow("Original", imgOriginal); //show the original image

        if (waitKey(30) == 27){ //Se o esc for pressionado quebra o loop
            cout << "Tecla Esc foi pressionada pelo usuario" << endl;
            break;
        }
    } // Fim do while

}

void Imagem::reconhecerPreto(int a){
    a = 0; //confirmação de captura de cor
    Cor::mostrarPreto();
    VideoCapture cap(0); //Captura imagem da webcam
    if(!cap.isOpened()){
      cout << "Falha ao abrir camera" << endl;
      exit(1); // Se a camera não abri o programa vai fechar
    }
    //camera ligada
    namedWindow("Control", CV_WINDOW_AUTOSIZE); //Abri janela chamada "Control"

    /*Criando trackbars na janela "Control": Matrizes das Cores
    - Matriz Amarelo (22-38)
    - Matriz Azul (75-130)
    - Matriz Branco(255-255)
    - Matriz Preto(0-0)
    - Matriz Verde (38-75)
    - Matriz Vermelho (160-179)*/

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
        //
        inRange(imgHSV, Scalar(0, 0, 60), Scalar(179, 255, 255), imgThresholded); //Threshold imagem

        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        Moments oMoments = moments(imgThresholded);

        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;

        if (dArea > 10000){
            //Calcula a posição da cor
            int posX = dM10 / dArea;
            int posY = dM01 / dArea;

            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0){
                //Desenha uma linha vermelha por onde o objeto passar
                line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
                setA(a++);
            } /*else {
                cout << "Cor não detectada" << endl;

                setA(0);
            }*/


            iLastX = posX;
            iLastY = posY;
        }

        imshow("Thresholded Image", imgThresholded); //Mostra a imagem thresholded

        imgOriginal = imgOriginal + imgLines;
        imshow("Original", imgOriginal);

        if (waitKey(30) == 27){ //Se o esc for pressionado quebra o loop
            cout << "Tecla Esc foi pressionada pelo usuario" << endl;
            break;
        }
    } // Fim do while

}

void Imagem::reconhecerVerde(int a){
    a = 0; //confirmação de captura de cor
    Cor::mostrarVerde();
    VideoCapture cap(0); //Captura imagem da webcam
    if(!cap.isOpened()){
      cout << "Falha ao abrir camera" << endl;
      exit(1); // Se a camera não abri o programa vai fechar
    }
    //camera ligada
    namedWindow("Control", CV_WINDOW_AUTOSIZE); //Abri janela chamada "Control"

    /*Criando trackbars na janela "Control": Matrizes das Cores
    - Matriz Amarelo (22-38)
    - Matriz Azul (75-130)
    - Matriz Branco(255-255)
    - Matriz Preto(0-0)
    - Matriz Verde (38-75)
    - Matriz Vermelho (160-179)*/

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
        //Valores para cores
        inRange(imgHSV, Scalar(38, 75, 60), Scalar(179, 255, 255), imgThresholded); //Threshold imagem

        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        Moments oMoments = moments(imgThresholded);

        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;

        if (dArea > 10000){
            //Calcula a posição da cor
            int posX = dM10 / dArea;
            int posY = dM01 / dArea;

            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0){
                //Desenha uma linha vermelha por onde o objeto passar
                line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
                setA(a++);
            } /*else {
                cout << "Cor não detectada" << endl;

                setA(0);
            }*/

            iLastX = posX;
            iLastY = posY;

        }

        imshow("Thresholded Image", imgThresholded); //Mostra a imagem thresholded

        imgOriginal = imgOriginal + imgLines;
        imshow("Original", imgOriginal); //

        if (waitKey(30) == 27){ //Se o esc for pressionado quebra o loop
            cout << "Tecla Esc foi pressionada pelo usuario" << endl;
            break;
        }
    } // Fim do while

}

void Imagem::reconhecerVermelho(int a){
    a = 0; //confirmação de captura de cor
    Cor::mostrarVermelho();
    VideoCapture cap(0); //Captura imagem da webcam
    if(!cap.isOpened()){
      cout << "Falha ao abrir camera" << endl;
      exit(1); // Se a camera não abri o programa vai fechar
    }
    //camera ligada
    namedWindow("Control", CV_WINDOW_AUTOSIZE); //Abri janela chamada "Control"

    /*Criando trackbars na janela "Control": Matrizes das Cores
    - Matriz Amarelo (22-38)
    - Matriz Azul (75-130)
    - Matriz Branco(255-255)
    - Matriz Preto(0-0)
    - Matriz Verde (38-75)
    - Matriz Vermelho (160-179)*/

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
        //Valored das cores
        inRange(imgHSV, Scalar(160, 179, 60), Scalar(179, 255, 255), imgThresholded); //Threshold imagem


        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );


        Moments oMoments = moments(imgThresholded);

        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;


        if (dArea > 10000){
            //Calcula a posição da cor
            int posX = dM10 / dArea;
            int posY = dM01 / dArea;

            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0){
                //Desenha uma linha vermelha por onde o objeto passar
                line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
                setA(a++);
            } /*else {
                cout << "Cor não detectada" << endl;

                setA(0);
            }*/

            iLastX = posX;
            iLastY = posY;

            break;
        }

        imshow("Thresholded Image", imgThresholded); //mostra a imagem thresholded

        imgOriginal = imgOriginal + imgLines;
        imshow("Original", imgOriginal);

        if (waitKey(30) == 27){ //Se o esc for pressionado quebra o loop r vai para outra cor
            cout << "Tecla Esc foi pressionada pelo usuario" << endl;
            break;
        }
    } // Fim do while

}
