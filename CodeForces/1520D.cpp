#include<bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define pii pair<int, int>


typedef long long ll;
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  scanf("%d\n", &t);

  while(t--){
    int n;
    scanf(" %d \n", &n);
      map<int, int> a;
      ll res = 0;
      for(int i=0; i < n; i++){
        int x;
        scanf("%d\n", &x);
        x -= i;
        res += a[x];
        a[x]++;
      }
      printf("%lld \n", res);
  }

  return 0;
}
