#include <iostream>
using namespace std;

int getFpb(int a, int b){
    if (b == 0){
        return a;
    }else{
        return getFpb(b, a%b);
    }
}

int main(){
    int t,kpk;
    cin>>t;

    for (int i = 0; i < t; i++){
        if (i < 2){
            int a,b;
            cin>>a>>b;
            kpk = (a*b) / getFpb(a,b);
            i ++;
        }else{
            int k;
            cin>>k;
            kpk = (kpk*k) / getFpb(kpk,k);
        }
    }

    cout<<kpk;
}