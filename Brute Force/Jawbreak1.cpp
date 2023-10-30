#include <iostream>
using namespace std;

int m,n,arr[25][25];
int t,nilai = 0;

void getLine(int b,int k,int target){

    if (arr[b][k] != target || b > m - 1 || b < 0 || k > n - 1 || k < 0 ){
        return;
    }
    t++;
    arr[b][k] = -1;
    getLine(b,k+1,target);
    getLine(b+1,k,target);
    getLine(b,k-1,target);
    getLine(b-1,k,target);
}


int main(){
    cin>>m>>n;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] != -1){
                getLine(i,j,arr[i][j]);
                int tempNilai = t*(t-1);
                t = 0;
                if(nilai < tempNilai) nilai = tempNilai;
            }
        }
    }
    cout<<nilai;
}