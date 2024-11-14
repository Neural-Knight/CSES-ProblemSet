#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<"\n";
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t=1;
// 	cin>>t;
	while(t--) {
		solve();
	}
}