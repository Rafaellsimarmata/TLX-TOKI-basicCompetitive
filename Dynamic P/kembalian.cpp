#include <iostream>
using namespace std;

int n,kembalian;
int arr[501];
long long memo[50001];
bool isComputed[50001];

int getResult(int kembalian){ 
    if(kembalian == 0) return 0;

    if(isComputed[kembalian]) return memo[kembalian];

    int res = 1e9;
    for (int i = 0; i < n; i++){
        if(kembalian >= arr[i]) 
            res = min(res,getResult(kembalian - arr[i])+1);
    }
    isComputed[kembalian] = 1;
    memo[kembalian] = res;
    return res;
}

int main(){
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cin>>kembalian;
    int ret = getResult(kembalian);
    cout<<(ret == 1e9? -1:ret);
    
    

    
    
}