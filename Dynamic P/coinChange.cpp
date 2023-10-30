#include <iostream>
using namespace std;

int n,uang;
int arr[100];

int res(int n,int uang){
    if(uang == 0) return 0;
    if(n == 0) return 10000000;

    int ret = res(n-1,uang);

    if(arr[n] <= uang)
        ret = min(ret,res(n-1,uang-arr[n])+1);

    return ret;

}

int main(){
    cin>>n;

    for (int i = 0; i < n; i++)
        cin>>arr[i];

    cin>>uang;
    cout<<res(n,uang);
    


    
    
    
}