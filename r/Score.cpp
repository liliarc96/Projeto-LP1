#include "Score.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void Score::mostrarScore(int p){

    ofstream scores;
    scores.open("Ranking.txt");

    if(!scores.is_open()){
        cout << "Falha sao abrir arquivo de texto" << endl;
        exit(1);
    }

    scores << getPontuacao() << endl;

    scores.close();
}


