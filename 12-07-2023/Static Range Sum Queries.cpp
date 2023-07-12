//Link - https://cses.fi/problemset/task/1646

#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
 
    int n,q;
    cin>>n>>q;
 
    vector<ll> a(n),prefixSum(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        prefixSum[i] = a[i];
        if(i)
            prefixSum[i]+=prefixSum[i-1];
    }
 
    for(int i=0;i<q;i++){
 
        int a,b;
        cin>>a>>b;
 
        a--,b--;
 
        ll ans = prefixSum[b];
        if(a)
            ans-=prefixSum[a-1];
        
        cout<<ans<<"\n";
 
    }
 
}
