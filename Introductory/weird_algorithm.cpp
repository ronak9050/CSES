#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n;
    cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n&1) n=3*n+1;
        else n=n/2;
    }
    cout<<1<<endl;
    return 0;
}