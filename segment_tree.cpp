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
    int point_query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return point_query(v*2, tl, tm, l, min(r, tm))
           + point_query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void point_update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                point_update(v*2, tl, tm, pos, new_val);
            } else {
                point_update(v*2+1, tm+1, tr, pos, new_val);
            }
            t[v] = t[v*2] + t[v*2+1];
        }
    }
};

int main() {

}