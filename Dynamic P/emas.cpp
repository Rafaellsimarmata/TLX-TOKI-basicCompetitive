#include <iostream>
using namespace std;

int N;
int arr[1001];

int main(){

    cin>>N;
    arr[0] = 0;

    for (int i = 1; i <= N; i++){
        int best = max(i,arr[i/2]+arr[i/3]+arr[i/4]);
        arr[i] = best;
    }
    cout<<arr[N];
    
    

}