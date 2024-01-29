#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int mn=min(a,b),mx=max(a,b);
        if(mn*2<mx) cout<<"NO\n";
        else{
            if((mn%3==0 && mx%3==0)) cout<<"YES\n";
            else if((mn%3==0 || mx%3==0)) cout<<"NO\n";
            else if(mn%3!=mx%3) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}