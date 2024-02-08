#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n),psum(n,0);
    map<ll,ll> mp;
    for(int i=0; i<n; i++) cin>>a[i];
    psum[0]=a[0];
    mp[a[0]%n]++;
    for(int i=1; i<n; i++){
        psum[i]=psum[i-1]+a[i];
        mp[psum[i]%n]++;
    }

    ll ans=mp[0];

    for(int i=0; i<n; i++){
        mp[psum[i]%n]--;
        ans+=mp[psum[i]%n];
    }
    cout<<ans<<endl;
    return 0;
}