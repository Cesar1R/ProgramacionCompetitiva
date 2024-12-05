/*
Para este problema nos vamos a centrar en los caracteres que descienden, de esta
manera, nos fijaremos en las posibles fosas que almacenan el agua.

Cuando encontremos un caracter que desciende guardaremos su posicion, sabemos que
si encontramo caracter que asciende despues de este al mismo nivel, se generara
una fosa donde se almacenara el agua, cada uno de estos caracteres alberga
1/2 de unidad, por eso, al contabilizarlos juntos mas la cantidad bloques entre ellos
encontraremos el agua almacenada a ese nivel, este proceso se repetira para todos los
niveles de la fosa.

Entiendase por nivel las filas que se ven en la figura del problema.

La respuesta del problema es la suma de estas cantidades.
*/



#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    string s;
    stack<int> pila;
    int ans = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '\\') pila.push(i);

      else if (!pila.empty() && s[i] == '/') {
        ans += i - pila.top();
        pila.pop();
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
