#include<bits/stdc++.h> 

#define vi vector<int> 
#define pb push_back

using namespace std; 
using ll = long long;



inline void solve(){
    int n, i, j, tmp; 
    cin >> n; 

    vi hops_length_count (n+1, 0);  

    for(i = 1; i <= n; i++){
        cin >> tmp;  
        if(tmp <= n){ hops_length_count[tmp]++;}    
    }

    vi reps_arr(n+1, 0); 

    for(i = 1;  i <= n; i++){
        if(hops_length_count[i] == 0){continue;} 
        
        reps_arr[i] = reps_arr[i] ? reps_arr[i] + hops_length_count[i]:hops_length_count[i]; 
        for(j = 2; j <= 1 +  (int)(n/i) ; j++){
            if(i * j > n){continue;} 
            reps_arr[i*j] += hops_length_count[i]; 
        }          

    }


    auto max_reps = *std::max_element(reps_arr.begin(), reps_arr.end()); 


    cout << max_reps << endl; 
}


int main(){
    int t; 
    cin >> t; 

    while(t--){
        solve(); 
    }

    return 0;
}
