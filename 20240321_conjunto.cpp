#include<stdio.h>
#define MAX 20

struct Conjunto{

    int n;
    int e[MAX];

    void ler() {
        scanf("%d", &n);
        if (n > MAX) {
            printf("Tamanho maximo atingido\n");
            return;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &e[i]);
            // TODO checar repetidos
        }
    }

    void imprimir() {
        printf("[ ");
        for (int i = 0; i < n; i++) {
            printf("%d ", e[i]);
        }
        printf("]\n");
    }

    void uniao(Conjunto c) {
        int possiveis = 0;
        for (int i = 0; i < c.n; i++) {
            int achou = 0;
            for (int j = 0; j < n; j++) {
                if (c.e[i] == e[j]) {
                    achou = 1;
                }
            }
            if (achou == 0) possiveis++;
        }
        if (n + possiveis > MAX) {
            printf("Conjunto cheio\n");
            return;
        }
        for (int i = 0; i < c.n; i++) {
            int achou = 0;
            for (int j = 0; j < n; j++) {
                if (c.e[i] == e[j]) {
                    achou = 1;
                }
            }
            if (achou == 0) {
                e[n] = c.e[i];
                n++;
            }
        }
    }

    void intersecao(Conjunto c) {
        int tmp[MAX], x = 0;
        for (int i = 0; i < c.n; i++) {
            int achou = 0;
            for (int j = 0; j < n; j++) {
                if (c.e[i] == e[j]) {
                    achou = 1;
                }
            }
            if (achou == 1) {
                tmp[x] = c.e[i];
                x++;
            }
        }
        n = x;
        for (int i = 0; i < n; i++) {
            e[i] = tmp[i];
        }
    }
};

int main() {

    Conjunto c1, c2;

    c1.ler();
    c1.imprimir();
    c2.ler();
    c2.imprimir();
    //c1.uniao(c2);
    c1.intersecao(c2);
    c1.imprimir();

    return 0;
}











