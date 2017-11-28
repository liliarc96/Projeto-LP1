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
            cout << "Primeira cor: Amarelo" << endl;

            cout << endl;
            Imagem::reconhecerAmarelo(getA());
            if(a > 0){
                p += 10;
                cout << "Pontos - " << p << endl;
                 //putText(frame, "Pontos - 10", Point(50, frame.rows * 0.5 + 30),FONT_HERSHEY_DUPLEX,4,Scalar(255,255,255),10);
            }
        }

        if(i == 1){
            cout << "Segunda cor: Azul" << endl;

            cout << endl;

            Imagem::reconhecerAzul(getA());
            if(a > 0){
                p += 10;
                cout << "Pontos - " << p << endl;
            }
        }

        if(i == 2){
            cout << "Terceira cor: Branco" << endl;

            cout << endl;

            Imagem::reconhecerBranco(getA());
            if(a > 0){
                p += 10;
                cout << "Pontos - " << p << endl;
            }
        }

        if(i == 3){
            cout << " Quarta cor: Preto" << endl;

            cout << endl;


            Imagem::reconhecerPreto(getA());
            if(a > 0){
                p += 10;
                cout << "Pontos - " << p << endl;
            }
        }

        if(i == 4){
            cout << "Quinta cor: Verde" << endl;

            cout << endl;

            Imagem::reconhecerVerde(getA());
            if(a > 0){
                p += 10;
                cout << "Pontos - " << p << endl;
            }
        }

        if(i == 5){
            cout << "Sexta cor: Vermelho" << endl;

            cout << endl;
            Imagem::reconhecerVermelho(getA());
            if(a > 0){
                p += 10;
                cout << "Pontos - " << p << endl;
            }
        }
    }

    setPontuacao(p);
    cout << "Total de pontos = " << getPontuacao() << endl;
}
