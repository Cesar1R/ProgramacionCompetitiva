#include<bits/stdc++.h>

#define OPTIMIZE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

inline void solve(){
    int n, i, sum = 0, ans =0;
    cin >> n; 
    
    int arr [n];

    for(i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i]; 

        ans = std::max(ans, sum);
        sum = std::max(sum, 0);
    }  

    cout << ans << endl; 
}

int main(void){
    OPTIMIZE
    solve();

    return 0;
}