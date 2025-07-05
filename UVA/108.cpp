#include<bits/stdc++.h>
#define OPTIMIZE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


using namespace std;


void solve(){

    int  N, i, j, tmp; 
    cin >> N; 

    int mat [N][N]; 

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            cin >> mat[i][j];
            if(i > 0) mat[i][j] += mat[i-1][j];
            if(j > 0) mat[i][j] += mat[i][j-1];
            if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
        }
    }
    

    int maxSubRect = -127 * 100 * 100, 
        k, l;

    for(i=0; i < N; i++){
        for(j = 0; j<N; j++){
            for(k=i; k<N; k++){
                for(l=j; l<N; l++){
                    int subRect = mat[k][l];
                    if(i > 0) subRect -= mat[i-1][l];
                    if(j > 0) subRect -= mat[k][j-1];
                    if(i > 0 && j >0) subRect += mat[i-1][j-1];

                    maxSubRect = std::max(maxSubRect, subRect);
                }
            }
        }
    }


    cout << maxSubRect << endl;
}

int main(void){
    OPTIMIZE
    solve();
    return 0;
}