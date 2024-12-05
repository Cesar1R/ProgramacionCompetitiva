#include<bits/stdc++.h> 

using namespace std; 

pair<int, int> dp[10000+1]; 

void dp_fill (vector<int> & bets) {
    memset(dp, 0, sizeof(dp)); 
    dp[0] = {bets[0], 0}; 
    for(int i = 1; i < bets.size(); i++){
        if(dp[i-1].first + bets[i] >  bets[i]){
            dp[i] = {dp[i-1].first + bets[i], dp[i-1].second + 1}; 
        }
        else{ 
            dp[i] = {bets[i], 1}; 
        }
    }

    return; 
}

inline void solve(vector<int> & bets){
    dp_fill(bets); 
    int n = bets.size(); 
    if(dp[n-1].first > 0 ){
        cout << "The maximum winning streak is " << dp[n-1].first << "." << endl; 
    }
    else{
        cout << "Losing streak." << endl; 
    } 
    return; 
}


int main(){
    int n; 

    while(cin >> n && n != 0){
        
        vector<int> bets(n); 

        for(int i = 0; i < n; i++){
            cin >> bets[i]; 
        }
        
        solve(bets); 

    }



    return 0;
}