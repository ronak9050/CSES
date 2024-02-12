#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    ll sum=0,mx=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        sum+=a[i];
    }
    
    ll tp = (ceil(float(sum/k)));
    mx = max(mx,tp);
    ll cursum=0;
    for(int i=0; i<k; i++){
        
    }
    return 0;
}