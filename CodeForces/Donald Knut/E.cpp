#include<bits/stdc++.h>

using namespace std; 

#define pd push_back
#define vi vector<int> 
#define vvi vector<vector<int>> 

const int N = 1000+1; 

unsigned short dp[N][N][N]; 


int main(){

    int n, q; 

    cin >> n; 

    vvi mat(n+1, vi(n+1));  

    for (int i= 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> mat[i][j]; 
        }
    }

    memeset(dp, 0, sizeof(dp)); 

    unsigned short cont_arr [n+1];
    
    memeset(cont_arr, 0, sizeof(cont_arr))

    for (int i= 1; i <= n; i++){
        for(int j = 1; j <= i; k++){
            cont_arr[mat[i][j]]++; 
        }
    }

    for (int i =1; i <= n; i++){
        for(int k = 1; k <=n; i++){ 
            dp[i][i] = dp
        }
    }






    return 0; 
}
