#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void solve(vector<int> &arr, vector<int> &ans, int left, int right, int level)
{
    int n = arr.size();
    if(left > right || right >=n || left <0)
    {
        return ;
    }
            
    int max_val = arr[left];
    int I = left;
    for(int i=left; i<=right; i++)
    {
        if(max_val < arr[i])
        {
            I = i;
            max_val = arr[i];
        }
           
    }
    
    ans[I] = level;
    solve(arr, ans, left, I-1, level+1);
    solve(arr, ans, I+1, right, level+1 );
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        vector<int> ans(n, 0);
        solve(arr, ans, 0, n-1, 0);
        for(auto it: ans){
            cout << it << " "; 
        }
        cout << endl;
    }
    return 0;
}