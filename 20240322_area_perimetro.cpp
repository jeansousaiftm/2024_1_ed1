#include<stdio.h>

void calcula(double l1, double l2, double *cc, double *dd) {
    printf("%d %d\n", cc, dd);
    *a = l1 * l2;
    *p = (l1 + l2) * 2;
}

int main() {
    double l1, l2, a, p;

    scanf("%lf %lf", &l1, &l2);

    calcula(l1, l2, &a, &p);
    printf("%d %d\n", &a, &p);
    printf("%lf %lf\n", a, p);

    return 0;
}
