/*
En este problema utilizamos el algoritmo de FordFulkerson a un grafo bipartito.

Costruimos el grafo de la siguiente manera, creamos nodos por cada fila y columna,
hacemos esto ya que cada que colocamos una torre bloqueamos la fila y columna en que fue colocada
con aristas que conecten las celdas disponibles, la capidad de las mismas es 1, para
garantizar que no ocupemos una casilla dos veces.

Vamos a conectar los nodos que corresponden a las filas a la fuente y los que
corresponden a las columnas al sumidero.

Asi al calcular el fulo maximo obtendremos contando el numero maximo de rooks que
se pueden colocar en el tablero sin atacarse entre si.
*/
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef struct Edge {
    ll c; // capacidad
    ll f; // flujo
    int to;
} edge;

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
    int N;
    char s[128][128];
    while (cin >> N) {
        for (int i = 0; i < N; i++)
            cin >> s[i];
        int R[128][128], C[128][128];
        int rcnt = 0, ccnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (s[i][j] == '.' && (j == 0 || s[i][j-1] == 'X'))
                    rcnt++;
                if (s[i][j] == '.')
                    R[i][j] = rcnt;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (s[j][i] == '.' && (j == 0 || s[j-1][i] == 'X'))
                    ccnt++;
                if (s[j][i] == '.')
                    C[j][i] = ccnt;
            }
        }
        vector<vector<pair<int, ll>>> graph(rcnt + ccnt + 2);
        int source = 0, sink = rcnt + ccnt + 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (s[i][j] == '.')
                    graph[R[i][j]].push_back({C[i][j] + rcnt, 1});
            }
        }
        for (int i = 1; i <= rcnt; i++)
            graph[source].push_back({i, 1});
        for (int i = 1; i <= ccnt; i++)
            graph[i + rcnt].push_back({sink, 1});
        FordFulkerson ff(graph);
        int ret = ff.getMaxFlow(source, sink);
        cout << ret << endl;
    }
    return 0;
}
