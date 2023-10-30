#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int n,x,winner;
    int min = INT_MAX;
    cin>>n>>x;

    for (int i = 0; i < n; i++){
        int k;
        cin>>k;

        if (min > abs(k - x)){
            min = abs(k - x);
            winner = k;
        }else if(min == abs(k - x)){
            winner = (winner > k) ? k : winner;
        }
    }

    cout<<winner;
    
}