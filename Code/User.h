#ifndef USER_H
#define USER_H
#include "Record.h"
#include <iostream>

class User: public Jogo{
  private:
    std::string nome;
  public:
    void setNome(std::string n);
    std::string getNome();
};


#endif // USER_H
