#include<stdio.h>
#include<math.h>
#define PI 3.14159

void funcao(double r, double *a, double *v) {
    *a = 4 * PI * pow(r, 2);
    *v = (4.0 / 3.0) * PI * pow(r, 3);
}

int main() {

    double r, a, v;
    scanf("%lf", &r);

    funcao(r, &a, &v);

    printf("%.4lf %.4lf\n", a, v);

    return 0;
}
