/*
Para este codigo se utilizaron dos implementaciones de la transformada en cuestion, la primera de ellas considera que se utilizo
un arreglo de prefijos para implementar la transformada, por lo que solo busca revertirlo desde ese punto.


Por otro lado, la segunda implementacion intenta atacar el problema desde el punto de vista que se sugiere en el problema, obteniendo una tabla
de rotaciones y desde la tabla de rotaciones ordenadas por orden lexicografico, tomar la columna en que aparece la cadena original.
*/



#include<bits/stdc++.h>
using namespace std;



/*
inline string inverse_bwt(const string& bwt) {


  int n = bwt.size();

  vector<pair<char, int>> table(n);
  for (int i = 0; i < n; ++i) {
      table[i] = make_pair(bwt[i], i);
  }

  sort(table.begin(), table.end());

  string original = "";
  int index = 0;
  for (int i = 0; i < n; ++i) {
      original += table[index].first;
      index = table[index].second;
  }

  return original.substr(1, original.size()-1) + original[0];
}
*/


string inverse_bwt(const string & last_column, int original_row) {
    int n = last_column.length();
    vector<pair<char, int>> sorted_last_column(n);


    for (int i = 0; i < n; ++i) {
        sorted_last_column[i] = {last_column[i], i};
    }


    sort(sorted_last_column.begin(), sorted_last_column.end());


    string original_text;
    int current_row = original_row;
    for (int i = 0; i < n; ++i) {
        original_text += sorted_last_column[current_row].first;
        current_row = sorted_last_column[current_row].second;
    }


    reverse(original_text.begin(), original_text.end());

    return original_text;
}

int main() {
    string last_column;
    int original_row;

    while (cin >> last_column >> original_row) {
        string original_text = inverse_bwt(last_column, original_row - 1);
        cout  << original_text << endl;
    }

    return 0;
}
