/*
Para este problema utilizamos una tabla de dp de una sola dimension.

Primero ordenamos todos lo bloques de forma ascendente, luego llenamos la dp
con la recurrencia que se genera al llamar a la funcion tomar, tomar verifica
que podamos poner un bloque encima.

 dp[i] = altura maxima tomando el i-esimo bloque

 Devolvemos como respuesta la cantidad maxima que guardemos en la dp.

*/

#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

inline int tomar(int i, const vector<pii> &bloques, const vector<int> &dp){
    int res = 1;
    for(int j = i - 1; j >= 0; j--) {
        if(bloques[i].first >= bloques[j].first && bloques[i].second >= bloques[j].second) {
            res = max(res, 1 + dp[j]);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    while(cin >> n && n){
        vector<pii> bloques(n);

        for(int i = 0; i < n; i++){
            cin >> bloques[i].first >> bloques[i].second;
          }

        sort(bloques.begin(), bloques.end(), [](const pii & a, const pii &b){
            if(a.first == b.first){
                return a.second <= b.second;
              }
            else{
                return a.first < b.first;
              }
        });

        vector<int> dp(n, 1);  // dp[i] = La altura máxima de la torre hasta el par i

        int max_altura = 0;
        for(int i = 1; i < n; i++){
            dp[i] = max(dp[i], tomar(i, bloques, dp));
            max_altura = max(max_altura, dp[i]); 
          }

        cout << max_altura << endl;
    }

    cout << '*' << endl;

    return 0;
}
