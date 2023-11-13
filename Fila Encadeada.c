#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dados;
    struct No *prox;
} No;

typedef struct{
    No *ini, *fim;
    int tam;
} Fila;

void criarFila(Fila *fila){
    fila->ini = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

int vazia(Fila *fila){
    if(fila->tam == 0) return 1;
    else return -1;
}

int tamanho(Fila *fila){
    return fila->tam;
}

int obtIni(Fila *fila){
    if(vazia(fila) == 1) return -1;
    else return fila->ini->dados;
}

void inserir(Fila *fila,int dado){
    No *novo = (No*)malloc(sizeof(No));

    novo->dados = dado;
    novo->prox = NULL;

    if(vazia(fila) == 1){
        fila->ini = novo;
        fila->fim = novo;
    }else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }

    fila->tam++;
}

int remover(Fila *fila){
    if(vazia(fila) == 1) return -1;

    No *aux = fila->ini;
    int dado = aux->dados;
    fila->ini = aux->prox;

    if(fila->tam == 1){
        fila->fim = NULL;
    }
    free(aux);
    fila->tam--;

    return dado;
}

int main(){
    Fila fila;
    criarFila(&fila);
    inserir(&fila, 10);
    inserir(&fila, 5);
    inserir(&fila, 2);
    inserir(&fila, 0);
    inserir(&fila, 1);
    printf("%d\n",obtIni(&fila));
    remover(&fila);
    printf("%d\n",obtIni(&fila));
    remover(&fila);
    printf("%d\n",obtIni(&fila));
    remover(&fila);
    printf("%d\n",obtIni(&fila));
    remover(&fila);
    printf("%d\n",obtIni(&fila));
    remover(&fila);
    printf("%d\n",obtIni(&fila));
    return 0;
}
