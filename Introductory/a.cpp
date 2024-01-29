#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    for(int i=0; i<10; i++){
        int p=__builtin_ffs(i);
        cout<<p<<" ";
    }
    return 0;
}