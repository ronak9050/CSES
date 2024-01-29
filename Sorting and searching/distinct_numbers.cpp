#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    set<int> st;
    for(int i=0; i<n; i++){
        int p;
        cin>>p;
        st.insert(p);
    }
    cout<<st.size()<<endl;
    return 0;
}