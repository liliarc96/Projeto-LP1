#include "User.h"
#include <iostream>

using namespace std;

void User::setNome(string n){
  nome = n;
  // salvar junto com a pontuação no arquivo de record
}

string User::getNome(){
  return nome;
}
