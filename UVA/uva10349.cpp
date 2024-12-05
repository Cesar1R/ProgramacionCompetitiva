/*
Para este problema utilizamos el algoritmo de FordFulkerson sobre un grafo bipartito.

Construimos el grafo bipartito conectando nodos que representan los puntos de interes
y nodos que represtan las posiciones de antenas. Definimos el flujo de cada posicion
de las antenas como 1, ya que puede cubrir su posicion y una coordenada mas, ademas
esto nos asegura que tendremos un emparejamiento maximo.

El flujo maximo que recibimos lo podemos interpretar como la cantidad maxima de
puntos que podemos cubrir con las antes, es por ello que el numero minimo de antenas
lo podemos obtener de la resta del flujo a la cantidad total de puntos de interes.
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
    ll c, f;
    int to;
};

class FordFulkerson {
public:
    FordFulkerson(vector<vector<pair<int, ll>>> &graph) :
        g(graph) {}

    ll getMaxFlow(int s, int t) {
        init(); ll f = 0;
        while (findAndUpdate(s, t, f)) {}
        return f;
    }

//private:
    vector<vector<pair<int, ll>>> g;  // to, capacidad
    vector<edge> edges;
    vector<vector<int>> eIndexes;

    void init() {
        edges.clear(); eIndexes.clear(); eIndexes.resize(g.size());
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                edges.push_back({ g[i][j].second, 0, g[i][j].first });
                edges.push_back({ 0,0,i });
                eIndexes[i].push_back(edges.size() - 2);
                eIndexes[g[i][j].first].push_back(edges.size() - 1);
            }
        }
    }


    bool findAndUpdate(int s, int t, ll &flow) {
        queue<int> pending;
        vector<pair<int, int>> from(g.size(), make_pair(-1, -1));
        pending.push(s);
        from[s] = make_pair(s, -1);
        bool found = false;
        while (pending.size() && (!found)) {
            int u = pending.front(); pending.pop();
            for (int i = 0; i < eIndexes[u].size(); i++) {
                int eI = eIndexes[u][i];
                if ((edges[eI].c > edges[eI].f) &&
                    (from[edges[eI].to].first == -1)) {
                    from[edges[eI].to] = make_pair(u, eI);
                    pending.push(edges[eI].to);
                    if (edges[eI].to == t) found = true;
                }
            }
        }
        if (!found) return false;
        ll uFlow = LLONG_MAX; int current = t;
        while (current != s) {
            uFlow = min(uFlow,
                edges[from[current].second].c - edges[from[current].second].f);
            current = from[current].first;
        }
        current = t;
        while (current != s) {
            edges[from[current].second].f += uFlow;
            edges[from[current].second ^ 1].f -= uFlow;
            current = from[current].first;
        }
        flow += uFlow;
        return true;
    }
};

int main() {
    int n;
    cin >> n;

    while (n--) {
        int h, w;
        cin >> h >> w;

        int total = 0;
        vector<vector<char>> input(h, vector<char>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> input[i][j];
                if (input[i][j] == '*')  total += 1;
            }
        }

        vector<vector<pair<int, ll>>> graph(h * w + 2);
        int source = 0;
        int sink = h * w + 1;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if ((i + j) % 2 && input[i][j] == '*') {
                    graph[source].push_back({i * w + j + 1, 1});
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            int ni = i + di;
                            int nj = j + dj;
                            if (di * di + dj * dj == 1 && ni >= 0 && ni < h && nj >= 0 && nj < w && input[ni][nj] == '*') {
                                graph[i * w + j + 1].push_back({ni * w + nj + 1, 1});
                            }
                        }
                    }
                } else if ((i + j) % 2 == 0 && input[i][j] == '*') {
                    graph[i * w + j + 1].push_back({sink, 1});
                }
            }
        }

        FordFulkerson ff(graph);
        ll maxFlow = ff.getMaxFlow(source, sink);
        cout << total - maxFlow << endl;
    }

    return 0;
}
