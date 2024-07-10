/*

Para este problema utilizaremos calcularemos el arbol de expansion minima
entre las conexiones de las escuelas, haremos uso del metodo union-find
para representar al grafo que contiene las conexiones entre escuelas.

La respuesta al probelema es el primer y segundo arbol de expansion minima en el grafo

*/


#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define vb vector<bool>



typedef struct edge_s {
    int src, dest, weight;

    edge_s (int s, int d, int w):  src(s), dest(d), weight(w) {}
    edge_s (): src(0), dest(0), weight(0) {}
} Edge;


bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}


int findParent (int u, vi &p)
{ return (p[u] == -1) ? u : (p[u] = findParent(p[u], p)); }

int mSpanningTree ( int n, int m, vb &used, vb &valid, bool is_used, vector<Edge> & e_list  ){
  vi p;
  p.assign(n + 1, -1);
  int s = n;
  int total = 0;

  for(int i = 0; i < m; i++){
    if(valid[i]){
      int a = e_list[i].src;
      int b = e_list[i].dest;
      int c = e_list[i].weight;
      if(findParent(a, p) != findParent(b, p)){
        if(is_used) used[i] = true;
        p[findParent(a, p)] = findParent(b, p);
        s--;
        total += c;
      }
    }
  }
  return (s == 1) ? total : INT_MAX;
}
// int n, int m, vi &p, vb &used, vb &valid, bool is_used, vector<Edge> & e_list
int mSpanningTreeDOS (int n, int m,  vb &used, vb &valid, vector<Edge> & e_list)
{
  int k = INT_MAX;

  for(int i = 0; i < m; i++){
    if(used[i]){
      valid[i] = 0;
      int temp = mSpanningTree( n, m, used, valid, false, e_list);
      if(temp < k)
        k = temp;
      valid[i] = 1;
    }
  }

  return k;

}

int main() {
  int t, m, n, a, b, c;
  cin >> t;


  for(int i = 0; i < t; i++){
    cin >> n >> m;

    vector<Edge> e_list (m);

    for(int j = 0; j < m; j++){
      cin >> e_list[j].src >> e_list[j].dest >> e_list[j].weight;
        //cin >> a >> b >> c;
      //Edge tmp(a, b, c); //src, dest, weight;
      //e_list.pb(Edge(a, b, c));
    }
    sort (e_list.begin(), e_list.end(), compareEdges);
    vb used, valid;
    used.assign(m, 0);
    valid.assign(m, 1);
// int n, int m, vi &p, vb &used, vb &valid, bool is_used, vector<Edge> & e_list
    int o_uno = mSpanningTree(n, m, used, valid, true, e_list);
    int o_dos = mSpanningTreeDOS(n, m, used, valid,  e_list);
    cout << o_uno << " " << o_dos << endl;
  }

  return 0;
}
