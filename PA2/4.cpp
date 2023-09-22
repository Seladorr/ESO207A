#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


int count(vector<int>& arr,vector<int> &start, vector<int> &end, int s)
{
    int ans = 0;
    int siz = arr.size();
    vector<int> prefsum(siz + 1, 0);
    for (int i = 1; i <= siz; i++)
        prefsum[i] = prefsum[i-1] + arr[i-1];
    for(int i=0; i<s; i++)
    {
        int segsum = prefsum[end[i]] - prefsum[start[i] - 1];
        if (segsum > 0)    ans++;
    }
    return ans;
}
int minquer(vector<int> &arr, vector<int> &start, vector<int> &end, vector<int> &query, int k, int s)
{
    int lo = 0;
    int hi =  query.size()-1;
    int res = 1e8;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        int n = arr.size();
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=arr[i];
        for(int i=0;i<=mid;i++)
        {
            v[query[i]-1]=1;
        }
        int pos = count(v, start, end, s);
        if(pos<k)  lo = mid + 1;
        else{
            hi = mid-1;
            if(mid<res)
                res = mid;
        }
    }
    if(res == 1e8)  return -1;
    else    return res+1;
}

int solve(int n,int s,vector<int>& arr,vector<int>& start,vector<int>& end,int q,int k,vector<int>& query){
    if(count(arr, start, end,s) >= k)   return 0;
    int mini = minquer(arr, start, end, query, k, s);
    return mini;
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n,s;
        cin>>n>>s ;
        vector<int> arr(n);
        for (int i = 0; i<n;i++) cin >> arr[i];
        vector<int> start(s), end(s);
        for (int i = 0; i<s;i++) cin >> start[i] >> end[i];
        int q,k;
        cin>>q>>k;
        vector<int> query(q);
        for (int i = 0;i<q;i++) cin >> query[i];
        cout<<solve(n,s,arr,start,end,q,k,query)<<endl;
    }
    return 0;
}
