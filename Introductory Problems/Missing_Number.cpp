#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    long long sum1=0,sum2=((long long)n*(n+1))/2;
    for(int i=0;i<n-1;i++){
        int t;
        cin>>t;
        sum1+=t;
    }
    cout<<(sum2-sum1)<<"\n";
    return 0;
}