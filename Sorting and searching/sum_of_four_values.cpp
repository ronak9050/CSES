#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    vector<pair<ll,int>> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    vector<int> ans;
    int flag=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int k=j+1,l=n-1;
            while(k<l){
                ll sum=a[i].first+a[j].first+a[k].first+a[l].first;
                if(sum==x){
                    ans.push_back(a[i].second);
                    ans.push_back(a[j].second);
                    ans.push_back(a[k].second);
                    ans.push_back(a[l].second);
                    flag=1;
                    break;
                }
                else if(sum<x) k++;
                else l--;
            }
            if(flag) break;
        }
        if(flag) break;
    }

    if(ans.empty()) cout<<"IMPOSSIBLE\n";
    else {
        sort(ans.begin(),ans.end());
        for(auto e:ans) cout<<e+1<<" ";
        cout<<endl;
    }

    return 0;
}