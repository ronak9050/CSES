#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    ll n;
    cin>>n;
    if((n*(n+1)/2) &1) cout<<"NO\n";
    else{
        cout<<"YES\n";
        ll ans=n*(n+1)/4;
        ll i=n;
        vector<ll> a,b,c(n+1,0);
        while(ans){
            if(ans-i>=0){
                ans-=i;
                a.push_back(i);
                c[i]=1;
                i--;
            }
            else{
                a.push_back(ans);
                c[ans]=1;
                ans=0;
            }
        }
        for(i=1; i<=n; i++){
            if(!c[i]) b.push_back(i);
        }
        cout<<a.size()<<endl;
        for(auto e:a) cout<<e<<" ";
        cout<<endl;
        cout<<b.size()<<endl;
        for(auto e:b) cout<<e<<" ";
    }
    return 0;
}