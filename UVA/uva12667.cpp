/*
Para este problema utilizamos una structura que nos permite almacenar los envios hechos,
desde la lectura de envios descartaremos aquellos que no hayan sido aceptados.

Luego los equipos que ya tengan un envio valido descartaremos cualquier envio
siguiente para el mismo problema.

Por ultimo solo imrpimimos los valores que obtuvimos para cada problema que almacenamos
en otro arreglo el cual construimos de hacer las filtraciones anteriores, utilizamos
una funcion propia para ordenar por problema y en su defecto desempatamos por el tiempo .

*/

//Creo que el problema puede ser en los casos especificos donde
//los problemas no tienen nombres consecutivos, se arregla modificando la imrpesion. 

#include<bits/stdc++.h>
using namespace std;


typedef struct submit {
  int time;
  int teamID;
  char problem;
  bool ver;

  submit(int x, int y, char c, bool b) :
  time(x), teamID(y), problem(c), ver(b) {}
} Submit;


int main(){
  int n, t, m, i;
  int t1, t2;
  char c, curr;
  string s;
  vector<submit> lb;


  cin >> n >> t >> m;

  set<char>problemas;

  for(i = 0; i < m; i++){
    cin >> t1 >> t2 >> c >> s;
    if(s == "Yes"){
        lb.push_back(submit(t1, t2, c, true));
        problemas.insert(c);
      }
  }

  vector<submit> submits;
  bool found ['L'+1][t+1] = {false}; //n problemas t equipos

  for(auto c: lb){
    if(!found[c.problem - 'A'][c.teamID]) {
      found[c.problem - 'A'][c.teamID] = true;
      submits.push_back(c);
    }
    else continue;
  }


  sort(submits.begin(), submits.end(), [](const submit &a, const submit &b){
     if( a.problem != b.problem)
        return a.problem < b.problem;
     else
        return a.time > b.time;
  });


  curr = 'A';

  for(i = 0; i < submits.size() && curr - 'A' < n;){
    //if(problemas.find(curr) !=  problemas.end()){
    c = submits[i].problem;
      if(curr < c){
        cout << curr++ << " - -" << endl;
      }
      else if (c < curr) i++;
      else {
        cout << curr << " " << submits[i].time << " " << submits[i].teamID << endl;
        curr++; // Incrementar curr después de imprimir el submit actual
        i++;
      }
    //}
  }

  while(curr - 'A' <  n){
    //if(problemas.find(curr) !=  problemas.end())
    cout << curr++ << " - -" << endl;
  }




  return 0;
}
