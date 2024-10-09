/*
https://cses.fi/problemset/task/1695
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;

typedef struct Edge {
    ll c; // capacidad
    ll f; // flujo
    int to;
    int from; 
} edge;

class FordFulkerson {
public:
    FordFulkerson(vector<vector<pair<int, ll>>> &graph) : g(graph) {}

    ll getMaxFlow(int s, int t) {
        init(); 
        ll f = 0;
        while (findAndUpdate(s, t, f)) {}
        return f;
    }


    vector<pair<int, int>> get_path (int s) {
        vector<pair<int, int>> aristas = getMinCut(s); 
        set<int> nodos_alcanzables; 

        for(const auto &arista: aristas){
            nodos_alcanzables.insert(arista.first); 
            nodos_alcanzables.insert(arista.second);
        }

        vector<pair<int, int>> res; 

        for(const auto &edge: edges){ 
            if( nodos_alcanzables.find(edge.from) != nodos_alcanzables.end() 
                && nodos_alcanzables.find(edge.to) == nodos_alcanzables.end()
                && edge.f > 0){
            
                res.emplace_back(edge.from, edge.to); 
            }
        }

        return res; 
    }


private:
    vector<vector<pair<int, ll>>> g;  // to, capacidad
    vector<edge> edges;
    vector<vector<int>> eIndexes;

    void init() {
        edges.clear();
        eIndexes.clear();
        eIndexes.resize(g.size());
        for (ll i = 0; i < g.size(); i++) {
            for (const auto& edge : g[i]) {
                edges.push_back({ edge.second, 0, edge.first, (int)i });
                edges.push_back({ 0, 0, (int)i, edge.first }); 
                eIndexes[i].push_back(edges.size() - 2);
                eIndexes[edge.first].push_back(edges.size() - 1);
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
            for (ll i = 0; i < (ll)eIndexes[u].size(); i++) {
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

        ll uFlow = LLONG_MAX; 
        int current = t;
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

    vector<pair<int, int>> getMinCut(int s) {
        vector<bool> visited(g.size(), false);
        dfs(s, visited);
        
        vector<pair<int, int>> cutEdges;
        for (int u = 0; u < g.size(); u++) {
            if (visited[u]) {
                for (const auto &p : g[u]) {
                    int v = p.first; // nodo destino
                    int eI = eIndexes[u][0]; // índice de la arista de u a v
                    // Cambia la manera de obtener el índice eI aquí:
                    for (int idx : eIndexes[u]) {
                        if (edges[idx].to == v && edges[idx].f < edges[idx].c) {
                            cutEdges.emplace_back(u, v); // Agrega el par (origen, destino)
                        }
                    }
                }
            }
        }
        return cutEdges;
    }

    void dfs(int u, vector<bool> &visited) {
        visited[u] = true;
        for (const auto &p : g[u]) {
            if (!visited[p.first]) {
                int eI = eIndexes[u][0]; 
                if (edges[eI].c > edges[eI].f) {
                    dfs(p.first, visited);
                }
            }
        }
    }
};


int main(){

    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 

    int n,
        m,  
        i, from, to;

    cin >> n >> m; 

    vector<vector<pair<int, ll>>> cross (n+1);   


    for(i = 1; i <= m; i++){
        cin >> from >> to ;
        cross[from].emplace_back(make_pair(to, 1)); 

    }  

    FordFulkerson g (cross); 

    cout << g.getMaxFlow(1, n) << endl;

    vector<pair<int, int>> cruces = g.get_path(1); 


    for(const auto & pareja: cruces){
        cout << pareja.first << " " << pareja.second << endl; 
    }  



    return 0; 
}