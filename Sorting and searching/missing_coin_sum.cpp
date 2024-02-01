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
    ll sum=0,ans=1e15;
    for(int i=0; i<n; i++){
        if(sum+1<a[i]) ans=min(ans,sum+1);
        else{
            sum+=a[i];
        } 
    }
    if(ans!=1e15) cout<<ans<<endl;
    else cout<<sum+1<<endl;
    return 0;
}