#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll power(int a,int b){
    ll ans=1;
    for(int i=0; i<b; i++){
        ans=ans*1ll*a;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        ll p=0,inc=9;
        int ct=1;
        while(inc*ct<k){
            k=k-inc*ct;
            inc=inc*10;
            ct++;
        }
        ll adder=k/ct;
        if(k%ct==0) adder--;
        ll num=power(10,ct-1)+adder;
        ll digit=k%ct;
        string ss=to_string(num);
        if(digit==0) cout<<ss[ss.size()-1]<<endl;
        else{
            cout<<ss[digit-1]<<endl;
        }
    }
    return 0;
}