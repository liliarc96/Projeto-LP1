#ifndef GERENCIAMENTODEIMAGENS_H
#define GERENCIAMENTODEIMAGENS_H
#include <iostream>

class GerenciamentoDeImagens{
    private:
        std::string cor;
    public:
        void setCor(std::string c);
        std::string getCor();

        void ProcessamentoDeImagens();
};

#endif // GERENCIAMENTODEIMAGENS_H
