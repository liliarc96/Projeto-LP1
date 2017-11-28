#include "Jogo.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace cv;

void Jogo::setPontuacao(int p){
    pontuacao = p;
}

int Jogo::getPontuacao(){
    return pontuacao;
}

void Jogo::iniciarJogo(int a){
    int p = 0; //pontos totais
    int i;
    /* for (i = 0; i < 10 ; i ++){
      if( i == 0 ){
        mostramarelo
        reconheceramarelo} */

    for(i = 0; i <= 5; i++){
        Mat frame;
        if(i == 0){
            Imagem::reconhecerAmarelo(getA());
            if(a > 0){
                p += 10;
                 putText(frame, "Pontos - 10", Point(50, frame.rows * 0.5 + 30),FONT_HERSHEY_DUPLEX,4,Scalar(255,255,255),10);
            }
        }

        if(i == 1){
            Imagem::reconhecerAzul();
            if(a > 0){
                p += 10;
            }
        }

        if(i == 2){
            Imagem::reconhecerBranco();
            if(Imagem::reconhecerBranco() > 0){
                p += 10;
            }
        }

        if(i == 3){
            Imagem::reconhecerPreto();
            if(a > 0){
                p += 10;
            }
        }

        if(i == 4){
            Imagem::reconhecerVerde();
            if(a > 0){
                p += 10;
            }
        }

        if(i == 5){
            Imagem::reconhecerVermelho();
            if(a > 0){
                p += 10;
            }
        }
    }

    setPontuacao(p);
    cout << "Total de pontos = " << getPontuacao() << endl;
}
