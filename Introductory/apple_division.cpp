#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll func(int i,vector<ll> &p,ll sum,ll allsum){
    int n=p.size();
    if(i==n) {
        ll a=sum,b=allsum-sum;
        return abs(a-b);
    }
    return min(func(i+1,p,sum,allsum),func(i+1,p,sum+p[i],allsum));
}

int main(){
    int n;
    cin>>n;
    vector<ll> p(n);
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    ll allsum=0;
    for(auto e:p) allsum+=e;
    cout<<func(0,p,0,allsum)<<endl;
    return 0;
}