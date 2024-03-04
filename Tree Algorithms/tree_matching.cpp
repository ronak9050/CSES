#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// int dfs(int par,int cur,vector<int>&vis,vector<vector<int>>&g){
//     int ans=0;
//     for(auto e:g[cur]){
//         if(e!=par){
//             ans+=dfs(cur,e,vis,g);
//             if(!vis[e]&&!vis[cur]){
//                 vis[e]=vis[cur]=1;
//                 ans++;
//             }
//         }
//     }
//     return ans;
    
// }

int takingone(int cur,int par,vector<vector<int>>&g,vector<int>&dp0,vector<int>&dp1);

int notaking(int cur,int par,vector<vector<int>>&g,vector<int>&dp0,vector<int>&dp1){
    if(dp0[cur]!=-1) return dp0[cur];
    int ans=0;
    for(auto e:g[cur]){
        if(e!=par){
            ans+=max(notaking(e,cur,g,dp0,dp1),takingone(e,cur,g,dp0,dp1));
        }
    }
    return dp0[cur]=ans;
}

int takingone(int cur,int par,vector<vector<int>>&g,vector<int>&dp0,vector<int>&dp1){
    if(dp1[cur]!=-1) return dp1[cur];
    int ans=0;
    for(auto e:g[cur]){
        if(e!=par){
            ans=max(ans,notaking(e,cur,g,dp0,dp1)+1+notaking(cur,par,g,dp0,dp1)-max(takingone(e,cur,g,dp0,dp1),notaking(e,cur,g,dp0,dp1)));
        }
    }
    return dp1[cur]=ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> g(n+1);
    vector<int> vis(n+1,0);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // cout<<dfs(0,1,vis,g)<<endl;
    vector<int> dp1(n+1,-1);
    vector<int> dp0(n+1,-1);
    cout<<max(notaking(1,0,g,dp0,dp1),takingone(1,0,g,dp0,dp1))<<endl;
    
    return 0;
}