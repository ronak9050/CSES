#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    vector<ll> x(n),psum(n,0);
    for(int i=0; i<n; i++) cin>>x[i];
    psum[0]=x[0];
    for(int i=1; i<n; i++) psum[i]=psum[i-1]+x[i];

    multiset<ll> st;
    for(int i=a-1; i<b; i++) st.insert(psum[i]);
    ll ans=INT64_MIN;
    for(int i=0; i<n; i++){
        if(st.empty()) break;
        auto it = st.end();
        it--;
        ans=max(ans,*it-psum[i]+x[i]);
        if(i+b<n) st.insert(psum[i+b]);
        if(i+a-1<n) st.erase(st.lower_bound(psum[i+a-1]));
    }
    cout<<ans<<endl;
    return 0;
}