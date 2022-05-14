/*
Problem: https://codeforces.com/contest/1680/problem/C
Algorithm: Prefix_Sum, Math
TimeComplexity: O(n)

min인 상태는 항상 부분 문자열의 길이가 문자열의 1의 개수의 합이 되어야 한다.
그러므로 문자열의 길이가 고정된 상태로 선형 탐색하여 최소의 0의 개수를 구하면 된다.

n = 10^5일 때는 
n^2을 쓸 수 없다 
문자열에서 양쪽 끝을 지워서 최적화 문제를 찾는 경우
= 부분 문자열의 값 최적화
= prefix_sum이 거의 필수 -> 이 문제
= 필요하면 dp도 가능 -> boj skk문자열
= 만약 10^5이하면 그냥 O(n^2) dp 쓰면 된다 -> boj 유전자 
*/

#include<bits/stdc++.h>
using namespace std;
#define len(x) (int) (x).size()
#define all(x) x.begin(), (x).end()
#define endl "\n"
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
#define fi first
#define se second

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
      
    const int mx = 2*1e5;
    
    int t; cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int l = s.size();
          
        int psum0[mx+1];
        int num1 = 0;
        psum0[0] = 0;
        for(int i = 0; i < l; i++) {
            psum0[i+1] = (s[i] == '0') ? psum0[i] + 1 : psum0[i];
            if(s[i] == '1') num1++;
        }
        
        int ret = mx;
        // sz 0 -> l l - sz
        for(int i = num1; i <= l; i++) {
            ret = min(ret, psum0[i] - psum0[i - num1]);
        }
        
        cout << ret << "\n";
    }

}
