#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> bfs(int st,vector<vector<int>>&g){
    queue<vector<int>>q;
    q.push({st,0,0});
    int level,last;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int cur=it[0],lvl=it[2],par=it[1];
        level=lvl;
        last=cur;
        for(auto e:g[cur]){
            if(e!=par){
                q.push({e,cur,lvl+1});
            }
        }
    }
    return {last,level};
}

// int dfs(int cur,int par,vector<vector<int>>&g,vector<int>&ans,int maxlvl){
//     int ct=0;
//     for(auto e:g[cur]){
//         if(e!=par){
//             ct=max(ct,1+dfs(e,cur,g,ans,maxlvl));
//         }
//     }
//     ans[cur]=max(maxlvl-ct,ct);
//     return ct;
// }


void bfs2(int st,vector<vector<int>>&g,vector<int>&ans,int maxlvl){
    queue<vector<int>>q;
    q.push({st,0,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int cur=it[0],lvl=it[2],par=it[1];
        ans[cur]=max(ans[cur],lvl);
        for(auto e:g[cur]){
            if(e!=par){
                q.push({e,cur,lvl+1});
            }
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
    vector<int> ans(n+1,0);
    auto it1 = bfs(1,g);
    int st=it1[0];
    auto it2 = bfs(st,g);
    int mxlvl=it2[1],last=it2[0];

    // dfs(st,0,g,ans,mxlvl);
    bfs2(st,g,ans,mxlvl);
    bfs2(last,g,ans,mxlvl);

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}