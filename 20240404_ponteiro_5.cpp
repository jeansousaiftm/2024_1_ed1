#include<stdio.h>

void funcao(int v[], int n, int *minimo, int *maximo) {
    *minimo = v[0];
    *maximo = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > *maximo) {
            *maximo = v[i];
        }
        if (v[i] < *minimo) {
            *minimo = v[i];
        }
    }
}

int main() {

    int n;

    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int minimo, maximo;

    funcao(v, n, &minimo, &maximo);

    printf("%d %d\n", minimo, maximo);

    return 0;

}
