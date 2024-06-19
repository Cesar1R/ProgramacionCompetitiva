#include<bits/stdc++.h>
using namespace std;


/*
Para este problema se implementaron varias funciones de utilidad. Principalmente esta
la que nos permite convertir de caracter a entero para poder sumar con falicidad, las demas
son funciones que nos permiten verificar la validad de las cadenas que nos dan por
entrada, si estas no estan ordenadas de mayor a menor, si no cumplen las condiciones
de tener los simbolos iguales juntos o si alguno se repite mas de 9 veces, entonces
podemos rechazarla.
*/

inline int to_numer(char c){
  switch (c) {
    case 'B':
      return 1;
    case 'U':
      return 10;
    case 'S':
      return 100;
    case 'P':
      return 1000;
    case 'F':
      return 10000;
    case 'T':
      return 100000;
    case 'M':
      return 1000000;
    default:
      return 0;
  }
}

inline bool is_orderd (const string & cadena ){
  unordered_map <char, int> lugar= {
        {'B', 0}, {'U', 1}, {'S', 2},
        {'P', 3}, {'F', 4}, {'T', 5},
        {'M', 6}
    };

  int k = -1;
  int k_inverso = 7;

  for(char c: cadena){
    if(lugar.find(c) != lugar.end()){
      int id = lugar[c];
      int id_rev = 6 - id;

      //if(!(k <= id ||  id_rev <= k_inverso))
        //return false;

        k = id;
        k_inverso = id_rev;
    }

  }
    return 1;

}

inline bool valid (map<char, bool>  & used, char c, int k){
  if(used[c] || k >  9)
    return false;
  else
    return true;
}

int main() {
  int n;
  string s;

  map <char, bool> used;
  map <char, int> rep;

  cin >> n;

  while (n--){
    used['B'] = false;
    used['U'] = false;
    used['S'] = false;
    used['P'] = false;
    used['F'] = false;
    used['T'] = false;
    used['M'] = false;

    rep['B'] = 0;
    rep['U'] = 0;
    rep['S'] = 0;
    rep['P'] = 0;
    rep['F'] = 0;
    rep['T'] = 0;
    rep['M'] = 0;

    cin >> s;
    const char * cadena = s.c_str();
    int sum = 0;
    bool flag = is_orderd(s);
    int repeticiones = 0;

    int i = 0;
      while(i < s.length() && flag){
        rep[cadena[i]] += 1;
        if(valid(used, cadena[i], rep[cadena[i]]))
            sum += to_numer(cadena[i]);
        else{
          flag = 0;
          break;
        }

        if( i != s.length()  -1 && cadena[i] != cadena[i+1])
          used[cadena[i]] = 1;

        else if (i == s.length()-1)
          used[cadena[i]] = 1;

        i++;
      }


      if(flag)
        cout << sum << endl;
      else
        cout << "error" << endl;

  }


  return 0;
}
