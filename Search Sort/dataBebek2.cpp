#include <iostream>
using namespace std;

int dataBebek[100001],n;

int getIndex(int a){
    int left = 0;
    int right = n - 1;
    int mid;
    while (left < right){
        mid = (left + right)/2;
        if (dataBebek[mid] > a) right = mid - 1;
        else left = mid + 1;
    }
    if (dataBebek[left] <= a) left++;
    return left;
}

int main(){
    int q;
    int x,y;
    cin>>n;
    
    for (int i = 0; i < n; i++){
        cin>>dataBebek[i];
    }
    cin>>q;

    for (int j = 0; j < q; j++){
        cin>>x>>y;
        cout<<getIndex(y) - getIndex(x)<<endl; 
    }  
}