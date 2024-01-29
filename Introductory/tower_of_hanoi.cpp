#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(int src,int dest,int aux,int n){
    if(n<=0) return;
    solve(src,aux,dest,n-1);
    cout<<src<<" "<<dest<<endl;
    solve(aux,dest,src,n-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int p=(1<<n)-1;
    cout<<p<<endl;
    solve(1,3,2,n);
    
    return 0;
}