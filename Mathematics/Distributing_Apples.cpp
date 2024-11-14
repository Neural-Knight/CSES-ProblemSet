#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const int N = 1e6;
ll power(ll a , ll n){
      ll res = 1;
      while(n){
            if(n & 1) res = (res * a) % mod;
            n >>= 1;
            a = (a * a) % mod;
}
    return res;
}
ll fact(ll n){
    ll res=1;
    for(ll i=1;i<=n;i++){
        res=(res*i)%mod;
    }
    return res;
}
ll ModInv(ll n){
    return power(n,mod-2);
}
ll C(ll n , ll r){
    if(n < r) return 0;
    ll result = fact(n);
    result=(result*ModInv(fact(r)))%mod;
    result=(result * ModInv(fact(n-r))) % mod;
    return result;
}
void solve() {
    ll n,m;
    cin>>n>>m;
    cout<<C(n+m-1,m)%mod<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}