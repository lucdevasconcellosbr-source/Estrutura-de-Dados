#include <stdio.h>


//definindo a estrutura de um item da lista encadeada

typedef struct Item{
    
    int chave; 
    struct Item * Proximo;

} Item;

//bloco principal

int main(){

    Item * I = (Item *) malloc (sizeof(Item));
  

    I -> chave = 17;


    I ->chave = NULL;
 

    // alguns testes (pritnf's)

    printf("%x \t %d\n", I, I->chave);

    }