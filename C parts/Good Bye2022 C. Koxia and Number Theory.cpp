/*
Good Bye2022 C. Koxia and Number Theory
Algorithm: Number Theory, CRT
TC: O(n^2/logn)
SC: O(n)
Explaination: 

모든 수를 소수들로 나누었을 때 나오는 나머지가 모두 2개 이상씩
나와야만 아무리 어떤 수를 더해주어도 최소한 두 수는 그 소수로 나누어 떨어지게 된다

만약 어떤 소수로도 위의 경우가 만족되지 않으면
중국인의 나머지 정리에 의해 더해주는 수를 구할 수 있다

나누어 주는 소수들은 비둘기 집의 원리에 의해
2부터 n/2 까지의 소수만 생각하면 된다

n/2 개의 나머지 종류만 있어야지 각각 2개 이상씩 나올 수 있다  
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n; 
    vector<ll> a(n);
    for(ll &x : a) cin >> x;
    
    sort(a.begin(), a.end());
    bool ret = true;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            cout << "NO" << endl;
            return;
        }
    }
    
    bool ok = true;
    for(ll i = 2; i <= n/2; i++) {
        vector<int> v(i, 0);
        for(int j = 0; j < n; j++) {
            v[a[j] % i]++;
        }
        if(*min_element(v.begin(), v.end()) >= 2) {
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
}
