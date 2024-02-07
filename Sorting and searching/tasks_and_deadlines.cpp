#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll> a(n),d(n);
    for(int i=0; i<n; i++) cin>>a[i]>>d[i];
    ll sum=0;
    for(int i=0; i<n; i++) sum+=d[i];
    sort(a.begin(),a.end());
    ll sub=0,sum2=0;
    for(int i=0; i<n; i++){
        sum2+=a[i];
        sub+=sum2;
    }
    cout<<sum-sub<<endl;

    return 0;
}