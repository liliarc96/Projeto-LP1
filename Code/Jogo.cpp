#include "Jogo.h"
#include <iostream>
// adicionar include de arquivo

using namespace std;

void Jogo::setPontuacao(int p){
    pontuacao = p;
}

int Jogo::getPontuacao(){
    return pontuacao;
}

/*void Jogo::setCor(){
    //adicionar random para escolher cor
}

string Jogo::getCor(){
    return cor;
}*/

void Jogo::iniciarJogo(){
    GeremciamentoDeImagens::reconhecerImagem();
}

int Jogo::encerrarJogo(){

}

/*void Jogo::processamentoDeImagens(){
    //receber imagem da classe opencv e reconhecer
} */

