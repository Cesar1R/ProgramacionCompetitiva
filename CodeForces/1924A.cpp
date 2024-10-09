#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 26;

bool is_subsequence(const string& s, const string& t) {
    int m = s.size();
    int n = t.size();
    int j = 0;
    for (int i = 0; i < m && j < n; i++) {
        if (s[i] == t[j]) {
            j++;
        }
    }
    return j == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;

        bool all_present = true;
        string not_subsequence;


        vector<string> candidates;
        string current(n, 'a');
        candidates.push_back(current);


        while (true) {
            int pos = n - 1;
            while (pos >= 0 && current[pos] == 'a' + k - 1) {
                current[pos] = 'a';
                pos--;
            }
            if (pos < 0) break;
            current[pos]++;
            candidates.push_back(current);
        }


        for (const auto& candidate : candidates) {
            if (!is_subsequence(s, candidate)) {
                all_present = false;
                not_subsequence = candidate;
                break;
            }
        }

        if (all_present) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            cout << not_subsequence << "\n";
        }
    }

    return 0;
}
