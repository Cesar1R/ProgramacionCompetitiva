#include<bits/stdc++.h> 

using namespace std; 

string timeConversion(string s) {
    bool pm = false; 
    
    string new_time = s, tmp; 
    
    char car = s[8]; 
    
    tmp += s[0]; 
    tmp += s[1]; 

    if(car == 'P'){pm = true;}
    
    if(pm){
        int num = std::stoi(tmp); 
            num += 12;
        
        tmp = std::to_string(tmp); 
    }

    new_time.pop_back(); 
    new_time.pop_back(); 
    
    new_time[0] = tmp[0];
    new_time[1] = tmp[1]; 
    
    return new_time; 
    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
