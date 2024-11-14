#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(int mid, vector<int> &a, int k){
    int sum=0;
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>mid) return false;
        if(sum+a[i]>mid){
            cnt++;
            sum=0;
        }
        sum+=a[i];
    }
    if(sum>0) cnt++;
    return (cnt<=k);
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    int lo=0,hi=sum,ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,a,k)){
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