#include <iostream>
using namespace std;

string name[100001];
string number[100001];

int main(){
    int n,q;
    cin>>n>>q;
    
    for (int i = 0; i < n; i++){
        cin>>name[i];
        cin>>number[i];
    }

    for (int j = 0; j < q; j++){
        string target;
        cin>>target;

        int start = 0;
        int end = n-1;
        string result = "NIHIL";

        while (start <= end && result=="NIHIL"){
            int mid = (start + end)/2;
        
            if (target < name[mid]){
                end = mid - 1;
            }else if(target > name[mid]){
                start = mid + 1;
            }else{
                result = number[mid];
                break;
            }
        }
        cout<<result<<endl;
    }
    
    
}