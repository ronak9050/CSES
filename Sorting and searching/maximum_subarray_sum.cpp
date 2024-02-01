#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    ll a;
    ll ans=-1e9,sum=0;
    for(int i=0; i<n; i++){
        cin>>a;
        sum+=a;
        ans=max(ans,sum);
        if(sum<0) sum=0;
    }
    cout<<ans<<endl;
    return 0;
}