#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k=1;
    cin>>n;

    set<int>st;
    for(int i=0; i<n; i++){
        st.insert(i+1);
    }
    int k1=k%(st.size());
    auto it=st.begin();
    for(int i=0; i<n; i++){
        auto temp=it;
        for(int j=0; j<k1; j++){
            temp++;
            if(temp==st.end()){
                temp=st.begin();
                k1=k%(st.size());
            }
        }
        // for(auto e:st) cout<<e<<" ";
        // cout<<endl;
        cout<<*temp<<" ";
        it=temp;
        it++;
        if(it==st.end()) it=st.begin();
        st.erase(temp);
    }
    

    return 0;
}