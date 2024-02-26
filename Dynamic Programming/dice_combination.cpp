#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll m=1e9+7;


// optimized
int solve(int n){
    vector<ll> dp(6,0);
    dp[5]=1;
    for(int i=1; i<=n; i++){
        ll sum=0;
        for(int j=0; j<6; j++) sum+=dp[j];
        ll prev=0;
        for(int j=5; j>=0; j--){
            prev=dp[j];
            dp[j]=sum%m;
            sum=prev;
        }

    }
    return dp[5];
}

// tabular
int solve2(int n){
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(i-j>=0) dp[i]+=dp[i-j];
        }
        dp[i]=dp[i]%m;
    }
    return dp[n];
}

// top down
int solve3(int n,vector<ll>&dp){
    if(n<0) return 0;
    else if(n==0) return 1;
    else if(dp[n]!=-1) return dp[n];
    ll sum=0;
    for(int i=1; i<=6; i++) sum+=solve3(n-i,dp);
    return dp[n]=(sum%m);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll> dp(n+1,-1);
    cout<<solve3(n,dp)<<endl;
    // for(auto e:dp) cout<<e<<" ";
    // cout<<solve2(n)<<endl;
    // cout<<solve(n)<<endl;
    return 0;
}