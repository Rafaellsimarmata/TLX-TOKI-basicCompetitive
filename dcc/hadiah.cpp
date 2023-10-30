#include <iostream>
using namespace std;
typedef long long ll;

int a,b,c,n;

int kuadrat(int a){
    return (a *ll(1)* a) % n;
}

int f(int a, int b){
    if(b == 0 ) return 1;
    if(b % 2 == 1) return (a * ll(1)*f(a,b-1))%n;
    else return kuadrat(f(a,b/2)); 
}

int main(){
    cin>>a>>b>>c>>n;

    if(c == 0)cout<< (a % n) + 1;
    else if(c == 1) cout<<(f(a,b)% n) + 1;
    else if(c > 1){
        int ans = f(a,b);
        for (int i = 1; i < c; i++){
            ans = f(ans,b);
        }
        cout<<ans + 1;
    }
}