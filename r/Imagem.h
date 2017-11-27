#ifndef IMAGEM_H
#define IMAGEM_H
#include "Cor.h"

class Imagem: public Cor{
    public:
        int reconhecerAmarelo();
        int reconhecerAzul();
        int reconhecerBranco();
        int reconhecerPreto();
        int reconhecerVerde();
        int reconhecerVermelho();
};

#endif // IMAGEM_H
