/*
Teniendo en cuenta que vamos a utilizar la letra mas repetida en el mensaje con la mas
repetida en el codigo de encriptacion, esto le repetiremos para cada frecuencia, por lo que
debemos primero obtener las frecuencias relativas tanto del codigo como del mensaje,
teniendo este orden podemos emparejar las letras para obtener la encriptacion
correspondiente, en este codigo se utilizo un mapa donde como clave guardamos la
correspondencia entre letras dadas por las frecuiencia que obtuvimos antes esto nos permitira
sustituir las letras el mensaje por la clave. 
*/



#include<bits/stdc++.h>
using namespace std;

inline map<char, int> reps (const string & s){
  map<char, int> ans;

  for(char c: s){
    if(ans.find(c) != ans.end())
      ans[c]++;
    else ans[c] = 1;
  }

  return ans;
}


int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  while(n--){

    string s1, s2;
    cin >> s1 >> s2;

    map<char, int> contador_s1 = reps(s1);
    map<char, int> contador_s2 = reps(s2);

    set <pair<int, char>> reps_s1;
    for(auto pair : contador_s1)
      reps_s1.insert(make_pair(pair.second, pair.first));

    set<pair<int, char>> reps_s2;
    for(auto pair : contador_s2)
      reps_s2.insert({pair.second, pair.first});

    map<char, char> equivalencia;
    auto p1 = reps_s1.begin();
    auto p2 = reps_s2.begin();

    while (p1 != reps_s1.end(), p2 != reps_s2.end()){
      equivalencia[p2 -> second] = p1 ->second;
      p1++; p2++;
    }

    string original = "";
    for(char c : s2)
      original += equivalencia[c];

    cout << original << endl;

    cout << endl;
  }

  return 0;
}
