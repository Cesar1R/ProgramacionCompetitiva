#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define vi vector<int>

int dp[52][52]; // Costo mínimo de cortar desde i hasta j

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int l, n;

    while (cin >> l && l != 0) {
        cin >> n;
        vi cut_p(n + 2);
        cut_p[0] = 0;
        cut_p[n + 1] = l;
        for (int i = 1; i <= n; ++i) {
            cin >> cut_p[i];
        }

        // Inicializar dp con valores grandes
        for (int i = 0; i < 52; ++i) {
            fill(dp[i], dp[i] + 52, INT_MAX);
        }

        // Casos base: no se necesita cortar si hay sólo dos puntos
        for (int i = 0; i < n + 2; ++i) {
            dp[i][i + 1] = 0;
        }

        // Llenar la matriz dp
        for (int length = 2; length <= n + 1; ++length) {
            for (int i = 0; i <= n + 1 - length; ++i) {
                int j = i + length;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cut_p[j] - cut_p[i]);
                }
            }
        }

        cout << "The minimum cutting is " << dp[0][n + 1] << "." << endl;
    }

    return 0;
}
