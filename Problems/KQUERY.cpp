/**
 * Merge Sort Tree
 * https://www.spoj.com/problems/KQUERY/
*/

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

const int MAXN = 1e5;
const int INF = INT_MAX/10;

struct MergeSortTree {
    int n;
    vector<int> t[4*MAXN];

    MergeSortTree(vector<int> a) {
        this->n = a.size();
    }

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = vector<int>(1, a[tl]);
        } else { 
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
                back_inserter(t[v]));
        }
    }

    int query(int v, int tl, int tr, int l, int r, int x) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            vector<int>::iterator pos = upper_bound(t[v].begin(), t[v].end(), x);
            if (pos != t[v].end())
                return t[v].size() - (pos-t[v].begin());
            return 0;
        }
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm), x) +
                query(v*2+1, tm+1, tr, max(l, tm+1), r, x);
    }
};
 
void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    MergeSortTree* st = new MergeSortTree(a);
    st->build(a, 1, 0, n-1);

    int q;
    cin >> q;
    while (q--) {
        int i,j,k;
        cin >> i >> j >> k;
        i--,j--;
        int ans = st->query(1, 0, n-1, i, j, k);
        cout << ans << "\n";
    }
}
 
int main(){
  io_setup();
  solve();
}
 
/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
