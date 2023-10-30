#include <iostream>
#include <algorithm>
using namespace std;

int arr[10002],arr2[10002],N;

int main(){
    cin>>N;
    for (int i = 0; i < N; i++){
        cin>>arr[i];
    }
    for (int i = 0; i < N; i++){
        cin>>arr2[i];
    }

    sort(arr,arr+N);
    sort(arr2,arr2+N,greater<int>());

    long long res = 0;
    for (int i = 0; i < N; i++){
        res += (long long)(1)*arr[i]*arr2[i];
    }
    cout<<res;
    
    
}