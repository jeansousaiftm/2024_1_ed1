#include<stdio.h>

void dobra(int *p1, int *p2) {
    *p1 *= 2;
    *p2 *= 2;
}

int main() {
    int a = 10, b = 5;
    dobra(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
