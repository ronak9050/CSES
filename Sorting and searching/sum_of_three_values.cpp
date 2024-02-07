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

    // int i=0,j=n-1,flag=0;
    // while(i<j){
    //     ll rsum = x-a[i].first-a[j].first;
    //     if(rsum<=0) j--;
    //     else{
    //         auto it = lower_bound(a.begin()+i+1,a.begin()+j,pair<ll,int>(rsum,0));
    //         if(it==a.begin()+j) i++;
    //         else{
    //             if(a[i].first+a[j].first+it->first==x){
    //                 set<int> st;
    //                 st.insert(a[i].second);
    //                 st.insert(a[j].second);
    //                 st.insert(it->second);
    //                 if(st.size()==3){
    //                     for(auto e:st) cout<<e+1<<" ";
    //                     cout<<endl;
    //                     flag=1;
    //                     break;
    //                 }
    //             }
    //             else 
    //         }
    //     }
    // }
    // if(!flag) cout<<"IMPOSSIBLE\n";
    vector<int> ans;
    for(int i=0; i<n; i++){
        int j=i+1,k=n-1,flag=0;
        while(j<n && j<k){
            ll sum=a[i].first+a[j].first+a[k].first;
            if(sum==x){
                ans.push_back(a[i].second);
                ans.push_back(a[j].second);
                ans.push_back(a[k].second);
                flag=1;
                break;
            }
            else if(sum<x) j++;
            else k--;
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