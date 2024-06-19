/*
Para este problema utilizamos una pila de prioridad que nos permite almacenar
cada uno de los medicamentos, para los cuales utilizamos una estructura aparte.
inicializamos la prioridad con el orden en que los leemos, para imprimir, vamos
sacando de la pila que ordena por frecuencia, cuando sacamos un medicamento lo volvemos
a introducir a la pila pero con la frecuencia actual mas la frecuencia original.

Por como creamos el comparador de los medicamentos, en la pila tendremos primero
los que se deben tomar antes y se desempaten por prioridad.

Para obtener la respuesta realizamos el proceso de sacar los medicamentos de la pila y
volverlos a agregar con la frecuencia modificada hasta que hayamos realizado k impresiones.
*/



#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;

typedef struct medicamento {
  ll periodo;
  ll priority;
  string name;

  medicamento(ll _p, ll _p1, string _s):
    periodo(_p), priority(_p1), name(_s) {}


  // Definición del operador de comparación
  bool operator<(const medicamento& other) const {
      if(periodo == other.periodo)
          return priority > other.priority; // Desempate por prioridad
      return periodo > other.periodo;
  }
} medicamento;


int main() {
    int t, n, k, f;
    string s;
    cin >> t;

    while(t--){
      cin >> n >> k;
      priority_queue <medicamento> pq;
      ll p = 1;
      map <string, ll> o_frec;
      while(n--){
        cin >> s >> f;
        pq.push(medicamento(f, p++, s));
        o_frec.insert({s, f});
      }

      while (k--){
        medicamento curr = pq.top(); pq.pop();
        cout << curr.periodo << " " << curr.name << endl;
        ll tmp = o_frec[curr.name];
        pq.push(medicamento(curr.periodo + tmp, curr.priority, curr.name));
      }
    }
    return 0;
}
