#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,t;
    cin>>n>>t;
    vector<ll>a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());

    ll l=0,h=t*a[0];
    while(l<h){
        ll mid=(l+h)/2;
        ll ct=0;
        for(int i=0; i<n; i++) ct+=mid/a[i];

        if(ct>=t) h=mid;
        else l=mid+1;
    }
    cout<<h<<endl;

    return 0;
}