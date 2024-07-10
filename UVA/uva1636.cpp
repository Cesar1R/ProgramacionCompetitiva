/*
Para este codigo primero debemos entender como vamos a medir la probabilidad. La informacion
que tenemos es que la camara que se disparo estaba vacia, por lo tanto, nos interesa
saber, a partir de la posicion inicial, cuantas camaras cargadas se encuentran inmediatamente
despues de una camara vacia.

Realizamos este conteo con probabilidad clasica, casos favorables/posibles, si
es altamente probable que la siguiente camara este cargada entonces rotamos, si
es mas probable que este vacia, disparamos, si ambas probabilidades
son iguales entonces da igual.
*/


#include<bits/stdc++.h>
using namespace std;
typedef double db;
int main(){


  string s;

  while(getline(cin, s)){
    int i, p;
    int cont [4] = {0}; // 0, 1, ->0, ->1
    p = s.length() - 1;
    for(i = 0; i < s.length(); i++){
      if(s[i] == '0'){
        cont[0]++;
        if(s[p] == '0')
            cont[2]++;
      }
      else{
        cont[1]++;
        if(s[p] == '0')
          cont[3]++;
      }
      p=i;
    }
    db rot = (db) cont[0] / ((db)cont[0] + (db)cont[1]);
    db shoot = (db) cont[2] /((db)cont[2] + (db)cont[3]);
    //if(cont[0] < 1) break;
    if(abs(shoot - rot) <  0.0000001){
      cout << "EQUAL" << endl;
    }
    else if (shoot < rot){
        cout << "ROTATE" << endl;
      }
    else if(shoot > rot){
      cout << "SHOOT" << endl;
    }

  }

  return 0;
}
