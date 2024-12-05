#include <bits/stdc++.h> 

using namespace std; 


int main(){
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  int t, n, k, p;

  cin >> t; 

  for(int i = 1; i <= t; i++){
    cin >> n >> k >> p;

    cout << "Case " << i << ": "<< (  ((k + p)%n)? (k+p)%n : n)<< endl; 
  
  }

  return 0;
}
