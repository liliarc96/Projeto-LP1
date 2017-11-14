#ifndef JOGO_H
#define JOGO_H
#include "GerenciamentoDeImagens.h"
#include <iostream>

class Jogo{
    private:
        int pontuacao;
        std::string cor;
    public:
        void setPontuacao(int p);
        int getPontuacao();

        void setCor(std::string c);
        std::string getCor();

        void iniciarJogo();

        int encerrarJogo();

        void processamentoDeImagens();
};

#endif // RECORD_H
