/*
Para este problema utilizamos la funcion get_ans para poder indentificar de entre las
posibilidades cuantos digitos tenian de diferencia las posibilidades con el numero
de mama al que podiamos hacer recall.

Ya que sabemos que puede haber a lo mas un solo miss_match, entonces descartamos todas
las cadenas que tengan mas de un digito diferente. 
*/

#include<bits/stdc++.h>
using namespace std;


inline vector<string> get_ans(const vector<string> & vec, const string & moms){
  vector<string> ans;
  int len = vec.size();
  vector<bool> flag(len, true);
  int num_len = moms.length();

  vector<int> miss_match(len, 0);

  for(int i = 0; i < num_len; i++){

    for (int j = 0; j < len; j++) {
        if (vec[j][i] != moms[i]) {
            miss_match[j] ++;
        }

        if (miss_match[j] >= 2) {
            flag[j] = false;
        }
    }
  }


  for(int i =0; i <len; i++)
      if(flag[i]){
        ans.push_back(vec[i]);
        //cout << vec[i] << endl;
      }



  return ans;
}

int main (){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n;
  string s, moms;
  for (size_t j = 1; j <= n; j++) {
    cin >> k;
    vector<string> pos(k);
    for(int i = 0; i < k; i++)
      cin >> pos[i];

    cin >> moms;

    cout << "Case " << j << ":" << '\n';
    for(auto pos_ans : get_ans(pos, moms)) // posible answers
      cout << pos_ans << '\n';


  }

}
