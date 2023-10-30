#include <iostream>
#include <algorithm>
using namespace std;

int n,m;

long long getValue(long long arr[],long long x){
    long long res = 0;
    for (int i = 0; i < n; i++){
        res += x/arr[i]; 
    }
    return res;
}

long long searchValue(long long arr[],long long target){
    long long left = 0;
    long long right = (1LL<<40) - 1;
    long long res;

    while (left <= right){
        long long mid = (left + right) / 2;

        if(getValue(arr,mid) >= target){
            right = mid - 1;
            res = mid;
        }
        else left = mid + 1;
    }
    return res;
}

int main(){
    cin>>n>>m;
    long long arr[n];

    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    cout<<searchValue(arr,m+1) - searchValue(arr,m);
    
    
    





}