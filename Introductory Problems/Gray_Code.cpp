#include<bits/stdc++.h>
using namespace std;
//#define int long long

vector<string> Hamming(int n){
    if(n==1){
        return {"0","1"};
    }
    vector<string> ans;
    vector<string> prevHam=Hamming(n-1); 
    for(int i=0;i<prevHam.size();i++){
        ans.push_back("0"+prevHam[i]); //"0"+0, "0"+1
    }
    for(int i=prevHam.size()-1;i>=0;i--){
        ans.push_back("1"+prevHam[i]); //"1"+1,"1"+0
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<string> ans=Hamming(n);
    for(auto x:ans) cout<<x<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}