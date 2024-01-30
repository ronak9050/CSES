#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end(),cmp);
    priority_queue<int> pq;

    int ans=0,cur=0,ind=0;
    for(int i=n-1; i>=0; i--){
        while(pq.size() && pq.top()>a[i].second) pq.pop();
        cur = pq.size()+1;
        ans=max(ans,cur);
        pq.push(a[i].first);
    }
    cout<<ans<<endl;

    return 0;
}