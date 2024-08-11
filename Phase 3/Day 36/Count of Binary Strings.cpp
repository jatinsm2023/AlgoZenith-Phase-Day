#include <bits/stdc++.h>
using namespace std;

// DP with DFA - COOL Write
int n;
const int mod = 1e9+7;
int dp[1000100][5];
int rec( int length, int state){
    if(length==n && state!=4){
        return 1;
    }
    if(length==n && state==4){
        return 0;
    }
    if(state==4){
        return 0;
    }
    if(dp[length][state]!=-1){
        return dp[length][state];
    }
    int ans = 0;
    if(state==0){
        ans = rec(length+1, 0) + rec(length+1,1);
    }
    if(state==1){
        ans = rec(length+1, 1) + rec(length+1, 2);
    }
    if(state==2){
        ans = rec(length+1, 3) + rec(length+1, 0);
    }
    if(state==3){
        ans = rec(length+1, 4) + rec(length+1, 2);
    }
    return dp[length][state] = ans%mod;
}
int main() {
    int t;
    cin>>t;
    memset(dp, -1, sizeof(dp));
    while(t--){
        cin>>n;
        cout<<rec(0,0)<<'\n';
    }
}
