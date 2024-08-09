#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int dir = 0;
        int u=0;
        int r=0;
        for( int i=0; i<n; i++)
        {
            if(s[i]=='L'){
                dir = (dir+3)%4;
            }
            else if(s[i]=='R'){
                dir = (dir+1)%4;
            }else {
                if(dir==0){
                    u++;
                }
                else if(dir==1){
                    r++;
                }
                else if(dir==2){
                    u--;
                }
                else r--;
            }
        }
        if(r==0 && u==0){
            cout<<"YES"<<'\n'; 
        }
        else if(dir==0){
            cout<<"NO"<<'\n';
        }
        else cout<<"YES"<<'\n';
    }
}