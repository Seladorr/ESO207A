#include<iostream>
#include<vector>

using namespace std;
long long countInversions(vector<int> & arr, int i, int j)
{
    if(i==j)
        return 0;
    int mid = (i+j)/2;

    //divide step
    long long count1 = countInversions(arr, i, mid);
    long long count2 = countInversions(arr, mid+1, j);
    long long count3 = 0;

    // combine step--> slight modification of merge algorithm
    vector<int> temp; //create temporary vector for merge
    int p1 = i, p2 = mid+1;
    while(p1 <= mid && p2 <=j)
    {
        if(arr[p1] <= arr[p2])
        {
            temp.push_back(arr[p1]);
            p1++;
        }
        else
        {
            temp.push_back(arr[p2]);
            count3+= mid+1-p1; // only modification on merge algorithm
            p2++;
        }
    }
    while(p1<=mid)
    {
        temp.push_back(arr[p1]);
        p1++;
    }
    while(p2<=j)
    {
        temp.push_back(arr[p2]);
        p2++;
    }
    for(unsigned long q=0; q<temp.size(); q++) 
    {
        arr[q+i] = temp[q];  //update the array
    }
    return count1 + count2 + count3;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        cout <<countInversions(arr, 0, n-1)<<endl;
    }
}
