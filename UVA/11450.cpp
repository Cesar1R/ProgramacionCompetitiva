#include<bits/stdc++.h>

#define optimize ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


int precios [20][20];
int dp[210][25]; 
//dp[i][j] = la mayot cantidad de dinero que se puede gastar considerando los primeros i articulos  (filas) y las primeras j columnas

int M, C; 

int fill_dp(int money, int g){
    if (money < 0) return -1000000;
    if(g == C) return M - money; 

    if(dp[money][g] != -1) return dp[money][g];

    int ans =-1;
    for(int model =1; model <= precios[g][0]; model++){
        ans = std::max(ans, fill_dp(money-precios[g][model], g+1));
    }

    return dp[money][g] = ans; 
}


inline void solve(){

    int N, K, ans;
    
    int i, j;

    cin >> N; 

    while(N--){
        cin >> M >> C; 
        for(i=0; i<C; i++){
            cin >> precios[i][0]; 
            for(j=1;j<=precios[i][0]; j++){
                cin >> precios[i][j];
            }
        }

        memset(dp, -1, sizeof(dp));

        ans = fill_dp(M, 0);
        if(ans < 0){
            cout << "no solution" << endl;
        } else{
            cout << ans << endl;
        }
    }

}


int main(){

    solve();

    return 0;
}