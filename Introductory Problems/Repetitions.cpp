#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string n;
    cin>>n;
    int maxcount=1,cnt=1;
    for(int i=0;i<n.size()-1;i++){
        n[i]==n[i+1]?cnt++:cnt=1;
        maxcount=max(cnt,maxcount);
    }
    cout<<maxcount<<"\n";

    return 0;
}