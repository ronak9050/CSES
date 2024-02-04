#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>x>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    multiset<int> mst;
    set<pair<int,int>> st;
    st.insert({0,x});
    mst.insert(x);
    for(int i=0; i<n; i++){
        auto it = st.lower_bound(pair<int,int>(a[i],0));
        it--;
        int p=it->first,q=it->second;
        st.erase(it);
        st.insert({p,a[i]});
        st.insert({a[i],q});

        mst.insert(a[i]-p);
        mst.insert(q-a[i]);
        auto itt = mst.lower_bound(q-p);
        mst.erase(itt);
        
        auto itr = mst.end();
        itr--;
        cout<<*itr<<" ";
    }
    cout<<endl;

    return 0;
}