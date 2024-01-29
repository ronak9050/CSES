#include<bits/stdc++.h>
using namespace std;
#define ll long long int

multiset<int> st;
int n,m,h,t;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>h;
        st.insert(-h);
    }
    for(int i=0; i<m; i++) {
        cin>>t;
        // it gives TLE while using auto it = lower_bound(st.begin(),st.end(),-t)
        if(st.lower_bound(-t)==st.end()) cout<<-1<<endl;
        else{
            cout<<-*st.lower_bound(-t)<<endl;
            st.erase(st.lower_bound(-t));
        }
    }


    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int N, M, h, t;
// multiset<int> prices;

// int main(){
//     scanf("%d %d", &N, &M);
//     for(int i = 0; i < N; i++){
//         scanf("%d", &h);
//         prices.insert(-h);
//     }
//     for(int i = 0; i < M; i++){
//         scanf("%d", &t);
//         if(prices.lower_bound(-t) == prices.end())
//             printf("-1\n");
//         else {
//             printf("%d\n", -(*prices.lower_bound(-t)));
//             prices.erase(prices.lower_bound(-t));
//         }
//     }
// }