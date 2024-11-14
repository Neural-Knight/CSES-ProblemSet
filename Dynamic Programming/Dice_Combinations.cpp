#include<iostream>
using namespace std;

//Memoization
int numberofWays(int n, long long* dp){
    int mod=1e9+7;
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return (dp[n]%mod);
    dp[n]=0;
    for(int i=1;i<=6;i++){
        dp[n]+=(numberofWays(n-i,dp)%mod);
    }
    return (dp[n]%mod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    long long dp[n+1];
    for(int i=0;i<n+1;i++) dp[i]=-1;
    long long ans=numberofWays(n,dp);
    cout<<ans<<"\n";
    return 0;
}