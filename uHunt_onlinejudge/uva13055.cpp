#include<bits/stdc++.h>
using namespace std;

/*
Para este problema se utilizo una pila para identificar en que sueño estaba la personas
que brincaba entre ellos.

Si la pila esta vacia entonces la persona no estaba en un sueño. En otro caso,
dependiento de la instruccion recibida es la accion, si lo sacaban, quitamos la cima
de la pila y para el test, verificabamos el contenido de la pila. 
*/


int main (){
  ios_base::synch_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;

  string s, name;
  stack <string> nombres;

  while(n--){
    cin >> s;

    if(s == "Sleep"){
      cin >> name;
      nombres.push(name);
    }
    else if(s == "Kick"){
      if(!nombres.empty()) nombres.pop();
    }
    else if(s == "Test"){
      if(nombres.empty()){
        cout << "Not in a dream" << '\n';
      }
      else{
        cout << nombres.top() << '\n';
      }
    }
  }

return 0;
}
