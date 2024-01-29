#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    int ans=0;
    int ed=n-1;
    for(int i=0; i<n; i++){
        int rem=x-a[i];
        if(a[i]==1e9+1) break;
        if(rem<=0) ans+=(n-i);
        else{
            auto it=upper_bound(a.begin()+i+1,a.end(),rem);
            it--;
            // cout<<i<<" "<<a[i]<<" "<<*it<<endl;
            if(i==(it-a.begin())) ans++;
            else{
                // cout<<"else\n";
                for(;ed>=(it-a.begin()); ed--){
                    a[ed]=1e9+1;
                    ans++;
                }
            }

        }
    }

    
    // similar code 
    // int ind=n,ans=0;
    // vector<bool> vis(n,0);
    // for(int i=0; i<n; i++){
    //     if(vis[i]) continue;
    //     // cout<<a[i]<<" ";
    //     auto it = upper_bound(a.begin()+i,a.begin()+ind,x-a[i]);
    //     ans++;
    //     it--;
    //     if(it-a.begin()>i && *it+a[i]<=x) vis[it-a.begin()]=1;
    //     else it++;
    //     ind=it-a.begin();
    // }


    cout<<ans<<endl;

    

    return 0;
}