#include<bits/stdc++.h> 

using namespace std; 
#define pb push_back
#define vi vector<int> 
#define vvi vector<vector<int>> 


int main (){
     
    bool flag = true;

    int it=0; 

    int n = 1000, contador = 0; 

    set<int> blancos; //par
    set<int> negros;  // impar 
    negros.insert(1); 
 

    queue <pair<int, int>> por_visitar;

    por_visitar.push({1, -1});


    int curr = 0; 

    do{
        contador++; 

        if(contador > 2 *n){
            flag = false;
            break; 
        }

        por_visitar.pop(); 

        it++; 
        
        string s;  
        getline(cin, s); 

        istringstream iss (s);

        int i=1, j=1, k;

        iss >> k; 

        if(k==0){
            continue; 
        }

        for(i = 0; i < k; i++){
            iss >> j; 
            por_visitar.push({j, it});

            if(it%2){ // par
                if( negros.find(j) != negros.end()  ){
                    cout << "No" << endl; 
                    flag = false; 
                    cout.flush();  
                    break; 
                }else{
                    blancos.insert(j); 
                }
            }else { //impar 
                if(blancos.find(j) != blancos.end()  ){
                    cout << "No" << endl; 
                    flag = false; 
                    cout.flush();  
                    break; 
                }else{
                    negros.insert(j);  
                }

            }
        }

        if(!flag){ break; }

        pair<int, int> act = por_visitar.front(); 
        
        

        curr = act.first; 
        it = act.second;


        cout << 'M' << ' ' << curr <<  endl;
        cout.flush(); 

  
    }while(!por_visitar.empty()); 
        
    if(flag){cout << "Yes" << endl;}


    return 0; 
}