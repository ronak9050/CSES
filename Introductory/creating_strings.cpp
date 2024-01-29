#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    set<string> st;
    string p=s;
    reverse(p.begin(),p.end());
    while(p!=s){
        st.insert(s);
        next_permutation(s.begin(),s.end());
    }
    st.insert(p);
    cout<<st.size()<<endl;
    for(auto e:st){
        cout<<e<<endl;
    }
    return 0;
}