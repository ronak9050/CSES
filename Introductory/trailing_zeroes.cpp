#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    ll n;
    cin>>n;
    ll p=5,ans=0;
    while(n/p){
        ans+=n/p;
        p=p*5;
    }
    cout<<ans<<endl;
    return 0;
}