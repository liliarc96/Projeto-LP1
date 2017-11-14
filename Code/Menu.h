
#ifndef MENU_H
#define MENU_H
#include "Jogo.h"
#include "User.h"

class Menu{
      private:
            int opcao;
      public: 
            void setOpcao(int o);
            int getOpcao();
            
            void MostraMenu();
            
};

#endif // MENU_H
            
