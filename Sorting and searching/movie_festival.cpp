#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end());
    vector<int> ans(n+1,0);
    for(int i=n-1; i>=0; i--){
        auto it = lower_bound(a.begin()+i,a.end(),pair<int,int>(a[i].second,0));
        if(it!=a.end()){
            int ind = it-a.begin();
            ans[i] = max(ans[i+1],1+ans[ind]);
        }
        else ans[i] = max(ans[i+1],1);
    }
    cout<<*max_element(ans.begin(),ans.end())<<endl;


    return 0;
}