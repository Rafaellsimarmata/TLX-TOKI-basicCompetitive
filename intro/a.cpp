#include <iostream>
#include <algorithm>
using namespace std;

struct peserta{
    string id;
    int s3,s2,s1;
};

bool sortTerm(peserta a, peserta b){
    return a.s3 > b.s3 || (a.s3 == b.s3 && a.s2 > b.s2) || (a.s2 == b.s2 && a.s1 > b.s1);
}

peserta arr[80];

int main(){
    int t,n,m;
    string target;
    cin>>t;

    for (int j = 0; j < t; j++){    
        cin>>n>>m>>target;
        for (int i = 0; i < n; i++){
            cin>>arr[i].id>>arr[i].s1>>arr[i].s2>>arr[i].s3;
        }

        sort(arr, arr + n,sortTerm);

        bool lulus = false;
        for (int i = 0; i < m; i++){
            if (arr[i].id == target){
                lulus = true;
                break;
            }
        }

        cout<<(lulus? "YA" : "TIDAK")<<endl;
    }
    
}