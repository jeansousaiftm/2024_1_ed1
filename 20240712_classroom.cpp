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
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            printf("%d/\n", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
    }

    void exercicio1(int x) {
        for (int i = 0; i < x && n > 0; i++) {
            l.removerFinal();
        }
    }

    void exercicio2() {
        if (n <= 1) return;
        if (n == 2) {
            removerFinal();
            return;
        }
        No* segundo = inicio->prox;
        inicio->prox = segundo->prox;
        delete(segundo);
        n--;
    }

    void exercicio3() {
        inserirFinal(n);
    }

    void exercicio4(int x) {
        for (int i = 1; i <= x; i++) {
            inserirFinal(i);
        }
    }

    void exercicio5(int v) {
        if (n <= 1) return;
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        No* novo = new No(v);
        aux->prox = novo;
        novo->prox = fim;
        n++;
    }

};

int main() {

    Lista l;




    return 0;
}
