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
    ll med=a[n/2],ans=0;
    for(int i=0; i<n; i++){
        ans+=abs(a[i]-med);
    }
    cout<<ans<<endl;
    return 0;
}