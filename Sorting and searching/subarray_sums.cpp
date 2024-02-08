#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    ll sum=0,ans=0;
    int i=0,j=0;
    while(j<n){
        if(sum==x){
            ans++;
            // cout<<i<<" "<<j<<endl;
            sum+=a[j];
            j++;
        }
        else if(sum<x){
            sum+=a[j];
            j++;
        }
        else {
            sum-=a[i];
            // if(sum==x) ans++;
            i++;
        }
    }
    while(i<n){
        sum-=a[i];
        if(sum==x) ans++;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}