#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    int n;
    cin>>n;
    ll c,p=0,ans=0;
    for(int i=0; i<n; i++){
        cin>>c;
        if(c<p) ans+=(p-c);
        p=max(p,c);
    }
    cout<<ans<<endl;
    return 0;
}