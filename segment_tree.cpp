#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    int n;
    vector<int> t;

    SegmentTree(vector<int> a) {
        this->n = a.size();
        this->t.resize(4*n);
    }

    // call with build(a, 1, 0, n-1)
    void build(vector<int>& a, int v, int tr, int tl) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    // tl tr to keep track of tree vertices
    // l r to keep track of query
    int getAns(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return getAns(v*2, tl, tm, l, min(r, tm))
           + getAns(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
};

int main() {

}