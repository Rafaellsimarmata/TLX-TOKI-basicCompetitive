#include <iostream>
#include <algorithm>
using namespace std;

string arr[1001];

bool sortArr(string a, string b){
    return a < b;
}

int search(int size, string target){
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end){
        mid = (start + end)/2;
        if (arr[mid] < target){
            start = mid + 1;
        }else if(arr[mid] > target){
            end = mid - 1;
        }else{
            break;
        }
    }
    return mid + 1;
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        string name;
        cin>>name;
        arr[i] = name;

        if (i == 0) cout<<1<<endl;
        else{
            sort(arr,arr+i+1,sortArr);
            cout<<search(i+1,name)<<endl;
        }
    }
    
    
}