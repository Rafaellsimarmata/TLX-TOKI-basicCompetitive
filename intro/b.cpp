#include <iostream>
using namespace std;

char arr[21][9];
int r,c,base;

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

void runtuh(int i,int j){
    if ((arr[i][j] == '1') && (arr[i+1][j] == '0') && i<r){
        swap(arr[i][j],arr[i+1][j]);
        runtuh(i+1,j);
    }else{
        return;
    }
    
}

void getBase(){
    for (int i = r-1; i >= 0; i--){
        int isNull = 0;
        for (int j = 0; j < c; j++){
            if (arr[i][j] == '0'){
                isNull++;
            }
        }
        if (isNull == c){
            base = i-1;
            break;
        }
    }
}

bool clear(){
    bool isClear = 0;
    for (int i = 0; i < r; i++){
        int isFilled = 0;
        int k = 0;
        for (int j = 0; j < c; j++){
            
            if (arr[i][j] == '1'){
                isFilled++;
            }
        }
        if (isFilled == c){
            for (k = 0; k < c; k++){
                arr[i][k] = '0';
            }   
            isClear = 1;
        }
    }      
    if (isClear){
        return 1;
    }else{
        return 0;
    }
      
}

int main(){
    cin>>r>>c;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin>>arr[i][j];
        }
    }
    // cout<<endl;
    
    while (clear()){
        getBase();
        for (int i = base; i >= 0 ; i--){
            for (int j = 0; j < c; j++){
                runtuh(i,j);
            }
        }
    }
    

    for (int k = 0; k < r; k++){
        for (int l = 0; l < c; l++){
            cout<<arr[k][l];
        }
        cout<<endl;
    }
}