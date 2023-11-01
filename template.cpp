#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define what_is(x) cout << #x << " is " << x << "\n"
#define check(a) cout << "check: " << a << "\n";
#define put(a) cout << a << "\n"; return;

#ifdef LOCAL
ifstream in("input.txt");
ofstream out("output.txt");
#define cin in
#define cout out
#else
#endif

 
inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

inline void print(int t, auto ans) {
  cout << "Case #" << t << ": " << ans << "\n";
}
 
void solve(int T){
}
 
int main(){
  io_setup();
  int t;
  cin >> t;
  for (int i=1; i<=t; i++)
    solve(i);
}
 
/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
