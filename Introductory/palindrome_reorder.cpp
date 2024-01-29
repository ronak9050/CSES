#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    string s;
    cin>>s;
    vector<int> ct(26,0);
    for(auto e:s) ct[e-'A']++;
    int ctodd=0;
    for(auto e:ct){
        if(e&1) ctodd++;
    }
    if(ctodd>1) cout<<"NO SOLUTION\n";
    else{
        string ans;
        char p='0';
        for(int i=0; i<26; i++){
            if(ct[i]&1) p=i+'A';
            else{
                for(int j=0; j<ct[i]/2; j++){
                    ans.push_back('A'+i);
                }
            }
        }
        string dd=ans;
        reverse(dd.begin(),dd.end());
        if(p!='0'){
            for(int j=0; j<ct[p-'A']; j++){
                ans.push_back(p);
            }
        }
        ans=ans+dd;
        cout<<ans<<endl;
    }
    return 0;
}