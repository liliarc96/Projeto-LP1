#include "Cor.h"
#include "GeraCor.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include <time.h> //necessário p/ função time()
#include <iostream>

using namespace std;

int GeraCor::SortearCor(){
  int i;
  int d;

  srand(time(NULL));

  d = (rand() % 5);
  Cor *c = new cor();

  getch();

}
