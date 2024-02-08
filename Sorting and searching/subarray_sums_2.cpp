#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n,0),psum(n,0);
    map<ll,ll> mp;

    for(int i=0; i<n; i++) cin>>a[i];
    psum[0]=a[0];
    mp[a[0]]++;
    for(int i=1; i<n; i++){
        psum[i]=psum[i-1]+a[i];
        mp[psum[i]]++;
    }

    ll ans=mp[x];

    for(int i=0; i<n; i++){
        mp[psum[i]]--;
        ans+=mp[psum[i]+x];
    }

    cout<<ans<<endl;
    
    return 0;
}