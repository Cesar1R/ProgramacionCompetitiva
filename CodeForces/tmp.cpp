#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;

        vector<vector<int>> tiempos(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> tiempos[i][j];
            }
        }

        vector<pair<int, int>> resultados(n); // pair <puntos, penalización>

        for (int i = 0; i < n; i++) {
            sort(tiempos[i].begin(), tiempos[i].end()); // Ordenar los tiempos
            int t_ac = 0, pts = 0;

            for (int j = 0; j < m; j++) {
                if (t_ac + tiempos[i][j] <= h) {
                    t_ac += tiempos[i][j];
                    pts++;
                } else {
                    break;
                }
            }

            resultados[i] = {pts, t_ac}; // Guardar puntos y penalización
        }

        // Obtener puntos y penalización de Rudolf (índice 0)
        int puntos_rudolf = resultados[0].first;
        int penalizacion_rudolf = resultados[0].second;

        int lugar = 1; // Rudolf inicia en el primer lugar

        // Comparar con otros participantes
        for (int i = 1; i < n; i++) {
            if (resultados[i].first > puntos_rudolf ||
                (resultados[i].first == puntos_rudolf && resultados[i].second < penalizacion_rudolf)) {
                lugar++;
            }
        }

        cout << lugar << "\n";
    }

    return 0;
}
