#include <bits/stdc++.h> 

using namespace std;    

#define ll long long 
#define pb push_back 
#define vi vector<int>
#define vvi vector<vector<int>> 

int main(){

    int t, n, m, h; 

    cin >> t; 

    while(t--){

        cin >> n  //participantes 
            >> m  //problemas 
            >> h; //limite de tiempo 


        vvi tiempos(n, vi(m)); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> tiempos[i][j];
            }
        }

        // Tiempo acumulado, tiempo de penalizacion
        pair<int, ll> soluciones [n]; 

        for(int i = 0; i < n; i++){
            ll t_pen = 0, 
                t_ac = 0; 
                
            int pts = 0; 
            
            sort(tiempos[i].begin(), tiempos[i].end()); 

            for(int j = 0; j < m; j++){
                if(t_ac + tiempos[i][j] > h){break;} 
                else{
                    t_ac += tiempos[i][j]; 
                    t_pen += t_ac;  
                    pts++; 
                }
            }

            soluciones[i] = make_pair(-pts, t_pen); 
        }

        int lugar = 1; 

        for(int i = 1; i < n; i++){
            if( soluciones[i] < soluciones[0]){
               lugar++;  
            }
        }


        cout << lugar << "\n"; 
        
    }


    return 0; 
}