#include<bits/stdc++.h>
using namespace std;
//#define int long long

// void solve(){ //T.C:-O(t*root(n))
//     int n;
//     cin>>n;
//     vector<int> v;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0) {
//             v.push_back(i);
//             if(i!=(n/i)) v.push_back(n/i);
//         }
        
//     }
//     cout<<(v.size())<<"\n";
// }

const int maxN=1e6;
vector<int> max_div(maxN+1); // max_div[i] contains the largest prime that goes into i

void solve(){
    int n;
    cin>>n;

    // n can have log(n) distinct prime factors
    int count_div=1;
    while(n!=1){ // T.C:- O(log n)
        int prime=max_div[n];
        int count=0;
        /*
		* get the largest prime that can divide x and see
		* how many times it goes into x (stored in count)
		*/
        while(n%prime==0){
            count++;
            n/=prime;
        }
        count_div*=(count+1);
    }
    cout<<count_div<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=2;i<=maxN;i++){ // O(maxN log(maxN) ) :- Preprocessing
        if(max_div[i]==0){
            for(int j=i;j<=maxN;j+=i) max_div[j]=i;
        }
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}