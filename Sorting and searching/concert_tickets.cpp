#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> t(m);
    multiset<int> st;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        st.insert(tmp);
    }
    for(int i=0; i<m; i++){
        cin>>t[i];
    }

    for(int i=0; i<m; i++){
        auto it=upper_bound(st.begin(),st.end(),t[i]);
        if(it==st.begin()) cout<<-1<<endl;
        else{
            it--;
            cout<<*it<<endl;
            st.erase(it);
        }
    }
    return 0;
}