#include "Cor.h"
#include "Imagem.h"
#include "Jogo.h"
#include "Score.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(){
    int op;
    Jogo jg;
    Score sc;

    cout << "       Bem-vindo ao Jogo das Cores" << endl;

    while(1){
        cout << "Menu:" << endl;
        cout << "       1 - Iniciar jogo" << endl;
        cout << "       2 - Ver ranking" << endl;
        cout << "       3 - Encerrar jogo" << endl;

        cout << "Escolha uma das opcoes para continuar" << endl;
        cin >> op;

        switch(op){
        case 1:
            jg.iniciarJogo(1);
            break;
        case 2:
            sc.mostrarScore(1);
            break;
        case 3:
            cout << "Obrigado por jogar!" << endl;
            cout << "FIM" << endl;
            return 1;
            break;
        default:
            cout << "Numero escolhido nao existe, tente novamente" << endl;
            break;
        }
    }

    return 0;
}
