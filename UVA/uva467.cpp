/*
En este problema queremos encontrar si dentro de la primera hora existe un momento 
en que todos los semaforos estaran en verde de nuevo, sabemos cuanto tiempo les toma 
estar en cada color, utilizaremos que los limites del problema son bastante bajos 
para probar en cada segundo de la hora, tomando como punto de inicio el tiempo del menor
ciclo, ya que buscamos el momento en que estaran de nuevo en verde. 
*/

#include <bits/stdc++.h>

#define endl "\n" 
using namespace std;

const int  TIEMPO_MAX = 60 * 60; 




inline bool  color (int t_segundos, int t_ciclo)
{
  int c = (t_segundos % t_ciclo);
  c = (c == 0)? t_ciclo: c;


  int t_v  = (int)((t_ciclo)/2) -5;

  if(c <= t_v)
    return 0;


  return 1; 
}


int main()
{
  string s;
  int id = 0;
  while(getline(cin, s))
  {
      istringstream ciclos (s);
      int tmp; 
      set <int> tiempos;

      while ( ciclos >> tmp ) 
        tiempos.insert(tmp); 

      int id_temp = id; 
      for(int i = (*tiempos.begin()) *2 ; i < TIEMPO_MAX; i++)
      {
        if(id > id_temp) break; 

        int k = 0; 
        for(auto tiempo: tiempos)
          if(color(i, 2*tiempo))
            break;
          else k++; 

        if(k == tiempos.size())
        {
         // cout << "Set " << ++id << " synchs again at " << (int) i/60 << " minute(s) and "  << i%60 - 1 << " second(s) after all turning green. " << endl;
          cout << "Set " << ++id << " synchs again at " << (int) i / 60 << " minute(s) and " << (int) i % 60 - 1 << " second(s) after all turning green.\n";
          break;  
        }   
          
      }

      if(id == id_temp)
        //cout << "Set " << ++id << " is unable to synch after one hour. " << endl; 
        cout << "Set " << ++id << " is unable to synch after one hour.\n";  

  }

  return 0;
}
