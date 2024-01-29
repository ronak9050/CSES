#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int p=1,ans=1;
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1]) p++;
        else{
            ans=max(ans,p);
            p=1;
        }
    }
    ans=max(ans,p);
    cout<<ans<<endl;
    return 0;
}