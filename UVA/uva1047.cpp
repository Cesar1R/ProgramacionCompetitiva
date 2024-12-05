/*
Para este problema utilizamos un algoritmo de fuerza bruta donde probamos
todas las combinaciones de torres, de estas, guardamos aquella que maximce los
usuarios beneficiados.

Para recorrer las combinaciones de torres buscamos incluir primero aquellas que
beneficien al mayor numero de clientes. Utilizamos manipulacion de bits para representar
las combinaciones de torres. 

Por los limites del problema, la solucion, para en tiempo y memoria.
*/

#include <bits/stdc++.h>
using namespace std;

#define MINF -1e9
#define bipct(x) __builtin_popcount(x)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int in = 1, o, t, n, m, d, tmp, a;
    while (cin >> n >> t && (n || t)) {
        int val[n],  mx = MINF, ans = 0;
				map<int, int> mp;

        for (int i = 0; i < n; ++i)  cin >> val[i];

        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> d; a = 0;
            for (int j = 0; j < d; ++j) {
                cin >> tmp; tmp--;
                a |= (1 << tmp);
            }
            cin >> o;
            mp[a] = o;
        }

        for (int i = 0; i < (1 << n); ++i) {
            if (bipct(i) == t) {
                int sum = 0;
                for (int j = 0; j < n; ++j) {
                    if (i & (1 << j)) {
                        sum += val[j];
                    }
                }
                for (auto x : mp) {
                    tmp = bipct(i & x.first);
                    if (tmp >= 2) sum -= x.second * (tmp - 1);
                }
                if (mx < sum) {
                    mx = sum; ans = i;
                }
            }
        }
        cout << "Case Number  " << in++ << endl;
        cout << "Number of Customers: " << mx << endl;
        cout << "Locations recommended:";
        for (int i = 0; i < n; ++i) {
            if (ans & (1 << i)) {
                cout << " " << i + 1;
            }
        }
        cout << endl << endl;
    }
}
