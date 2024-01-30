#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(),a.end());
    int sind=0,send=n-1;
    while(sind<=send){
        if(a[sind].first+a[send].first==x) break; 
        else if(a[sind].first+a[send].first<x) sind++;
        else send--;
    }
    if(a[sind].first+a[send].first==x && sind!=send) cout<<a[sind].second<<" "<<a[send].second<<endl;
    else cout<<"IMPOSSIBLE\n";
    return 0;
}