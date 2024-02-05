// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n,k;
//     cin>>n>>k;

//     set<int>st;
//     for(int i=0; i<n; i++){
//         st.insert(i+1);
//     }
//     int k1=k%(st.size());
//     auto it=st.begin();
//     for(int i=0; i<n; i++){
//         auto temp=it;
//         k1=k%(st.size());

//         for(int j=0; j<k1; j++){
//             temp++;
//             if(temp==st.end()){
//                 temp=st.begin();
//             }
//         }

//         // for(auto e:st) cout<<e<<" ";
//         // cout<<endl;
//         cout<<*temp<<" ";
        
//         it=temp;
//         it++;
//         if(it==st.end()) it=st.begin();
//         st.erase(temp);
//     }
    

//     return 0;
// }


// same can be done with use of ordered_set ---> of associate container


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int N, K, idx;
tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
        T.insert(i);

    idx = K;
    while(T.size()){
        idx %= T.size();
        int x = *T.find_by_order(idx);
        T.erase(x);
        printf("%d%c", x, (" \n")[T.size() == 0]);
        idx += K;
    }
}


