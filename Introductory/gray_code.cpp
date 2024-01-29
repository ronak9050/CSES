// #include <bits/stdc++.h>

// using namespace std;
// const int maxN = 16;

// int N;
// bool b[maxN+1];

// void print(){
//     for(int i = N; i > 0; i--)
//         printf("%d", b[i]);
//     printf("\n");
// }

// int main(){
//     scanf("%d", &N);

//     print();
//     for(int i = 1; i < (1<<N); i++){
//         int LSB = __builtin_ffs(i);
//         b[LSB] ^= 1;
//         print();
//     }
// }



#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(int n){
    for(int i=0; i<(1<<n); i++){
        int p=i^(i>>1);
        bitset<32> a(p);
        string ans=a.to_string();
        for(int j=32-n; j<32; j++){
            cout<<ans[j];
        }
        cout<<endl;
    }
}


int main(){
    int n;
    cin>>n;
    solve(n);
    return 0;
}

