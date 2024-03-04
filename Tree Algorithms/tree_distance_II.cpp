#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int cur,int par,vector<vector<int>>&g,vector<ll>&ans,vector<int>&childct){
    for(auto e:g[cur]){
        if(e!=par){
            dfs(e,cur,g,ans,childct);
            childct[cur]+=1+childct[e];
            ans[cur]+=ans[e]+1+childct[e];
        }
    }
}

void dfs2(int cur,int par,vector<vector<int>>&g,vector<ll>&ans,vector<int>&childct){
    int n=ans.size()-1;
    ll rempar = (ans[par]-ans[cur]-1-childct[cur]);
    ans[cur]=ans[cur]+rempar+(n-childct[cur]-1);
    for(auto e:g[cur]){
        if(e!=par){
            dfs2(e,cur,g,ans,childct);
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> ans(n+1,0);
    vector<int> childct(n+1,0);
    dfs(1,0,g,ans,childct);
    for(auto e:g[1]){
        dfs2(e,1,g,ans,childct);
    }
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}