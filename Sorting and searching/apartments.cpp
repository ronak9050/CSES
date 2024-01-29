#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n),b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int ans=0;
    int bg=0;
    for(int i=0; i<n; i++){
        int p=a[i]-k;
        if(p<0) p=0;
        auto it=lower_bound(b.begin(),b.end(),p);
        if(it==b.end()) break;
        else{
            if(*it>a[i]+k) continue;
            else{
                ans++;
                for(;bg<=(it-b.begin()); bg++){
                    b[bg]=-1;
                }
            }
        }
    }

    // 2nd approach
//     int ind=0,ans=0;
//     for(int i=0; i<m; i++){
//         auto it = lower_bound(a.begin()+ind,a.end(),b[i]-k);
//         ind = it-a.begin();
//         if(*it>=b[i]-k && *it<=b[i]+k){
//             ind++;
//             ans++;
//         }
//     }

    cout<<ans<<endl;


    return 0;
}

