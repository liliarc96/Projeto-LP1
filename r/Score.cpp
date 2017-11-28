#include "Score.h"
#include <iostream>
#include <list>
#include <fstream>
#include <stdlib.h>

using namespace std;

void Score::mostrarScore(int p){
    list <int> ranking;

    ranking.push_back(p);

    ofstream scores;
    scores.open("Ranking.txt");

    if(!scores.is_open()){
        cout << "Falha sao abrir arquivo de texto" << endl;
        exit(1);
    }



    //iterator it;
    //ranking.insert(it) << it->getPontuacao() << endl;

    //ranking.close("Ranking.txt");
}


