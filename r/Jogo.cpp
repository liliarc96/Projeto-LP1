#include "Jogo.h"
#include <iostream>

using namespace std;

void Jogo::setPontuacao(int p){
    pontuacao = p;
}

int Jogo::getPontuacao(){
    return pontuacao;
}

void Jogo::iniciarJogo(){
    int p = 0; //pontos totais
    int i;
    /* for (i = 0; i < 10 ; i ++){
      if( i == 0 ){
        mostramarelo
        reconheceramarelo} */

    for(i = 0; i <= 5; i++){
        if(i == 0){
            Imagem::reconhecerAmarelo();
            if(Imagem::reconhecerAmarelo() > 0){
                p += 10;
            }
        }

        if(i == 1){
            Imagem::reconhecerAzul();
            if(Imagem::reconhecerAzul() > 0){
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
            if(Imagem::reconhecerPreto() > 0){
                p += 10;
            }
        }

        if(i == 4){
            Imagem::reconhecerVerde();
            if(Imagem::reconhecerVerde() > 0){
                p += 10;
            }
        }

        if(i == 5){
            Imagem::reconhecerVermelho();
            if(Imagem::reconhecerVermelho() > 0){
                p += 10;
            }
        }
    }

    cout << "Total de pontos = " << p << endl;
}
