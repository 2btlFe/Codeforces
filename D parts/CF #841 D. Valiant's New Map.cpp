/*
CF #841 D. Valiant's New Map
Algorithm: parametric search, prefix_sum
TC: O(nmlog(min(n, m)))
SC: O(nm)
Explaination:

1) 2차원 prefix sum
//pre[0][0] = 0 을 만들기 위해 pre[i+1][j+1]을 쓴 것이다
정의: pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + add;
사용: sum = pre[i][j] - pre[i-mid][j] - pre[i][j-mid] + pre[i-mid][j-mid];

2) parametric search
int l, r, ret
while(l <= r) {
    int mid = (l + r) / 2;
    
    if(true) {
        ret = mid
        //큰 거 구하면 l = mid + 1
        //작은 거 구하면 r = mid - 1
    } else {
        //큰 거 구하면 r= mid - 1
        //작은 거 구하면 l = mid + 1
    }
    
}
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

int n, m; 
bool check(const vector<vector<int>>& v, int mid) {
    vector<vector<int> > pre(n + 1, vector<int>(m+1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int add = 0;
            if(v[i][j] >= mid) {
                add = 1;
            }
            pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + add;
        }
    }
    for(int i = mid; i < n+1; i++) {
        for(int j = mid; j < m+1; j++) {
            int sum = pre[i][j] - pre[i-mid][j] - pre[i][j-mid] + pre[i-mid][j-mid];
            if(sum == (mid * mid)) return true;
        }
    }
    
    return false;
}

void solve() {
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x; cin >>x;
            v[i][j] = x;
        }
    }
    
    int l = 1;
    int r = min(n, m);
    int ret = 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(v, mid)) {
            ret = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
}
