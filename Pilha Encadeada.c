#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *ant;
} No;

typedef struct {
    No *fim;
    int tam;
} Lista;

void criarLista(Lista *lista){
    lista->tam = 0;
    lista->fim = NULL;
}

int vazia(Lista *lista){
    if(lista->tam == 0) return 1;
    else return -1;
}

int tamanho(Lista *lista){
    return lista->tam;
}

int obtTop(Lista *lista){
    return lista->fim->dado;
}

void inserir(Lista *lista,int dado){
    No *novo = (No*)malloc(sizeof(No));
    novo->ant = lista->fim;
    novo->dado = dado;
    lista->fim = novo;

    lista->tam++;
}

int remover(Lista *lista){
    if(vazia(lista) == 1) return -1;

    No *aux = lista->fim;

    int dado = aux->dado;
    lista->fim = aux->ant;
    free(aux);

    lista->tam--;
    return dado;
}

int main(){
    Lista lista;
    criarLista(&lista);
    inserir(&lista,1);
    inserir(&lista,2);
    inserir(&lista,3);
    inserir(&lista,4);
    inserir(&lista,5);
    printf("%d\n",obtTop(&lista));
    printf("%d\n",remover(&lista));
    printf("%d\n",remover(&lista));
    printf("%d\n",remover(&lista));
    printf("%d\n",remover(&lista));
    printf("%d\n",remover(&lista));
    return 0;
}
