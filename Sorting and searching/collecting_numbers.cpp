#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n),b(n+1,0);
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[a[i]]=i;
    }
    int ans=1;
    for(int i=2; i<=n; i++){
        if(b[i]<b[i-1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}