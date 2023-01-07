/*
CF #842 D. Lucky Permutation
Algorithm: dfs, Permutation Cycle Decomposition
TC: O(N)
SC: O(N)
Explaination:

같은 composite에 있다면
유일한 inversion을 만들 수 있다
*/

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> f(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        f[i] = x - 1;
    }
    
    int ret = 0;
    vector<int> comp(n, 0);
    int ind = 1;
    for(int i = 0; i < n; i++) {
        if(comp[i]) continue;
        
        int cnt = 0;
        for(int u = i; !comp[u]; u = f[u]) {
            cnt++;
            comp[u] = ind;
        }
        ind++;
        ret += cnt - 1;
    }
    
    for(int i = 0; i < n-1; i++) {
        if(comp[i] == comp[i+1]) {
            cout << ret - 1 << endl;
            return;
        }
    }
    
    cout << ret + 1<< endl;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
}
