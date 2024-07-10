
/*
Para este problema utilizamos la funcion get_winer para poder
contabilizar los puntos acumulados de cada corredor a traves de la temporada,
es decir, por cada gran premio.

Recorremos las posiciones finales de los premios y verificamos que los pilotos hayan
quedado en zona de puntos, de ser asi, asignamos los puntos correspondientes a su
posicion, dados por el sistema utilizado, a sus puntuacion acumulada.

Por ultimo volvemos a recorrer el arreglo de puntos acumulados y vemos
cuantos de ellos tienen la puntuacion maxima, devolvemos un arreglo con los ganadores

Realizamos el proceso anterior para cada uno de los sitemas de puntaje. 

*/


#include<bits/stdc++.h>
using namespace std;


#define vi std::vector<int>
#define vvi vector<vector<int>>
#define pb push_back

inline vi get_winer (const vi & sistema, const vvi & carreras, const int p){
  vi puntos_acumulados (p, 0);
  int ultimo_puntuado = sistema.size();
  int max = 0 ;

  for(auto resultado: carreras){
    for(int i = 0;  i < p; i ++)
      if(resultado[i] < ultimo_puntuado){
        puntos_acumulados[i] += sistema[resultado[i]];
        max = (max > puntos_acumulados[i]) ? max : puntos_acumulados[i];
      }
  }

  vi ganadores;

  for(int i = 0; i < p; i++)
    if(puntos_acumulados[i] == max) ganadores.pb(i + 1);

  return ganadores;

}


int main(){

  int g, p; // Carreras, pilotos

  while(cin >> g >> p && (g && p)){
    vector<vector<int>> lugares(g);
    for(int i = 0; i < g; i++){
      lugares[i].resize(p);
      for(int j = 0; j < p; j++){
        cin >> lugares[i][j];
      }
    }

    int s;
    cin >> s;
    cin.ignore();
    vector<vector<int>> sis_puntos (s);

    for(int j = 0; j < s; j++){
      string str;
      getline(cin, str);
      istringstream iss(str);
      int tmp;
      while(iss >> tmp) sis_puntos[j].pb(tmp);
    }

     bool flag;
    for(auto sistema: sis_puntos){
      vector<int> winners = get_winer(sistema, lugares, p);
       flag = 1;
        for(auto ganador: winners){
          if(!flag) cout << " ";
          cout << ganador;
          flag = 0;
        }

      cout << endl;
    }



  }



  return 0;
}
