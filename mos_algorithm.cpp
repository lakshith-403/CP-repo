#include <bits/stdc++.h>

using namespace std;

void init();
void remove(int idx);  // TODO: remove value at idx from data structure
void add(int idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> MoSAlgorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    init();

    int cur_l = 0;
    int cur_r = -1;
    
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

int sum;
vector<int> a;

void init() {
    sum = 0;
}

void remove(int idx) {
    sum -= a[idx];
}

void add(int idx) {
    sum += a[idx];
}

int get_answer() {
    return sum;
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<Query> queries;

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;
        queries.push_back((Query){l, r, queries.size()});
    }

    vector<int> answers = MoSAlgorithm(queries);

    for (int ans: answers) {
        cout << ans << " ";
    }
    cout << "\n";
}