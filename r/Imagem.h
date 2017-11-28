#ifndef IMAGEM_H
#define IMAGEM_H
#include "Cor.h"

class Imagem: public Cor{
    private:
        int a;
    public:
        void setA(int a);
        int getA();

        void reconhecerAmarelo(int a);
        int reconhecerAzul();
        int reconhecerBranco();
        int reconhecerPreto();
        int reconhecerVerde();
        int reconhecerVermelho();
};

#endif // IMAGEM_H
