#ifndef TAREFA_H
#define TAREFA_H

#define TAM_TITULO 96
#define TAM_NOME 48

#define A_FAZERD 0
#define EM_ANDAMENTO 1
#define FEITO 2

typedef struct
{
    char Titulo(TAM_TITULO);
    char Responsavel(TAM_NOME);
    int Status;
    float Progresso;
    int Avaliação;
} Tarefa;

typedef struct
{
    Tarefa * Dados;
    int capacidade;
    int tamanho;

} Lista;

Lista * CriarLista(int C);

void DestruirLista(Lista * L) {
    if (L == NULL) return;
    free(L ->Dados);
    free(L);
}

void GerarHTMLTabela(Lista *Lista, char *CaminhoArquivo)

#endif
