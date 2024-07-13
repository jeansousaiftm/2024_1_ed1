#include<stdio.h>

struct No {

    int valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(int _valor) {
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

    void inserirInicio(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void inserirFinal(int valor) {
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

    void removerInicio() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    void removerFinal() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }

    void imprimir() {
        No* aux = inicio;
        int i = 0;
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            printf("X[%d] = %d\n", i++, aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
    }

    void menorLista() {
        if (inicio == NULL) return;
        int i = 0;
        int menor = inicio->valor, posicao = 0;
        No *aux = inicio;
        while (aux != NULL) {
            if (aux->valor < menor) {
                menor = aux->valor;
                posicao = i;
            }
            aux = aux->prox;
            i++;
        }
        printf("Menor valor: %d\n", menor);
        printf("Posicao: %d\n", posicao);
    }

};

int main() {

    Lista l;

    int x, n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.inserirFinal(x);
    }

    l.menorLista();

    return 0;
}
