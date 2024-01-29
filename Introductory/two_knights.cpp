#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    int n;
    cin>>n;
    for(ll i=1; i<=n; i++){
        ll ans=(i*i)*(i*i-1)/2;
        if(i>2){
            ans=ans-(4*(i-2))-(6*(i-2));
            if(i>=4) ans=ans-(4*(i-2)*(i-4))-i-(i-4);
        }
        if(i==3) ans=28; 
        cout<<ans<<endl;
    }
    return 0;
}