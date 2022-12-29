/*
CF #841 C. Even Subarrays
Algorithm: prefix_sum, hash, bitwise
TC: O(n*sqrt(2*n))
SC: O(n)
Explaination:

Bitwise 연산의 특징 
1) a^0 = a
2) a^a = 0
3) a^b = c 라면 a^c = b이다
4) (a^b)^c = a^(b^c)
5) 연산자 순서가 9번으로 낮아서 대부분 괄호를 해주어야 한다

n 이 10^5 이상이라면
1) n*log(n)
2) n*len(prime)
3) n*sqrt(n)

정도는 생각해보자
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

void solve() {
    ll n; cin >> n;
    vector<ll> p(n);
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        p[i] = x ^ ((i == 0) ? 0 : p[i-1]);
    }
    
    //O(n * sqrt(n))
    vector<int> m(2*n, 0);
    m[0] = 1;
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        for(ll j = 0; j*j < 2*n; j++) {
            if((p[i] ^(j*j)) < 2*n) {
                cnt += m[p[i] ^ (j*j)];
            }
        }
        m[p[i]]++;
    }
    ll ret = (n * (n+1) / 2) - cnt;
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
