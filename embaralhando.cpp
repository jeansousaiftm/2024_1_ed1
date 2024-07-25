#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct No {

    char valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(char _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No* inicio;
    No* fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirFinal(char valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void imprimir() {
        No* aux = inicio;
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            printf("%c ", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
    }

};

int main() {

    Lista maiusculo, minusculo;

    char tmp[101];
    scanf("%s", tmp);

    for (int i = 0; i < strlen(tmp); i++) {
        if (isupper(tmp[i])) {
            maiusculo.inserirFinal(tmp[i]);
        } else {
            minusculo.inserirFinal(tmp[i]);
        }
    }

    maiusculo.imprimir();
    minusculo.imprimir();


    return 0;
}
