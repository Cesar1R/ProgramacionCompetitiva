#include<bits/stdc++.h>


/*https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2661&mosmsg=Submission+received+with+ID+29824285*/



int main(){

   

    long long t, i, n;  

    std::cin >> t; 
    while(t--){

        std::cin >> n; 

        i = (-1 + std::sqrt(1 + 8 * n))/2; 

       std::cout << i  << "\n"; 

    }

    

    return 0; 
}