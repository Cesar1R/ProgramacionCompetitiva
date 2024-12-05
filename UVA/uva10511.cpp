/*
Para este problema utilizamos el algoritmo de FordFulkerson para obtener el flujo
maximo en un grafo bi partito.

Crearemos el grafo bipartito con los clubes y los partidos,  cada nodo sera uno de estos
cada arista entre cada parte representara una persona que pertenece tanto a ese partido
como club. Por cada persona, se agrega en 1 la capacidad de la arista.

La fuente conecta con los clubes, los clubes con los partidos y los partidos con el
sumidero, buscamos maximizar el flujo hacia el sumidero, pues esto representara que

*/

#include<bits/stdc++.h>
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    string emptyLine;
    getline(cin, emptyLine);

    while (T--) {
        vector<vector<pair<int, ll>>> graph;
        unordered_map<string, int> residentId;
        unordered_map<string, int> clubId;
        unordered_map<string, int> partySize;
        vector<string> residents;

        string line;
        while (getline(cin, line) && !line.empty()) {
            stringstream ss(line);
            string res, part;
            ss >> res >> part;

            residents.push_back(res);
            residentId[res] = residents.size() - 1;

            string club;
            while (ss >> club) {
                if (!clubId.count(club)) {
                    clubId[club] = graph.size();
                    graph.push_back({});
                }
                graph[residentId[res]].push_back({ clubId[club], 1 });
            }
            partySize[part]++;
        }

        int s = graph.size();
        int t = s + 1;

        for (int i = 0; i < residents.size(); i++) {
            graph.push_back({});
            graph[s].push_back({ i, 1 });
        }

        for (auto& k : clubId)
            graph[k.second].push_back({ t, partySize[k.first] });

        FordFulkerson ff(graph);

        ll maxFlow = ff.getMaxFlow(s, t);


        bool flag = true;
        for (int i = 0; i < residents.size(); i++) {
            for (auto& r : graph[i]) {
                if (r.first != s && r.second > 0) {
                    if (ff.edges[ff.eIndexes[i][r.first]].f != 1) {
                        flag = false;
                        break;
                    }
                }
            }
        }

        for (auto& k : clubId) {
            if (ff.edges[ff.eIndexes[k.second][t]].f > partySize[k.first] / 2) {
                flag = false;
                break;
            }
        }

        if (flag) {
            for (int i = 0; i < residents.size(); i++) {
                for (auto& r : graph[i]) {
                    if (r.first != s && r.second > 0) {
                        cout << residents[i] << " " << r.first << endl;
                        break;
                    }
                }
            }
        }
        else {
            cout << "Impossible." << endl;
        }

        if (T) {
            cout << endl;
        }
    }

    return 0;
}
