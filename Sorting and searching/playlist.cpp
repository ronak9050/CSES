#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1,-1);
    map<int,int> mp;
    int ans=1;
    for(int i=1; i<n+1; i++) {
        cin>>a[i];
    }
    mp[a[n]]=n;
    b[n]=n+1;
    for(int i=n-1; i>0; i--){
        if(mp[a[i]])  b[i]=min(b[i+1],mp[a[i]]);
        else b[i]=b[i+1];
        ans=max(ans,b[i]-i);
        mp[a[i]]=i;
    }
    cout<<ans<<endl;

    

    return 0;
}