#include<bits/stdc++.h> 

using namespace std; 

#define vi vector<int> 
#define pb push_back 


pair<int, int>  dp[20001]; 

void solve (vector<int> & descripcion, const int k){
    int n = descripcion.size(),
        max_sum = INT_MIN, 
        tmp_sum = 0,
        min_id = 0, max_id = 0;  

    memset(dp, 0, sizeof(dp));  


    for(int i = 0; i < n; i++){ 

        if(i == 0){
            tmp_sum = descripcion[i]; 
            min_id = max_id = i; 
        }else { 
            if(tmp_sum + descripcion[i] < descripcion[i] || tmp_sum <  0){
                min_id = i; 
                tmp_sum = descripcion[i];  
                max_id = i; 
            }
            else{
                max_id = i;  
                tmp_sum += descripcion[i];        
            }
        }

        if( tmp_sum > max_sum || (tmp_sum == max_sum && (max_id - min_id > dp[i-1].second - dp[i-1].first))){
            dp[i] = {min_id, max_id}; 
        }else{
            dp[i] = (i == 0) ? make_pair(0,-1) : dp[i-1]; 
        }

        max_sum = max(max_sum, tmp_sum);   
    }   
    
    if(max_sum > 0){
        cout << "The nicest part of route " << k << " is between stops " << dp[n-1].first + 1 << " and " << dp[n-1].second + 2 << endl; 
    }else{ 
        cout << "Route " << k << " has no nice parts" << endl;
    }


}



int main(){

    int b, tmp, tmp1; 
    cin >> b; 
    vector<int> descripcion_rutas; 

    for(int i = 1; i <= b; i ++){
        cin >> tmp1;
        descripcion_rutas.clear(); 
        for(int j = 1; j < tmp1; j++){
            cin >> tmp; 
            descripcion_rutas.pb(tmp);  
        }

        solve(descripcion_rutas, i); 
    }





    return 0; 
}