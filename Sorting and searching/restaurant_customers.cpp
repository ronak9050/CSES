#include<bits/stdc++.h>
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

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
    ordered_multiset st;

    int ans=0,cur=0,ind=0;
    for(int i=n-1; i>=0; i--){
        if(st.size()) cur = st.find_by_order(st.lower_bound(a[i].second));
        ans=max(ans,cur);
        st.insert(a[i].first);
    }
    cout<<ans<<endl;

    return 0;
}