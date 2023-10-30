#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int N,arr[20002];
ll B;

int main(){
    cin>>N>>B;

    for (int i = 0; i < N; i++){
        cin>>arr[i];
    }

    sort(arr,arr+N,greater<int>());

    ll temp = 0;
    ll ind = 0;
    for (int i = 0; i < N; i++){
        temp += arr[i];
        ind++;
        if(temp >= B) break;
    }

    cout<<ind;
    





    
    
}