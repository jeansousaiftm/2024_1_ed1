#include<stdio.h>

int main() {

    float v[10];

    /*for (int i = 0; i < 10; i++) {
        scanf("%f", &v[i]);
    }*/

    printf("%d\n", &v);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", &v[i]);
    }

    return 0;
}
