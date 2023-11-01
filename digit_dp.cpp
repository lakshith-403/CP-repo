#include <bits/stdc++.h>

using namespace std;

const int MAXN = 18;
const int MAX_SUM = 9*MAXN;


long long solve(long long a, int k) {
    string a_string = to_string(a);
    int n = a_string.size();

    long long dp[n][k+1][2];
    memset(dp, 0, sizeof(dp));

    for (int i=0; i<n-1; i++) {
        for (int sum=0; sum<=k; sum++) {
            for (int f=0; f<=1; f++) {
                
                for (int j=0; j<=(f?9:(a_string[i+1]-'0')); j++) {
                    if (sum + j <= k) // filtering out unwanted states
                        dp[i+1][sum+j][f || j<(a_string[i+1]-'0')] += dp[i][sum][f];
                }

            }
        }
    }

    return dp[n-1][k][0] + dp[n-1][k][1];
}

int main() {

}