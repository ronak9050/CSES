#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    int n;
    cin>>n;
    int p=0;
    for(int i=1; i<=n; i++){
        p=p^i;
    }
    for(int i=0; i<n-1; i++){
        int q;
        cin>>q;
        p=q^p;
    }
    cout<<p<<endl;
    return 0;
}