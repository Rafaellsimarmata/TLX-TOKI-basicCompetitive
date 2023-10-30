#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int nilai[100001];

int main(){
    int n;
    float result;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>nilai[i];
    }
    sort(nilai,nilai+n);

    if (n % 2 != 0) result = (float)nilai[n/2];
    else result = (((float)nilai[n/2 - 1] + (float)nilai[n/2])/2.0);

    cout<<fixed<<setprecision(1)<<result;
}