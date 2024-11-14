#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(int mid, vector<int> &a, int t){
    //can we produce t products in mid seconds?
    int total_product=0;
    for(int i=0;i<a.size();i++){
        total_product+=mid/a[i];
    }
    return (total_product>=t);
}

void solve(){
    int n,t;
    cin>>n>>t;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int lo=0,hi=t*(*min_element(a.begin(),a.end())),ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,a,t)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<"\n";
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