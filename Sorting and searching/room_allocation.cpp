// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// bool comp(vector<int>&a,vector<int>&b){
//     if(a[1]==b[1]) return a[0]<b[0];
//     return a[1]<b[1];
// }


// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin>>n;
//     vector<vector<int>> a(n),b(n);
//     for(int i=0; i<n; i++){
//         int p,q;
//         cin>>p>>q;
//         a[i]={p,q,i};
//         b[i]=a[i];
//     }
    
//     sort(a.begin(),a.end());
//     priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
//     int ans=0,ct=0;
//     vector<int> seq;
//     for(int i=0; i<n; i++){
//         pq.push({a[i][1],a[i][0],a[i][2]});
//         while(!pq.empty() && pq.top().at(0)<a[i][0]){
//             seq.push_back(pq.top().at(2));
//             pq.pop();
//         }
//         ans=max(ans,int(pq.size()));
//     }
//     while(!pq.empty()){
//         seq.push_back(pq.top().at(2));
//         pq.pop();
//     }

//     cout<<ans<<endl;
//     vector<int> ret(n,0);

//     for(int i=0; i<n; i++){
//         ret[seq[i]]=ct+1;
//         ct=(ct+1)%ans;
//     }

//     for(auto e:ret) cout<<e<<" ";
//     cout<<endl;

//     return 0;
// }



#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 2e5;

int N;
int ans[MAX_N];
vector<pair<pair<int, int>, int>> v(MAX_N);

int main() {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i;  // store the original index
	}
	sort(v.begin(), v.end());

	int rooms = 0, last_room = 0;
	priority_queue<pair<int, int>> pq;  // min heap to store departure times.
	for (int i = 0; i < N; i++) {
		if (pq.empty()) {
			last_room++;
			// make the departure time negative so that we create a min heap
			// (cleanest way to do a min heap... default is max in c++)
			pq.push(make_pair(-v[i].first.second, last_room));
			ans[v[i].second] = last_room;
		} else {
			// accessing the minimum departure time
			pair<int, int> minimum = pq.top();
			if (-minimum.first < v[i].first.first) {
				pq.pop();
				pq.push(make_pair(-v[i].first.second, minimum.second));
				ans[v[i].second] = minimum.second;
			}

			else {
				last_room++;
				pq.push(make_pair(-v[i].first.second, last_room));
				ans[v[i].second] = last_room;
			}
		}

		rooms = max(rooms, int(pq.size()));
	}

	cout << rooms << "\n";
	for (int i = 0; i < N; i++) { cout << ans[i] << " "; }
}


