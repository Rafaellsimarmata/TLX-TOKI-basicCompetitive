#include <iostream>
using namespace std;

bool wildCard(string a,string text){
    if (text.length() < a.length()-1){
        return false;
    }
    
    int indAsterisk = a.find('*');
    string prefix1 = a.substr(0,indAsterisk);
    string postfix1 = a.substr(indAsterisk+1);
    string prefix2 = text.substr(0,prefix1.length());
    string postfix2 = text.substr(text.length()-postfix1.length(),postfix1.length());
    
    return prefix1 == prefix2 && postfix1 == postfix2;
    
}

int main(){
    string a;
    int n;
    cin>>a>>n;
    
    for (int i = 0; i < n; i++){
        string match;
        cin>>match;
        if (wildCard(a,match)){
            cout<<match<<endl;
        } 
    }    
}