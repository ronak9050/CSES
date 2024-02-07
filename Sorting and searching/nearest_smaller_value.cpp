#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<int> a(n),ans(n,0);
    for(int i=0; i<n; i++) cin>>a[i];

    stack<int> st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && a[st.top()]>a[i]){
            ans[st.top()]=i+1;
            st.pop();
        }
        st.push(i);
    }

    for(auto e:ans) cout<<e<<" ";
    cout<<endl;
    return 0;
}