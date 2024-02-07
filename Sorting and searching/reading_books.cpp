#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a.begin(),a.end());
    ll sum=0;
    for(int i=0; i<n; i++) sum+=a[i];

    if(sum-a[n-1]>=a[n-1]) cout<<sum<<endl;
    else cout<<2*1ll*a[n-1]<<endl;
    return 0;
}