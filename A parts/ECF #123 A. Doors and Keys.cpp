/*
ECF #123 A. Doors and Keys
Algorithm: Emplementation
Time Complexity: O(1)


*Editorial
for _ in range(int(input())):
	s = input()
	for (d, k) in zip("RGB", "rgb"):
		if s.find(d) < s.find(k):
			print("NO")
			break
	else:
		print("YES")


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
    int r, g, b;
    r = g = b = 0;
 
    int flag = 1;
    char c;
    for(int i = 0; i < 6 ;i++) {
        scanf("%1c", &c);
        
        if(c >= 'a') {
            if(c == 'r') r = 1;
            else if(c == 'g') g = 1;
            else b = 1;
        }
        else {
            if(c == 'R' && r == 0 || c == 'G' && g == 0 || c == 'B' && b == 0)
            {
                flag = 0; 
            }
        }
    }
    
    scanf("%1c", &c);
    
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
