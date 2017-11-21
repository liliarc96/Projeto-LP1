#ifndef GERENCIAMENTODEIMAGENS_H
#define GERENCIAMENTODEIMAGENS_H
#include <iostream>
#include <string>

class GeremciamentoDeImagens{
    private:
        std::string cor;
    public:
        //void capturarImagem();
        void reconhecerImagem();

        void setCor(std::string c);
        std::string getCor();
};

#endif // GERENCIAMENTODEIMAGENS_H
