#include <bits/stdc++.h>

using namespace std;

struct SqrtDecomp {
    int n;
    vector<int> a;
    vector<int> b;
    int len;

    SqrtDecomp(int n, vector<int> a) {
        this->n = n;
        this->a = a;
        len = (int) sqrt (n + .0) + 1;
        b.resize(len);

        for (int i=0; i<n; ++i) {
            b[i / len] += a[i];
        }
    }

    void update(int i, int val) {
        b[i/len] += val - a[i];
        a[i] = val;
    }

    int query(int l, int r) {
        int sum = 0;
        int c_l = l / len,   c_r = r / len;
        if (c_l == c_r)
            for (int i=l; i<=r; ++i)
                sum += a[i];
        else {
            for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
                sum += a[i];
            for (int i=c_l+1; i<=c_r-1; ++i)
                sum += b[i];
            for (int i=c_r*len; i<=r; ++i)
                sum += a[i];
        }
    }
};

struct SqrtDecompMin {
    int n;
    vector<int> a;
    vector<int> b;
    int len;

    SqrtDecompMin(int n, vector<int> a) {
        this->n = n;
        this->a = a;
        len = (int) sqrt (n + .0) + 1;
        b.resize(len);
        b.assign(len, INT_MAX);

        for (int i=0; i<n; ++i) {
            b[i / len] = min(b[i / len], a[i]);
        }
    }

    void update(int i, int val) {
        int index = i/len;
        b[index] = INT_MAX;
        a[i] = val;
        for (int j=index*len; j<(index+1)*len; j++) {
            b[index] = min(b[index], a[j]);
        }
    }

    int query(int l, int r) {
        int min_value = 0;
        int c_l = l / len,   c_r = r / len;
        if (c_l == c_r)
            for (int i=l; i<=r; ++i)
                min_value = min(min_value, a[i]);
        else {
            for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
                min_value = min(min_value, a[i]);
            for (int i=c_l+1; i<=c_r-1; ++i)
                min_value = min(min_value, b[i]);
            for (int i=c_r*len; i<=r; ++i)
                min_value = min(min_value, a[i]);
        }
    }
};

int main() {

}