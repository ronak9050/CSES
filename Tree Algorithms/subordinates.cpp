#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dfs(int i, vector<vector<int>>&g,vector<int>&ans){
    int ct=0;
    for(auto e:g[i]){
        ct+=dfs(e,g,ans);
    }
    return ans[i]=ct+g[i].size();
}

void solve(int n,vector<vector<int>>&g){

    vector<int> ans(n+1);
    dfs(1,g,ans);
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=2; i<=n; i++){
        int a;
        cin>>a;
        g[a].push_back(i);
    }
    solve(n,g);


    return 0;
}