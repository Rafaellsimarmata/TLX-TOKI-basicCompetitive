#include <iostream>
using namespace std;

int arr[75][75];
int arr2[75][75];

bool checkIdentik(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] != arr2[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool checkHorisontal(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] != arr2[(n-1)- i][j]){
                return false;
            }
        }
    }
    return true;
}

bool checkVertikal(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] != arr2[i][(n - 1)-j]){
                return false;
            }
        }
    }
    return true;
}

bool checkDiagonalKiri(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[(n-1)-j][(n-1)-i] != arr2[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool checkDiagonalKanan(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[j][i] != arr2[i][j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n1,n2,n3,n4;
    cin>>n1>>n2;

    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            cin>>arr[i][j];
        }
    }

    cin>>n3>>n4;

    for (int i = 0; i < n3; i++){
        for (int j = 0; j < n4; j++){
            cin>>arr2[i][j];
        }
    }

    if (checkIdentik(n1) == 1) cout<<"identik";
    else if(checkHorisontal(n1) == 1) cout<<"horisontal";
    else if(checkVertikal(n1) == 1) cout<<"vertikal";    
    else if(checkDiagonalKanan(n1) == 1) cout<<"diagonal kanan bawah";
    else if(checkDiagonalKiri(n1) == 1) cout<<"diagonal kiri bawah";
    else cout<<"tidak identik";
    
    
    
}