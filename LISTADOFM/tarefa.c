#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tarefa.h"

Lista * CriarLista(int C) {

    Lista * L = (Lista *) malloc(sizeof(Lista));

    if (L == NULL) {
        printf("ERRO: não existe memoria para a estrutura da lista\n")
        return NULL;
    }

    L -> Tamanho = 0
    L -> Capacidade = C;
    L -> dados = malloc(C * sizeof(Tarefa));

    if (L ->Dados == NULL) {
        printf("ERRO: nao existe memoria para o vetor de tarefas");
        free(L);
        return NULL;
    }

    return L;
}

void DestruirLista(Lista * L) {
    free(L == NULL) return;
    free(L)
}

void AdicionarTarefa(Lista * L, Tarefa T) {
    if(L ->tamanho == L ->capacidade) {
        printf("ERRO: Lista cheia\n");
        return;
    }

    L ->Dados(L ->tamanho) = T
    L ->tamanho++;
}

void GerarHTMLTabela(Lista *Lista, char *CaminhoArquivo) {
    if (Lista == NULL || CaminhoArquivo == NULL) return;

    FILE *Arq = fopen(CaminhoArquivo, "w");
    if (Arq == NULL) return;

    /* Cabeçalho HTML + CSS embutido */
    fputs(
"<!DOCTYPE html>\n"
"<html lang=\"pt-br\">\n"
"<head>\n"
"  <meta charset=\"utf-8\">\n"
"  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
"  <title>Lista de Tarefas</title>\n"
"  <style>\n"
"    :root { --borda:#e0e0e0; --cinza:#f8f9fa; --texto:#222; --verde:#d1e7dd; --laranja:#ffe8cc; --azul:#e7f1ff; }\n"
"    body{font-family:system-ui,-apple-system,Segoe UI,Roboto,Ubuntu,'Helvetica Neue',Arial,sans-serif;margin:24px;color:var(--texto);}\n"
"    h1{font-size:22px;margin:0 0 16px;}\n"
"    table{width:100%;border-collapse:collapse;background:#fff;border:1px solid var(--borda);table-layout:fixed;}\n"
"    thead th{background:var(--cinza);text-align:left;font-weight:600;padding:10px;border-bottom:1px solid var(--borda);} \n"
"    td{padding:10px;border-top:1px solid var(--borda);vertical-align:middle;word-wrap:break-word;}\n"
"    .col-titulo{width:45%;}\n"
"    .col-responsavel{width:18%;}\n"
"    .col-status{width:15%;}\n"
"    .col-progresso{width:15%;}\n"
"    .col-avaliacao{width:7%;}\n"
"    .status{display:inline-block;padding:4px 8px;border-radius:8px;font-size:12px;font-weight:600;}\n"
"    .status-afazer{background:var(--azul);}\n"
"    .status-emandamento{background:var(--laranja);}\n"
"    .status-feito{background:var(--verde);}\n"
"    .progresso{width:100%;height:10px;background:#eee;border-radius:6px;overflow:hidden;border:1px solid #ddd;}\n"
"    .progresso-barra{height:100%;background:#2f80ed;}\n"
"    .estrela{font-size:14px;color:#ffb703;}\n"
"    @media (max-width:720px){ .col-titulo{width:100%;} }\n"
"  </style>\n"
"</head>\n"
"<body>\n"
"  <h1>Lista de Tarefas</h1>\n"
"  <table>\n"
"    <thead>\n"
"      <tr>\n"
"        <th style=\"width:5%;\">#</th>\n"
"        <th class=\"col-titulo\">Título</th>\n"
"        <th class=\"col-responsavel\">Responsável</th>\n"
"        <th class=\"col-status\">Status</th>\n"
"        <th class=\"col-progresso\">Progresso</th>\n"
"        <th class=\"col-avaliacao\">Avaliação</th>\n"
"      </tr>\n"
"    </thead>\n"
"    <tbody>\n", Arq);

    /* Percorrer a lista de tarefas e gerar as linhas */
    int i;
    for (i = 0; i < Lista->Tamanho; i++) {
        Tarefa T = Lista->Dados[i];
        int Percentual = (int)(T.Progresso * 100.0f);
        if (Percentual < 0) Percentual = 0;
        if (Percentual > 100) Percentual = 100;

        fprintf(Arq, "      <tr>\n");
        fprintf(Arq, "        <td>%02d</td>\n", i);

        /* Coluna Título */
        fprintf(Arq, "        <td class=\"col-titulo\">%s</td>\n", T.Titulo);

        /* Coluna Responsável */
        fprintf(Arq, "        <td class=\"col-responsavel\">%s</td>\n", T.Responsavel);

        /* Coluna Status */
        const char *Classe =
            (T.Status == A_FAZER) ? "status-afazer" :
            (T.Status == EM_ANDAMENTO) ? "status-emandamento" :
            (T.Status == FEITO) ? "status-feito" : "status-desconhecido";

        const char *Texto =
            (T.Status == A_FAZER) ? "A Fazer" :
            (T.Status == EM_ANDAMENTO) ? "Em Andamento" :
            (T.Status == FEITO) ? "Feito" : "?";

        fprintf(Arq, "        <td class=\"col-status\"><span class=\"status %s\">%s</span></td>\n",
                Classe, Texto);

        /* Coluna Progresso */
        fprintf(Arq,
                "        <td class=\"col-progresso\">\n"
                "          <div class=\"progresso\"><div class=\"progresso-barra\" style=\"width:%d%%\"></div></div>\n"
                "        </td>\n", Percentual);

        /* Coluna Avaliação (estrelas) */
        fprintf(Arq, "        <td class=\"col-avaliacao estrela\">");
        int j;
        if (T.Avaliacao < 0) T.Avaliacao = 0;
        if (T.Avaliacao > 5) T.Avaliacao = 5;
        for (j = 0; j < T.Avaliacao; j++) fputs("&#9733;", Arq); /* ★ */
        for (; j < 5; j++) fputs("&#9734;", Arq);               /* ☆ */
        fputs("</td>\n", Arq);

        fputs("      </tr>\n", Arq);
    }

    /* Rodapé */
    fputs(
"    </tbody>\n"
"  </table>\n"
"</body>\n"
"</html>\n", Arq);

    fclose(Arq);

}
