#include<stdio.h>
#define PI 3.14159

void funcao1() {

    int a, b;

    scanf("%d %d", &a, &b);

    if (&a > &b) {
        printf("%d\n", &a);
    } else {
        printf("%d\n", &b);
    }

}

void funcao2() {
    float a[10];

    for (int i = 0; i < 10; i++) {
        printf("%d\n", &a[i]);
    }
}

void funcao3(double n, int* i, int* d) {
    *i = (int) n;
    char tmp[1000];
    sprintf(tmp, "%.10lf", n);
    sscanf(tmp, "%*d.%d", d);
}

void funcao4(double r, double* a, double* v) {
    *a = 4 * PI * r * r;
    *v = (4.0/3.0) * PI * r * r * r;
}

void funcao5(int v[], int t, int* menor, int* maior) {
    if (t <= 0) {
        return;
    }
    *menor = v[0];
    *maior = v[0];
    for (int i = 1; i < t; i++) {
        if (v[i] > *maior) {
            *maior = v[i];
        }
        if (v[i] < *menor) {
            *menor = v[i];
        }
    }
}

int main() {

    //funcao1();
    //funcao2();

    /*int i, d;
    funcao3(100.1234, &i, &d);
    printf("%d %d\n", i, d);*/

    /*double a, v;
    funcao4(100, &a, &v);
    printf("%.2lf %.2lf\n", a, v);*/

    /*int maior, menor;
    int v[] = { 1,2,3,5,6,1,5,7,8,0,1 };
    funcao5(v, 11, &menor, &maior);
    printf("%d, %d\n", menor, maior);*/

    return 0;
}
