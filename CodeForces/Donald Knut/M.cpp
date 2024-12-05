#include <bits/stdc++.h> 

using namespace std; 

#define pb push_back 


const int MAXS = 1000; 
const int MAXC = 1000; 


string to_lud (string s){
    //a = 97
    //A = 65
    string new_s = "";

    for(char c: s){
        if(c < 'A'){
            new_s += 'd'; 
        }
        else if (c < 'a'){
            new_s += 'u'; 
        }
        else{
            new_s += 'l'; 
        }
    }


    return new_s; 
}


int main(){

    int n, m, p, s; 

    cin >> n; 

    map<string, string> pat_names; //patron, nombre

    string pat, name; 

    for(int i = 0; i < n; i++){
        cin >> pat >> name; 
        pat_names[pat] = name;  
    }

    cin >> m 
    string tmp; 
    vector<string> cadenas(m); 

    for(int i = 0; i < m; i++){
        cin >> tmp; 
        cadenas.pb(to_lud(tmp)); 
    }



    for(string s: cadenas){

    }


    return 0; 
}