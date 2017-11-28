#ifndef JOGO_H
#define JOGO_H
#include "Imagem.h"


class Jogo: public Imagem{
    private:
        int pontuacao;
    public:
        void iniciarJogo(int a);
        int encerrarJogo();

        void setPontuacao(int p);
        int getPontuacao();

        void processamentoDeImagens();
};

#endif // JOGO_H
