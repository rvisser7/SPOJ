#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    int n;
    string s;
    vector<int> table;
    int pos, cnd;

    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> s;

        //DO KMP TABLE
        table.resize(n);
        table.clear();
        table[0] = -1;
        table[1] = 0;

        pos = 2;
        cnd = 0;
        while (pos < n) {
            if (s[pos-1] == s[cnd]) {
                cnd++;
                table[pos] = cnd;
                pos++;
            } else if (cnd > 0) {
                cnd = table[cnd];
            } else {
                table[pos] = 0;
                pos++;
            }
        }

        //CHECK DEBUG
        for (int i = 0; i < n; i++) {
            cout << table[i] << ' ';
        }
        cout << "\n";

        for (int i = 0; i < n; i++) {
            cout << (n-i)+ 1 + table[i] << ' ';
        }
        cout << "\n";
    }

    return 0;
}
