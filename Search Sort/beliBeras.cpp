#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct dataBeras{
    int berat;
    int harga;
};

dataBeras arr[1001];

bool sortFromMax(dataBeras a, dataBeras b){
    return (double)a.harga/a.berat > (double)b.harga/b.berat || (double)((double)a.harga/a.berat == (double)b.harga/b.berat && (double)a.berat > (double)b.berat);
}

int main(){
    int n,x;
    cin>>n>>x;
    
    for (int i = 0; i < n; i++){
        cin>>arr[i].berat;
    }
    for (int i = 0; i < n; i++){
        cin>>arr[i].harga;
    }
    sort(arr,arr+n,sortFromMax);

    double result= 0;
    int j = 0;
    while (x > 0 && j < n){
        if (x >= arr[j].berat){
            x -= arr[j].berat;
            result += arr[j].harga;
            ++j;
        }else{
            result += (double)arr[j].harga / (double)arr[j].berat * (double)x;
            x = 0;
        }
    }
    cout<<fixed<<setprecision(7)<<result;
}