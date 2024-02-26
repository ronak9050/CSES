#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll func(int i,int x,vector<int>&a,vector<ll>&dp){
    if(i>=a.size()) return 1e6+1;
    if(x==0) return 0;
    if(dp[x]!=-1) return dp[x];
    ll ans=1e6+1;
    if(x-a[i]>=0) ans=1+func(i,x-a[i],a,dp);
    ans=min(ans,func(i+1,x,a,dp));
    return dp[x]=ans;
}

int solve(int n,int x,vector<int>&a){
    vector<ll> dp(x+1,-1);
    func(0,x,a,dp);
    if(dp[x]>1e6) return -1;
    return int(dp[x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<solve(n,x,a)<<endl;
    return 0;
}