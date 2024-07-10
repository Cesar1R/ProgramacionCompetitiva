/*
Para este problema se utilizo el algoritmo de maximo flujo de FordFulkerson.

Tendremos nodos que representan personas, estos estaran conectados a los lugares
donde pueden moverse, los lugares grandes tendran conexion de capacidad 1. Al grafo
agregaremos aristas conforme las restricciones que representa el problema.

Conectaremos los nodos que representan lugares 'seguros' al sumidero, interpretando
la llegada del bote salvavidas, mientras que las personas estaran conectadas a la fuente,
asi al calcular el flujo maximo obtendremos la cantidad maxima de personas que
pueden ser salvadas. 
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

private:
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
                if ((edges[eI].c > edges[eI].f) && (from[edges[eI].to].first == -1)) {
                    from[edges[eI].to] = make_pair(u, eI);
                    pending.push(edges[eI].to);
                    if (edges[eI].to == t) found = true;
                }
            }
        }
        if (!found) return false;
        ll uFlow = LLONG_MAX; int current = t;
        while (current != s) {
            uFlow = min(uFlow, edges[from[current].second].c - edges[from[current].second].f);
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

bool fuera(int x, int y, int n, int m) {
    return !(x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
    int rows, cols, cost;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (cin >> rows >> cols >> cost) {
        string map[rows];
        for (int i = 0; i < rows; i++) cin >> map[i];
        int cell_id[rows][cols], cell_count = 2;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cell_id[i][j] = cell_count++;
            }
        }
        vector<vector<pair<int, ll>>> graph(2 * cell_count);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int tn = cell_id[i][j];
                if (map[i][j] == '*') {
                    graph[0].push_back({tn, 1});
                    graph[tn].push_back({tn + cell_count, 1});
                } else if (map[i][j] == '#') {
                    graph[tn].push_back({tn + cell_count, LLONG_MAX});
                    graph[tn + cell_count].push_back({1, cost});
                } else if (map[i][j] == '.') {
                    graph[tn].push_back({tn + cell_count, 1});
                } else if (map[i][j] == '@') {
                    graph[tn].push_back({tn + cell_count, LLONG_MAX});
                }
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (fuera(nx, ny, rows, cols)) continue;
                    int nn = cell_id[nx][ny];
                    if (map[i][j] == '*' || map[i][j] == '.') {
                        if (map[nx][ny] != '~' || map[nx][ny] != '*') {
                            graph[tn + cell_count].push_back({nn, 1});
                        }
                    } else if (map[i][j] == '@' || map[i][j] == '#') {
                        if (map[nx][ny] != '~' || map[nx][ny] != '*') {
                            graph[tn + cell_count].push_back({nn, LLONG_MAX});
                        }
                    }
                }
            }
        }
        FordFulkerson ff(graph);
        cout << ff.getMaxFlow(0, 1) << endl;
    }
    return 0;
}
