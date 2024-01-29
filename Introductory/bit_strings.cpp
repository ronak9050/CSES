#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll M=1e9+7;

ll power(ll a,ll b){
    if(b==0) return 1;
    ll p=power(a,b/2);
    if(b&1) return ((p*p)%M*a)%M;
    return (p*p)%M;
}

int main(){
    ll n;
    cin>>n;
    cout<<power(2,n)<<endl;
    return 0;
}