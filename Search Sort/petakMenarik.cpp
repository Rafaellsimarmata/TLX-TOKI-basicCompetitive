#include <iostream>
using namespace std;

int arr[101][101];

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
    int value;
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            value = 1;
            if (i > 0){value *= arr[i-1][j];}
            if (i < n-1){value *= arr[i+1][j];}
            if (j > 0){value *= arr[i][j-1];}
            if (j < m-1){value *= arr[i][j+1];}

            if (value == k){
                cout<<i+1<<" "<<j+1;
                break;
            }
        }
        if (value == k) break;
    }

    if (value != k){
        cout<<"0 0";
    }
}