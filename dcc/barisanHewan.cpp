#include <iostream>
typedef long long ll;
using namespace std;

int N,Q,arr[100002];

int searchJenis(int target){
    ll L = 0;
    ll R = N-1;
    int ret;

    while (L <= R){
        ll mid = (L+ R) / 2;

        if(target <= arr[mid]){
            R = mid - 1;
            ret = mid * ll(1);
        }else L = mid+1;
    }
    return ret;
    
}

int main(){
    cin>>N;
    ll temp = 0;
    for (int i = 0; i < N; i++){
        int k;
        cin>>k;
        temp += k; 
        arr[i] = temp;
    }

    cin>>Q;
    for (int i = 0; i < Q; i++){
        int k;
        cin>>k;
        cout<<searchJenis(k) + 1<<endl;
    }
}