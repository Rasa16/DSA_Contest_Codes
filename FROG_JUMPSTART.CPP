#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long INF = 1e18;   
    long long N, C;
    cin>>N>>C;
    vector<long long> v;
    for(int i = 0; i<N; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
        
    vector<long long> dp(N+1, INF);

    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i<=N; i++){
        for(int j = 1; j<i; j++){
            long long t = v[i-1]-v[j-1];
            t = t*t + dp[j] + C;
            dp[i] = min(dp[i], t);
        }
    }
    
    cout<<dp[N];
    return 0;
}
