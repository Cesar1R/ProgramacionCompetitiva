#include <bits/stdc++.h> 

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 

    int t; 
    cin >> t; 

    bool linea_uno = true; 

    while (t--) { 

        if(!linea_uno){
            cout << endl; 
        }
        
        linea_uno = false; 

        int d; 
        cin >> d; 

        int l, h, q, p; 

        string s; 
        map<string, pair<int, int>> data_base; 

        for (int i = 0; i < d; i++) {
            cin >> s >> l >> h;
            data_base[s] = {l, h}; 
        }

        cin >> q; 

        for (int i = 0; i < q; i++) {
            cin >> p; 
            vector<string> candidates; 

            for (const auto &marca : data_base) {
                if (marca.second.first <= p && p <= marca.second.second) {
                    candidates.push_back(marca.first); 
                }
            }

            if (candidates.size() == 1) { 
                cout << candidates[0] << endl; 
            } else {
                cout << "UNDETERMINED" << endl; 
            }
        }
    }
    return 0; 
}
