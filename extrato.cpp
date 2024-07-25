#include<stdio.h>

struct No {

    double valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(double _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No* inicio;
    No* fim;
    int n, valido;
    double saldo;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
        saldo = 0;
        valido = 1;
    }

    void inserirFinal(double valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        saldo += valor;
        if (saldo < 0) valido = 0;
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
        if (valido == 1) {
            printf("%.2lf\n", saldo);
        } else {
            printf("invalido\n");
        }
    }

};

int main() {

    Lista l;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        double x;
        scanf("%lf", &x);
        l.inserirFinal(x);
    }

    l.imprimir();


    return 0;
}
