#include <iostream>
#include <vector>
using namespace std;

bool arr[1000000] = {0};
vector <int> primeList;

int main(){
    int t,k;
    cin>>t;

    for (int i = 2; i < 1000000; i++){
        if (!arr[i]){
            primeList.push_back(i);
            int temp = i*2;
            while (temp < 1000000){
                arr[temp] = 1;
                temp += i;
            }            
        }       
    }

    for (int i = 0; i < t; i++){
        cin>>k;
        cout<<primeList[k-1]<<endl;    
    }
}