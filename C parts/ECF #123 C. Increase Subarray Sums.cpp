/*
ECF #123 C. Increase Subarray Sums
Algorithm: DP, Greedy, Brute Force, Part Sum
Time Complexity: O(N^2)
Explaination: 

i개 연속 구간의 합 최대 
dp[i] = max(dp[i], psum[j] - psum[j - i]);

최소 i개의 연속 구간 합 최대
dp[i] = max(dp[i], dp[i+1]);

i개의 숫자를 k만큼 더했을 때 
sdp[0] = big
sdp[i] = max(sdp[i-1], dp[i] + k*i);

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define len(x) (int) (x).size()
#define all(x) x.begin(), (x).end()
#define endl "\n"
 
int main()
{
  int T;
  cin >> T;
 
    
    const int NEGINF = -987654321;
  while(T--) {
    int n, k;
    cin >> n >> k;
    
    
    int psum[n+1];
    psum[0] = 0;
    vector<int> v;
    for(int i = 1; i <= n; i++ ) {
        int x;
        cin >> x;
        psum[i] = psum[i-1] + x;
        
    }
    
    int dp[n+1]; //i개 숫자의 합
    int big = 0; 
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = NEGINF;
        for(int j = i; j <= n ; j++) {
            dp[i] = max(dp[i], psum[j] - psum[j - i]);
            big = max(dp[i], big);
        }
        //cout << i << " : " << dp[i] << endl;
    }
    
    for(int i = n-1; i >= 0; i--) {
        dp[i] = max(dp[i], dp[i+1]);
    }
    
    int sdp[n+1];
    sdp[0] = big;
    cout << sdp[0] << " ";
    for(int i = 1; i <= n; i++) {
        sdp[i] = max(sdp[i-1], dp[i] + k*i); 
        cout << sdp[i] << " ";
    }
    cout << endl;
  }
}
