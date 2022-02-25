/*
ECF #123 B. Anti-Fibonacci Permutation
Algorithim:  Brute Force, Constructive Algorithms
Time Complexity: O(n^2)
Explanation:

*내 방식
가장 큰 수를 제외한 숫자들을 내림차순으로 정리하고
사이사이에 가장 큰 수를 넣는다

다만, 홀수일 경우, 조건에 맞는 경우가 생길 수 있으니
스킵하고 마지막 1 과 2를 교체한 케이스를 하나 더 추가한다

3의 경우 위의 알고리즘이 적용 불가하니 그냥 예외처리한다

*Editorial
n n-1 n-2 n-3 .... 3 2 1
1 n n-1 n-2 ..... 4 3 2
2 n n-1 n-2 ..... 4 3 1
3 n n-1 n-2 ..... 4 2 1
.
.
.
.
n-1 n n-2 n-3 ....... 3 2 1

총 n개가 만들어진다
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
 
  while(T--) {
    int n; cin >> n;
    
    if(n == 3) {
        
        cout << "3 2 1" << endl;
        cout << "1 3 2" << endl;
        cout << "3 1 2" << endl;
        continue;
    }
    
    vector<int> v(n);
    
    for(int i = n-1; i > 0; i--) {
        v.push_back(i);    
    }
    
    for(int i = 0; i < n; i++) {
        if(n%2 == 1 && i == n/2 + 1) continue;
        
        int tmp = n-1;
        int j = 0;
        for(;j < i; j++) {
            cout << tmp << " ";
            tmp--;
        }
        
        cout << n << " ";
        
        for(;j < n-1; j++) {
            cout << tmp << " ";
            tmp--;
        }
        cout << endl;
    }
    if(n%2 == 1){
        for(int i = n; i > 2; i--) {
        cout << i << " ";
        }
        cout << 1 << " " << 2 << endl; 
    }
  }
}
