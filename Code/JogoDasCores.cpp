#include "User.h"
#include "Jogo.h"
//#include "Menu.h"
#include "Record.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

int main(){
    User u;
    Jogo jg;
   // Menu m;
    Record r;

    int opcao;
    string n;

    cout << "       Bem-vindo ao Jogo das Cores " << endl;

    while(1){
        cout << "Menu:      1 - Iniciar jogo " << endl;
        cout << "           2 - Ver ranking  " << endl;
        cout << "           3 - Encerrar jogo" << endl;

        cout << "Escolha uma das opcoes: ";
        cin >> opcao;

        cout << endl;

        switch(opcao){
        case 1:
            jg.iniciarJogo();
            break;
        case 2:
            r.mostrarRecord();
            break;
        case 3:
            cout << "Obrigado por jogar";
            break;
        default:
            cout << "Escolha invalida, tente novamente." << endl;
            break;
        }
    }
    return 0;
}
