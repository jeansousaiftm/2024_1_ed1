#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<set>
#include<list>
using namespace std;

int main() {
    srand(time(NULL));
    set<int> s;
    list<int> l;
    freopen ("nomes.txt","r+",stdin);
    char tmp[1000][1000];
    int i = 0;
    while (scanf("%[^\n]%*c", tmp[i]) != EOF) {
        //printf("%s\n", tmp);
        i++;
    }
    int n = i;

    while (s.size() < n) {
        int x = (rand() % n);
        if (!s.count(x)) {
            s.insert(x);
            l.push_back(x);
        }
    }

    i = 0;
    for (list<int>::iterator it = l.begin(); it != l.end(); it++, i++) {
        if (i == 0) printf("QUINTA\n");
        if (i == 18) printf("SEXTA\n");
        printf("%s\n", tmp[*it]);
    }


    /*for (int i = 0; i < n; i++) {
        printf("%s\n", tmp[i]);
    }*;*/

    return 0;
}
