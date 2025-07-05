#include<bits/stdc++.h>
#define OPTIMIZE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int ways(int n, int k){
    if(k == 1){
        return 1;
    }

    int sum = 0;
    for(int i =0; i<=n; i++){
        sum += ways(n - i, k-1);
    }
    return sum;
}

int main (void){
    int n, K; 

    while(true){
        cin >> n >> K; 

        if(K == 0 && n == 0){break;}

        cout << ways(n, K) << endl;
    }
    return 0;
}