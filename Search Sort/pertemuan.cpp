#include <iostream>
#include <algorithm>
using namespace std;

string arr[501];

bool sortLength(string a, string b){
    if (a.length() != b.length()){
        return a.length() < b.length();
    }else{
        return a < b;
    }
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,sortLength);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<endl;
    }
}