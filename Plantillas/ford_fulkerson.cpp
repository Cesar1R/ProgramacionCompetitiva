#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;


 typedef struct Edge {
     ll c; // capacidad
     ll f; // flujo
     int to;
 } edge;


class FordFulkerson {
public:
    FordFulkerson(vector<vector<pair<int, ll>>> &graph): // from, to, capacity
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
        for (ll i = 0; i < (ll)g.size(); i++) {
            for (ll j = 0; j < (ll)g[i].size(); j++) {
                edges.push_back({ g[i][j].second, 0, g[i][j].first });
                edges.push_back({ 0,0, (int)i });
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


int main(){


    return 0; 
}