#include<iostream>
using namespace std;

typedef long long ll;

bool cost(ll arr[], ll n, ll ht,long long k){
    ll sum = 0;
    for(ll i=0;i<n;i++){
        ll temp = arr[i] - ht;
        if(temp > 0) sum += (arr[i]*(arr[i]+1)- ht*(ht+1))/2;
        if(sum>k)   return false;
    }
    return sum <= k;
}

int main() {  
    int t;cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll maxht = -1;
        for(ll i=0;i<n;i++){
            if(arr[i]>maxht) maxht = arr[i];
        }
        //applying binary search on the maximum height
        ll lo = 0, hi = maxht;
        ll ans = maxht;
        while(lo<=hi){
            ll mid = lo + (hi-lo)/2;
            if(cost(arr,n,mid,k)){
                ans = mid;
                hi= mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
