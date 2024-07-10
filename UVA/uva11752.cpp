
/*
Para este problema implementamos una variante de la criba de eratostenes para generar
las super potencias. Luego simplemente imprimimos cada uno de estos numeros guardados en la criba. 
*/


#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

set<unsigned long long> st;

bool mark[80] = {};

void siv() {
    for (int i = 2; i * i <= 63; i++)
        if (!mark[i])
            for (int j = i; i * j <= 63; j++)
                mark[i * j] = true;

    unsigned long long high = 18446744073709551615;

    for (unsigned long long i = 2; i <= 100000; i++) {
        unsigned long long x = 1;
        for (int j = 1; j <= 64; j++) {
            x *= i;
            if (mark[j])
                st.insert(x);
            if (x > high / i)
                break;
        }
    }
}

int main() {
    siv();
    printf("1\n");
    for (auto it = st.begin(); it != st.end(); ++it) {
        printf("%llu\n", *it);
    }
    return 0;
}
