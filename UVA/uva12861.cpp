/*
Para este problema desde que estamos leyendo las zonas horarias identificamos
si existe alguna repetida que nos pueda generar un 0, de ser asi, eliminamos el elemento
que corresponde con el numero que estamos leyendo.

Por otro lado, cuando descartamos los 0 ordenamos el arreglo, con la funcion ans
comparamos si la distancia entre los exrtemos es menor que la distancia entre el primer
numero y el segundo o entre el ultimo y el penultimo, en caso de que si sea menor que
alguno de los dos, entonces quitamos los extremos y agregamos la distancia a nuestra
respuesta.

Luego de haber concluido con los extremos que cumplen la condicion, utilizamos el arreglo
ordenado para hacer parejas contigüas y sumar su distancia a la respuesta.
*/


#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back

inline int get_diference (const int i, const int j){
  int tmp = abs(i - j);
  return (tmp < 24 - tmp) ? tmp : 24 - tmp;
}


inline int ans(vi & z){
  int min = 0, t, frente, cola;
  t = get_diference(z[0], z[z.size()-1]);
  frente = get_diference(z[0], z[1]);
  cola =  get_diference(z[z.size()-2], z[z.size()-1]);

  while( (t < frente || t < cola)){
    min += t;
    z.erase(z.begin());
    z.pop_back();
    if(z.size() < 2) break;
    t = get_diference(z[0], z[z.size()-1]);
    frente = get_diference(z[0], z[1]);
    cola =  get_diference(z[z.size()-2], z[z.size()-1]);
  }

  for(int i = 1; i < z.size(); i += 2){
    t = get_diference(z[i-1], z[i]);
    min += t;
    //cout << min << " " << t << " " << z[i-1] << " " << z[i] << '\n';
  }

  return min;
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  while (cin >> n){
    vi zonas_h (n);
    for(int i = 0; i < n; i++){
      cin >> zonas_h[i];
    }

      sort(zonas_h.begin(), zonas_h.end());

      cout << ans(zonas_h) << '\n';

  }

  return 0;
}
