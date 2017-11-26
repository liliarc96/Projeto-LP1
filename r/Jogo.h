#ifndef JOGO_H
#define JOGO_H
#include "Imagem.h"
//#define MAX 100

class Jogo: public Imagem{
    private:
        //int pontuacao;
    public:
        void iniciarJogo();
        //int encerrarJogo();

        //void setPontuacao(int p);
        //int getPontuacao();

        void processamentoDeImagens();
};

#endif // JOGO_H
