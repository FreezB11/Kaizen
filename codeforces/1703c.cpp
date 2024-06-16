#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define what(x) cout << (#x) << ": " << x << '\n';
#define da cout << "-------------------------\n";
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int M = 1e6 + 10;
const int mod = 1e9 + 7;
const int oo = 2e18;
int T = 1, n, m, x, y, z, l, r, k;
int a[ M ], b[ M ], ans, sum, cnt;
bool yes, no, first;
string s, s1, s2;
 
main()
{
//      FAST
      cin >> T;
      while(T--)
      {
            cin >> n;
            for(int i = 1 ; i <= n ; i++) cin >> a[ i ];
 
            for(int i = 1 ; i <= n ; i++)
            {
                  cin >> x >> s;
                  cnt = 0;
                  for(int i = 0 ; i < x ; i++)
                        cnt += (s[ i ] == 'U' ? -1 : 1);
 
                  a[ i ] = (a[ i ] + 20 + cnt) % 10;
            }
 
            for(int i = 1 ; i <= n ; i++)
                  cout << a[ i ] << ' ';
                  cout << endl;
      }
}
/*
3
9 3 1
3 DDD
4 UDUU
2 DU
3 1 1
*/