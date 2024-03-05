#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int bfs(vector<vector<int>>&g,vector<int>&lvl){
    queue<vector<int>> q;
    q.push({1,0,0});
    int ret=0;
    while(!q.empty()){
        int cur = q.front()[0];
        int level = q.front()[1];
        int par=q.front()[2];
        ret=max(ret,level);
        lvl[cur]=level;
        q.pop();
        for(auto e:g[cur]){
            if(e!=par){
                q.push({e,level+1,cur});
            }
        }
    }
    return ret;
}

void dfs(int cur,vector<int>&a,int n,vector<int>&p,vector<int>&lvl,int nr,vector<vector<int>>&g){
    if(lvl[cur]<nr) p[cur]=1;
    else if(!(lvl[cur]%nr)) p[cur]=a[cur];
    else p[cur]=p[a[cur]];

    for(auto e:g[cur]){
        if(e!=a[cur]){
            dfs(e,a,n,p,lvl,nr,g);
        }
    }
}

int query(int x,int k,vector<int>&a,int n,vector<int>&p,vector<int>&lvl,int nr,vector<vector<int>>&g){
    while(k && p[x]==p[a[x]]){
        if(x==1) return -1;
        k--;
        x=a[x];
    }
    if(k){
        if(x==1) return -1;
        k--;
        x=a[x];
    }
    while(k>nr){
        if(x==1) return -1;
        x=p[x];
        k-=nr;
    }
    while(k){
        if(x==1) return -1;
        k--;
        x=a[x];
    }
    return x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1,0);
    vector<vector<int>> g(n+1);
    for(int i=2; i<=n; i++){
        cin>>a[i];
        g[i].push_back(a[i]);
        g[a[i]].push_back(i);
    }
    vector<int>p(n+1,0),lvl(n+1,0);
    int height = bfs(g,lvl);
    int nr = sqrt(height);
    dfs(1,a,n,p,lvl,nr,g);

    for(int i=0; i<q; i++){
        int x,k;
        cin>>x>>k;
        cout<<query(x,k,a,n,p,lvl,nr,g)<<" ";
    }
    cout<<endl;

    

    return 0;
}