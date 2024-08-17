#include <bits/stdc++.h>
using namespace std;

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        stack<int> a,b;
        // a - real , b - for push
        for(int i=0; i<n;i++){
            string s;
            cin>>s;
            if(s=="push"){
                int x;
                cin>>x;
                a.push(x);
            }else if(s=="pop"){
                if(!b.empty()){
                    cout<<b.top()<<'\n';
                    b.pop();
                }else{
                    while(!a.empty()){
                        b.push(a.top());
                        a.pop();
                    }
                    cout<<b.top()<<'\n';
                    b.pop();
                }
            }
            else if(s=="front"){
                if(!b.empty()){
                    cout<<b.top()<<'\n';
                    // b.pop();
                }else{
                    while(!a.empty()){
                        b.push(a.top());
                        a.pop();
                    }
                    cout<<b.top()<<'\n';
                    // b.pop();
                }
            }
        }
    }
}