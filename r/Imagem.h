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
        void reconhecerAzul(int a);
        void reconhecerBranco(int a);
        void reconhecerPreto(int a);
        void reconhecerVerde(int a);
        void reconhecerVermelho(int a);
};

#endif // IMAGEM_H
