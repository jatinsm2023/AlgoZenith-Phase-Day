#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
pair<int,int> p[101];

double sq(double x){
    return x*x;
}

double cost(int x, int y){
    return sqrt(sq(p[x].first-p[y].first)+sq(p[x].second-p[y].second));
}

signed main(){
    cin>>n;
    for( int i=1; i<=n;i++){
        cin>>p[i].first>>p[i].second;
    }

    double dp[n+1][n+1];
    for( int len = 3; len<=n; len++){
        for( int l = 1; l+len-1<=n ;l++){
            int r  = l+len-1;
            if(len==3){
                return 0;
            }
            
        }
    }
    return 0;
}