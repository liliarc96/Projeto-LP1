#include "Cor.h"
#include <iostream>

using namespace std;

Cor::Cor(int i){
  int argc;
  char* argv;

  switch (i) {
    case 0:
      String imageName( "/home/rebeca/amarelo.jpg"); //acessar imagem
      if(argc > 1)
      {
          imageName = argv[1];
      }
      Mat image;
      image = imread( imageName, IMREAD_COLOR ); // ler o arquivo
      if(image.empty()){ //verficar se o arquivo existe
          cout <<  "Falha ao abrir imagem" << std::endl ;
          return -1;
      }
      namedWindow( "Display window", WINDOW_AUTOSIZE ); //abrir janela para exibir
      imshow( "Display window", image );
      waitKey(0);

      break;
    case 1:
      String imageName( "/home/rebeca/azul.png");
      if(argc > 1){
          imageName = argv[1];
      }
      Mat image;
      image = imread( imageName, IMREAD_COLOR );

      if(image.empty()){
          cout <<  "Falha ao abrir imagem" << std::endl ;
          return -1;
      }

      namedWindow( "Display window", WINDOW_AUTOSIZE );
      imshow( "Display window", image );
      waitKey(0);

      break;
    case 2:
      String imageName( "/home/rebeca/branco.png");
      if(argc > 1){
          imageName = argv[1];
      }
      Mat image;
      image = imread( imageName, IMREAD_COLOR );

      if(image.empty()){
          cout <<  "Falha ao abrir imagem" << std::endl ;
          return -1;
      }

      namedWindow( "Display window", WINDOW_AUTOSIZE );
      imshow( "Display window", image );
      waitKey(0);

      break;
    case 3:
      String imageName( "/home/rebeca/preto.png");
      if(argc > 1){
          imageName = argv[1];
      }
      Mat image;
      image = imread( imageName, IMREAD_COLOR );

      if(image.empty()){
          cout <<  "Falha ao abrir imagem" << std::endl ;
          return -1;
      }

      namedWindow( "Display window", WINDOW_AUTOSIZE );
      imshow( "Display window", image );
      waitKey(0);

      break;
    case 4:
      String imageName( "/home/rebeca/verde.png");
      if(argc > 1){
          imageName = argv[1];
      }
      Mat image;
      image = imread( imageName, IMREAD_COLOR );

      if(image.empty()){
          cout <<  "Falha ao abrir imagem" << std::endl ;
          return -1;
      }

      namedWindow( "Display window", WINDOW_AUTOSIZE );
      imshow( "Display window", image );
      waitKey(0);

      break;
    case 5:
      String imageName( "/home/rebeca/vemelho.png");
      if(argc > 1){
          imageName = argv[1];
      }
      Mat image;
      image = imread( imageName, IMREAD_COLOR );

      if(image.empty())
      {
          cout <<  "Falha ao abrir imagem" << std::endl ;
          return -1;
      }

      namedWindow( "Display window", WINDOW_AUTOSIZE );
      imshow( "Display window", image );
      waitKey(0);

      break;
    default:
      cout << "Cor invalida" << endl;
      break
  }
}
