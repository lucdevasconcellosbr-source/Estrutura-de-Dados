#include <stdio.h>


//definindo a estrutura de um item da lista encadeada

typedef struct Item{
    
    int chave; 
    struct Item * Proximo;

} Item;

//bloco principal

int main(){

    Item * A = (Item *) malloc (sizeof(Item));
    Item * B = (Item *) malloc (sizeof(Item));
    Item * C = (Item *) malloc (sizeof(Item));
    Item * D = (Item *) malloc (sizeof(Item));

    A -> chave = 17;
    B -> chave = 29;
    C -> chave = 41;
    D -> chave = 97;

    A ->chave = NULL;
    B ->chave = NULL;
    C ->chave = NULL;
    D ->chave = NULL;

    // alguns testes (pritnf's)

    printf("%x \t %d\n", A, A->chave);
    printf("%x \t %d\n", B, B->chave);
    printf("%x \t %d\n", C, C->chave);
    printf("%x \t %d\n", D, D->chave);

    //construindo o encadeamneto (lista) A, C, B, D

    A -> Proximo = B;
    B -> Proximo = C;
    C -> Proximo = D;


    for (item * X = A; ; X != NULL; X = X->Proximo) {
        printf("%X \t %d\n", X, X->Chave);
        if (X == NULL) break;
    }
}