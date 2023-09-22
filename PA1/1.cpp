#include<iostream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        long arr[n],ans[n];
        for(int i=0;i<n;i++){
            cin>>arr[n-i-1];
        }
        ans[0] = arr[0];
        //algorithm
        for(int i=1;i<n;i++){
            if(ans[i-1]<0)  ans[i] = arr[i];
            else    ans[i] = ans[i-1] + arr[i];
        }
        for(int i=0;i<n;i++){
            cout<<ans[n-i-1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
