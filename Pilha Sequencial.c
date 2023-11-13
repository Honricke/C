#include <stdio.h>

#define max 10

typedef struct{
    int dados[max];
    int tamMax;
    int tamAtual;
} Lista;

void criarLista(Lista *lista){
    lista->tamMax = max;
    lista->tamAtual = 0;
}

int vazia(Lista *lista){
    if(lista->tamAtual == 0) return 1;
    else return -1;
}

int cheia(Lista *lista){
    if(lista->tamAtual == lista->tamMax) return 1;
    else return 0;
}

int tamanho(Lista *lista){
    return lista->tamAtual;
}

int obtTop(Lista *lista){
    if(vazia(lista)==1) return -1;
    int index = lista->tamAtual-1;
    return lista->dados[index];
}

int inserir(Lista *lista, int dado){
    if(cheia(lista) == 1) return -1;

    int index = lista->tamAtual;
    lista->dados[index] = dado;
    lista->tamAtual++;
    return 1;
}

int remover(Lista *lista){
    if(vazia(lista) == 1) return -1;

    int index = lista->tamAtual-1;
    int dado = lista->dados[index];
    lista->tamAtual--;
    return dado;
}

int main(){
    Lista lista;
    criarLista(&lista);
    inserir(&lista,5);
    inserir(&lista,4);
    inserir(&lista,3);
    inserir(&lista,2);
    inserir(&lista,1);
    printf("%d\n",obtTop(&lista));
    printf("%d\n",remover(&lista));
    printf("%d\n",remover(&lista));
    printf("%d\n",remover(&lista));
    printf("%d\n",remover(&lista));
    printf("%d\n",remover(&lista));
    printf("%d\n",obtTop(&lista));
    // printf("%d\n",vazia(&lista));
    return 0;
}