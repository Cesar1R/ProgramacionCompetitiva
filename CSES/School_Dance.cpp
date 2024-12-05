/*
https://cses.fi/problemset/result/10708359/
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;

struct Edge {
    ll capacity; // Capacidad
    ll flow;     // Flujo
    int to;      // Nodo destino
    int from; 
};

class FordFulkerson {
public:
    FordFulkerson(vector<vector<pair<int, ll>>> &graph) : g(graph) {}

    ll getMaxFlow(int s, int t) {
        init();
        ll f = 0;
        while (findAndUpdate(s, t, f)) {}
        return f;
    }

    void list_couples (int n, vector<pair<int, int>> & vec_r){
    
        for(const auto & edge: edges){
            if(edge.from <=n 
                && edge.flow > 0
                && edge.to > n){
                vec_r.pb({edge.from, edge.to}); 
            }
            else{ continue;} 
        }

        return ; 
    }


private:
    vector<vector<pair<int, ll>>> g; // Grafo
    vector<Edge> edges;
    vector<vector<int>> eIndexes;


    int findEdgeIndex(int from, int to) {
        for (int i = 0; i < g[from].size(); i++) {
            if (g[from][i].first == to) {
                return eIndexes[from][i]; // Devolver el índice de la arista en edges
            }
        }
        return -1; // Si no se encuentra la arista
    }

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

        while (!pending.empty() && !found) {
            int u = pending.front(); pending.pop();
            for (int i : eIndexes[u]) {
                if (edges[i].capacity > edges[i].flow && from[edges[i].to].first == -1) {
                    from[edges[i].to] = make_pair(u, i);
                    pending.push(edges[i].to);
                    if (edges[i].to == t) found = true;
                }
            }
        }

        if (!found) return false;
        
        ll uFlow = LLONG_MAX;
        int current = t;
        while (current != s) {
            uFlow = min(uFlow, edges[from[current].second].capacity - edges[from[current].second].flow);
            current = from[current].first;
        }

        current = t;
        while (current != s) {
            edges[from[current].second].flow += uFlow;
            edges[from[current].second ^ 1].flow -= uFlow;
            current = from[current].first;
        }
        
        flow += uFlow;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0); 

    int n, m, k; 
    cin >> n >> m >> k; 

    vector<vector<pair<int, ll>>> bipartite_graph(n + m + 2);  

    int from, to; 
    for (int i = 1; i <= k; i++) {
        cin >> from >> to; 
        bipartite_graph[from].pb({n + to, 1});  
    }

    for (int i = 1; i <= n; i++) {
        bipartite_graph[0].pb({i, 1}); 
    }

    for (int i = 1; i <= m; i++) {
        bipartite_graph[n + i].pb({n + m + 1, 1}); 
    }

    FordFulkerson ff(bipartite_graph); 
    ll max_flow = ff.getMaxFlow(0, n + m + 1); 
    cout << max_flow << endl; 

    vector<pair<int, int>> parejas; 
    
    ff.list_couples(n, parejas);  
    
    for (const auto &p : parejas) {
        cout << p.first << " " << p.second - n << endl; 
    }

    return 0; 
}
