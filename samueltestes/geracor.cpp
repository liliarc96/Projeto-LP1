#include "geracor.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include <time.h>//necessário p/ função time()
#include "cor.h"
#include <iostream>

using namespace std;
 
geracor::geracor()
{
    //ctor
}
geracor:: cor()
{
     int i,d;
 
     srand(time(NULL));
 
           // gerando valores aleatórios na faixa de 0 a 5
           d = (rand() % 5);
           Cor *c = new cor(); 
 
     getch();
     return 0;
}

geracor::~geracor()
{
    //dtor
}
