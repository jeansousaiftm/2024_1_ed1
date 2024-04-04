#include<stdio.h>
#include<string.h>

void funcao(double n, int *i, int *d) {
    char tmp[100];
    sprintf(tmp, "%lf", n);
    sscanf(tmp, "%d.%d", i, d);
}

void funcao2(double n, int *i, double *d) {
    *i = (int) n;
    *d = n - *i;
}

void funcao3(double n, long long *i, long long *d) {
    char tmp[1000];
    sprintf(tmp, "%.20lf", n);
    //printf("%s\n", tmp);
    int x, y;
    for (x = strlen(tmp) - 1; x >= 0; x--) {
        if (tmp[x] != '0') break;
    }
    //printf("%d\n", x);
    *i = 0;
    for (y = 0; tmp[y] != '.'; y++) {
        *i = (*i * 10) + (tmp[y] - '0');
    }
    *d = 0;
    for (y = y + 1; y <= x; y++) {
        *d = (*d * 10) + (tmp[y] - '0');
    }
}

int main() {

    double n;
    long long i, d;

    scanf("%lf", &n);

    funcao3(n, &i, &d);

    printf("%lld %lld\n", i, d);

    /*double n2, d2;
    int i2;

    scanf("%lf", &n2);

    funcao2(n2, &i2, &d2);

    printf("%d %lf\n", i2, d2);*/

    //scanf("%d.%d", &i, &d)

    return 0;
}
