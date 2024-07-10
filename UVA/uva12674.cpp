/*
En este codigo primero identificamos los picos, esto lo hacemos comparando con
la altura anterior y siguiente, en los casos extremos, solo lo hacemos con el anterior o
siguiente respectivamente.

Hacemo uso de una sparce Table para eficientar la bisqueda
de picos en los rangos, estimamos la prominencia y utilizamos el criterio
para determinar si es ultra o no. 
*/


#include <bits/stdc++.h>
using namespace std;

const int lim = 150000;
vector<vector<int>> SpT;


void buildSparseTable(vector<int>& A) {
    int n = A.size();
    int k = log2(n) + 1;
    SpT.assign(n, vector<int>(k));

    for (int i = 0; i < n; i++)
        SpT[i][0] = i;

    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
            if (A[SpT[i][j - 1]] < A[SpT[i + (1 << (j - 1))][j - 1]])
                SpT[i][j] = SpT[i][j - 1];
            else
                SpT[i][j] = SpT[i + (1 << (j - 1))][j - 1];
}

int query(int i, int j, vector<int>& A) {
    int k = log2(j - i + 1);
    if (A[SpT[i][k]] <= A[SpT[j - (1 << k) + 1][k]])
        return SpT[i][k];
    else
        return SpT[j - (1 << k) + 1][k];
}

int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N) {
        vector<int> height(N);
        for (int i = 0; i < N; ++i)
            cin >> height[i];

        vector<int> hi_left(N), hi_right(N);
        hi_left[0] = -1;
        for (int i = 1; i < N; ++i) {
            hi_left[i] = i - 1;
            while (hi_left[i] != -1 && height[hi_left[i]] <= height[i])
                hi_left[i] = hi_left[hi_left[i]];
        }

        hi_right[N - 1] = N;
        for (int i = N - 2; i >= 0; --i) {
            hi_right[i] = i + 1;
            while (hi_right[i] != N && height[hi_right[i]] <= height[i])
                hi_right[i] = hi_right[hi_right[i]];
        }

        buildSparseTable(height);

        int c = 0;
        for (int i = 1; i < N - 1; ++i) {
            int h = 0;
            if (hi_left[i] != -1)
                h = height[query(hi_left[i], i - 1, height)];
            if (hi_right[i] != N)
                h = max(h, height[query(i + 1, hi_right[i], height)]);

            if (height[i] - h >= lim) {
                cout << (c != 0 ? " " : "") << i + 1;
                ++c;
            }
        }
        cout << "\n";
    }

    return 0;
}
