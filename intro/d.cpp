#include <iostream>
using namespace std;

bool check(string a, string b){
    if (a.length()-1 != b.length()){
        return false;
    }

    for (int i = 0; i < b.length(); i++){
        if (a[i] != b[i] && a[i+1]!= b[i]){
            return false;
        }
    } 
    return true;
}

int main(){
    string a,b;
    cin>>a>>b;
    
    cout<<(check(a,b)? "Tentu saja bisa!" : "Wah, tidak bisa :(");
    
    

}