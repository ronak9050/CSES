#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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
    queue<int> q;
    vector<int> vis(n+1,0),vis2(n+1,0);
    q.push(1);
    int last=1;
    while(!q.empty()){
        int cur=q.front();
        last=cur;
        vis[cur]=1;
        q.pop();
        for(auto e:g[cur]){
            if(!vis[e]) q.push(e);
        }
    }

    queue<pair<int,int>> q1;
    int level=0;
    q1.push({last,0});
    while(!q1.empty()){
        int cur=q1.front().first;
        int lvl=q1.front().second;
        vis2[cur]=1;
        level=lvl;
        q1.pop();
        for(auto e:g[cur]){
            if(!vis2[e]) q1.push({e,lvl+1});
        }
    }

    cout<<level<<endl;


    return 0;
}