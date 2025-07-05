#include<bits/stdc++.h>
#define IOS_OPTIMIZE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dp[100][100];
int V[100];
int W[100]; 

int n;



int fill_dp(int id, int remW){
    if(id > n){
        return 0;
    }

    if(remW == 0 || id == n+1){
        dp[id][remW] = 0;
    }

    if(W[id] > remW){
        if(dp[id][remW] == -1){dp[id][remW] = fill_dp(id + 1, remW);}
    }

    if(W[id] <= remW){
        if(dp[id + 1][remW] ==-1){dp[id+1][remW] = fill_dp(id + 1, remW);}
        if(dp[id + 1][remW - W[id]] == - 1){dp[id+1][remW-W[id]] = fill_dp(id + 1, remW - W[id]);}

        dp[id][remW] = std::max(dp[id+1][remW], V[id] + dp[id+1][remW-W[id]]); 
    }


    return dp[id][remW];
    
}

int main(void){
    IOS_OPTIMIZE
    int S; 

    cin >> n >> S; 

    memset(V, 0, sizeof(V));

    int i;
    for(i=1; i<=n; i++){
        cin >> V[i];
    }
    
    memset(W, 0, sizeof(W));
    for(i=1; i<=n; i++){
        cin >> W[i];
    }


    memset(dp, -1, sizeof(dp));

    int ans = fill_dp(0, S);

    cout << ans  << endl;
    return 0;
}