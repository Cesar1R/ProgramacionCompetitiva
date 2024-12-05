#include<bits/stdc++.h> 

using namespace std; 


int main (){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 

    int t, n; 
    cin >> t; 

    while(t--){
        cin >> n;
        string s;
        cin >> s; 

        int cont = 0; 
        for(int i = 1; i < n-1; i++){
            if(s[i-1] == s[i+1]){cont++;}
        }
        
        cout << n-1 - cont << "\n";

    }


    return 0; 
}