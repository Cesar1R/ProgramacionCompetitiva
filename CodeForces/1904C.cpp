//https://codeforces.com/problemset/problem/1904/C

#include <bits/stdc++.h>
using namespace std;




int solve (){
  int n, k;

  cin >> n >> k;

  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  switch (k) {
    case 1:
    sort(arr.begin(), arr.end());
    int min = 0;
    for(int i = 0; i < n; i++){

    }

      break;

    case 2:
      break;

    case 3:
      cout << 0;
      break;
  }

}


int main(){

  int t;
  cin >> t;

  while(t--){
    solve();
  }


  return 0;
}
