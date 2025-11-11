#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main() {

    system("cls");

    Item * I1 = criarItem(30);
    Item * I2 = criarItem(30);
    Item * I3 = criarItem(30);
    Item * I4 = criarItem(30);
    Item * I5 = criarItem(30);
    Item * I6 = criarItem(30);
    Item * I7 = criarItem(30);

    Pilha * MinhaPilha = criarPilha();

    printf("%X", MinhaPilha);

    empilhar(MinhaPilha, 11);
    empilhar(MinhaPilha, 12);
    empilhar(MinhaPilha, 13);
    empilhar(MinhaPilha, 14);
    empilhar(MinhaPilha, 15);
    empilhar(MinhaPilha, 16);
    empilhar(MinhaPilha, 17);

    printf("%d \n", MinhaPilha->Topo)
    
}