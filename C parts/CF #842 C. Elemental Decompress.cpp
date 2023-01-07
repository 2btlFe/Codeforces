/*
CF #842 C. Elemental Decompress
Algorithm: MEX(SET), Greedy
TC: O(nlogn)
SC: O(??)
Explaination:

Set을 이요한 MEX개념을 통해 
Greedy하게 두 개의 배열에 값을 집어 넣어준다
*/


#include <bits/stdc++.h>
#define ll long long
#define enld "\n"
#define all(x) x.begin(), x.end()
 
using namespace std;
 
void solve() {
    int n; cin >> n;
    vector<pair<int, int> > v;
    vector<int> retp(n), retq(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back({x, i});
    }
    sort(all(v));
    
    set<int> p, q;
    for(int i = 1; i <= n; i++) {
        p.insert(i);
        q.insert(i);
    }
    
    for(auto pi : v) {
        int x = pi.first;
        int idx = pi.second;
        if(p.find(x) != p.end()) {
            retp[idx] = x;
            p.erase(x);
            int mex = *q.begin();
            if(mex > x) {
                cout << "NO" << endl;
                return;
            }
            
            retq[idx] = mex;
            q.erase(mex);
        } else if(q.find(x) != q.end()) {
            retq[idx] = x;
            q.erase(x);
            int mex = *p.begin();
            if(mex > x) {
                cout << "NO" << endl;
                return;
            }
            retp[idx] = mex;
            p.erase(mex);
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
    for(int pi : retp) cout << pi << " ";
    cout << endl;
    for(int qi : retq) cout << qi << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
