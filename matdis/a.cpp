#include <iostream>
using namespace std;

long long fpb(long e, long f){
    if (f == 0){
        return e;
    }else{
        return fpb(f, e%f);
    }
}

int main(){
    long long a,b,c,d,e,f;
    cin>>a>>b>>c>>d;

    f = b*d;
    e = d*a + b*c;

    cout<<e / fpb(e,f)<<" "<<f/fpb(e,f);
}