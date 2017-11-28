#include "Cor.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

//Fonte do código para mostrar imagem:https://docs.opencv.org/trunk/db/deb/tutorial_display_image.html

using namespace std;
using namespace cv;

int Cor::mostrarAmarelo(){
    /*int argc;
    char* argv;*/

    string imageName( "/home/rebeca/amarelo.png"); //acessar imagem
      /*if(argc > 1)
      {
          imageName = argv[1];
      }*/
      Mat image;
      image = imread( imageName, IMREAD_COLOR ); // ler o arquivo
      if(image.empty()){ //verficar se o arquivo existe
          cout <<  "Falha ao abrir imagem" << std::endl ;
          return -1;
      }
      namedWindow( "Display window", WINDOW_AUTOSIZE ); //abrir janela para exibir
      imshow( "Display window", image );
      waitKey(0);
}

int Cor::mostrarAzul(){
    /*int argc;
    char* argv;*/

    string imageName( "/home/rebeca/azul.jpg"); //acessar imagem
    /*if(argc > 1){
        imageName = argv[1];
    }*/
    Mat image;
    image = imread( imageName, IMREAD_COLOR ); // ler o arquivo
    if(image.empty()){ //verficar se o arquivo existe
        cout <<  "Falha ao abrir imagem" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); //abrir janela para exibir
    imshow( "Display window", image );
    waitKey(0);
}

int Cor::mostrarBranco(){
    /*int argc;
    char* argv;*/

    string imageName( "/home/rebeca/branco.jpg"); //acessar imagem
    /*if(argc > 1){
        imageName = argv[1];
    }*/
    Mat image;
    image = imread( imageName, IMREAD_COLOR ); // ler o arquivo
    if(image.empty()){ //verficar se o arquivo existe
        cout <<  "Falha ao abrir imagem" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); //abrir janela para exibir
    imshow( "Display window", image );
    waitKey(0);
}

int Cor::mostrarPreto(){
    /*int argc;
    char* argv;*/

    string imageName( "/home/rebeca/preto.jpg"); //acessar imagem
    /*if(argc > 1){
        imageName = argv[1];
    }*/
    Mat image;
    image = imread( imageName, IMREAD_COLOR ); // ler o arquivo
    if(image.empty()){ //verficar se o arquivo existe
        cout <<  "Falha ao abrir imagem" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); //abrir janela para exibir
    imshow( "Display window", image );
    waitKey(0);
}

int Cor::mostrarVerde(){
    /*int argc;
    char* argv;*/

    string imageName( "/home/rebeca/verde.jpg"); //acessar imagem
    /*if(argc > 1){
        imageName = argv[1];
    }*/
    Mat image;
    image = imread( imageName, IMREAD_COLOR ); // ler o arquivo
    if(image.empty()){ //verficar se o arquivo existe
        cout <<  "Falha ao abrir imagem" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); //abrir janela para exibir
    imshow( "Display window", image );
    waitKey(0);
}

int Cor::mostrarVermelho(){
    /*int argc;
    char* argv;*/

    string imageName( "/home/rebeca/vermelho.png"); //acessar imagem
    /*if(argc > 1){
        imageName = argv[1];
    }*/
    Mat image;
    image = imread( imageName, IMREAD_COLOR ); // ler o arquivo
    if(image.empty()){ //verficar se o arquivo existe
        cout <<  "Falha ao abrir imagem" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); //abrir janela para exibir
    imshow( "Display window", image );
    waitKey(0);
}
