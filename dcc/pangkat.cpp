#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;

ll a,b;
ll mod = 1000000;


ll power(ll a, ll b){
    if(a == 0 && b == 0) return 0;
    else if (b == 0) return 1;
    else if(a == 1) return 1;
    ll ret = 1;

    while (b > 0){
        if (b%2 == 1) ret = (ret * a) % mod;
        b = b / 2;
        a = (a*a)%mod;   
    }

    return ret;
}

int main(){
    cin>>a>>b;

    if(pow(a,b) < 999999) cout<<power(a,b);
    else cout << setw(6) << setfill('0') << power(a,b);
    

    

    

    
}