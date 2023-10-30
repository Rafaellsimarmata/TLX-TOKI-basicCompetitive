#include <iostream>
using namespace std;

int m,n,arr[25][25];
int arr2[25][25];
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

void getLineBreak(int b,int k,int target){

    if (arr2[b][k] != target || b > m - 1 || b < 0 || k > n - 1 || k < 0 ){
        return;
    }
    arr2[b][k] = -1;
    getLineBreak(b,k+1,target);
    getLineBreak(b+1,k,target);
    getLineBreak(b,k-1,target);
    getLineBreak(b-1,k,target);
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

bool isClear;

void runtuh(int b, int k){
    if(b>=m){
        return;
    }
    if(arr2[b][k] != -1 && arr2[b+1][k] == -1 && b<m-1){
        swap(arr2[b][k],arr2[b+1][k]);
        isClear = false;
    }
    runtuh(b+1,k);
}

int main(){
    cin>>m>>n;
    int iMax, jMax = -1;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }

    // copy array 
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            arr2[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] != -1){
                getLine(i,j,arr[i][j]);
                int tempNilai = t*(t-1);
                t = 0;
                if(nilai < tempNilai){
                    nilai = tempNilai;
                    iMax = i; jMax = j;
                }
            }
        }
    }

    getLineBreak(iMax,jMax,arr2[iMax][jMax]);
    // runtuh
    for (int j = 0; j<n; j++){
        while (true){
            isClear = true;
            runtuh(0,j);
            if(isClear) break;
        } 
    }
    cout<<endl;
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (arr2[i][j] == -1) cout<<". ";
            else cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    



    
}