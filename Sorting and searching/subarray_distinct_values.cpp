#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    set<int> st;
    unordered_map<int,int> mp;
    int i=0,j=0;
    ll ans=0;
    while(j<n){
        if(i<n){
            if(st.size()<k){
                while(i<n && st.size()<k){
                    st.insert(a[i]);
                    mp[a[i]]++;
                    i++;
                }
                while(i<n && mp[a[i]]){
                    st.insert(a[i]);
                    mp[a[i]]++;
                    i++;
                }
            }
            else{
                ans=ans+(i-j);
                mp[a[j]]--;
                if(!mp[a[j]]) st.erase(a[j]);
                j++;
            }
        }
        else{
            mp[a[j]]--;
            if(!mp[a[j]]) st.erase(a[j]);
            ans=ans+(n-j);
            j++;
        }
    }
    cout<<ans<<endl;


    return 0;
}