#include <iostream>
using namespace std;

int m,n,arr[25][25];
int temp[25][25];
bool isVisited[25][25];
int count2,nilai,nilai2 = 0;
int counts;

void getLine(int b,int k,int target){

    if (temp[b][k] != target || b > m - 1 || b < 0 || k > n - 1 || k < 0 ){
        return;
    }
    counts+=1;
    temp[b][k] = -1;
    isVisited[b][k] = 1;
    getLine(b,k+1,target);
    getLine(b+1,k,target);
    getLine(b,k-1,target);
    getLine(b-1,k,target);
}

void getLineBreak(int b,int k,int target){

    if (temp[b][k] != target || b > m - 1 || b < 0 || k > n - 1 || k < 0 ){
        return;
    }
    count2++;
    temp[b][k] = -1;
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
    if(temp[b][k] != -1 && temp[b+1][k] == -1 && b<m-1){
        swap(temp[b][k],temp[b+1][k]);
        isClear = false;
    }
    runtuh(b+1,k);
}

int main(){
    cin>>m>>n;
    int maxNilai = -1;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(!isVisited[i][j]){
                counts = 0;
                nilai2 = 0;
                // copy array 
                for (int i = 0; i < m; i++){
                    for (int j = 0; j < n; j++){
                        temp[i][j] = arr[i][j];
                    }
                }

                getLine(i,j,temp[i][j]);
                if(counts == 1)continue;
                nilai = counts*(counts-1);

                // runtuh
                for (int j = 0; j<n; j++){
                    while (true){
                        isClear = true;
                        runtuh(0,j);
                        if(isClear) break;
                    } 
                }

                for (int i = 0; i < m; i++){
                    for (int j = 0; j < n; j++){
                        if (temp[i][j] != -1){
                            getLineBreak(i,j,temp[i][j]);
                            int tempNilai = count2*(count2-1);
                            count2 = 0;
                            if(nilai2 < tempNilai){
                                nilai2 = tempNilai;
                            }
                        }
                    }
                }

                if(maxNilai < nilai + nilai2) maxNilai = nilai + nilai2;
            }
        }
    }
    cout<<maxNilai<<endl;

    



    
}