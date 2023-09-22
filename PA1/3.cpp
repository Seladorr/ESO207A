#include <iostream>
using namespace std;

typedef long long ll;
const int M = 998244353;


void mult(ll A[30][30], ll B[30][30], int size){
    ll C[30][30] = {0};
    for(ll i=0;i<size;i++){
        for(ll j=0;j<size;j++){
            for(ll k=0;k<size;k++)
                C[i][j] = (C[i][j]%M + (A[i][k]*B[k][j])%M)%M;
        }
    }
    for(ll i=0;i<size;i++){
        for(ll j =0;j<size;j++) A[i][j] = C[i][j];
    }
}

void pow(ll A[30][30], ll n, int size){
    ll B[30][30]={0};
    
    for(ll i=0;i<size;i++){
        for(ll j=0;j<size;j++){
            if(i==j)    B[i][j] = 1;
        }
    }
    while(n>0){
        if(n%2 != 0) mult(B,A,size);
        mult(A,A,size);
        
        n/=2;
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            A[i][j] = B[i][j];
        }
    }
}

bool check(int j,int i,int k){
    int num = 0;
    if(i-k>0) num = i-k;
    return j>=num;
}

int main() {
    int t;cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll matrix[30][30] ={0};
        int size= k;
        for(ll i=0;i<size;i++){
            matrix[0][i] = 1;
            if(i>0)   matrix[i][i-1] = 1;
        }
        ll ifib[30] ={0};
        ifib[0] = 1;
        for(int i=1;i<=size;i++){
            for(int j = i-1;check(j,i,k);j--){
                ifib[i] = (ifib[i] + ifib[j])%M;
            }
        }
        if(n<=size){
            cout<<ifib[n]<<endl;
            continue;
        }
        pow(matrix,n-k,size);
        ll ans = 0;
        for(ll i=0;i<size;i++){
            ans = (ans%M + (matrix[0][i]*ifib[size-i])%M)%M;
        }
        cout<<ans<<endl;
    }
    return 0;
}
