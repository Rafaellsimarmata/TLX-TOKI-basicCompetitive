#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int kakiBebek[1001],sepatu[1001];
int res = 0;

void getBebek(int indBebek, int indSepatu){
    if(indBebek >= N || indSepatu >= M){
        return;
    }

    if(kakiBebek[indBebek] == sepatu[indSepatu] || kakiBebek[indBebek] + 1 == sepatu[indSepatu]){
        res += 1;
        getBebek(indBebek+1,indSepatu+1);
    }else{
        if(sepatu[indSepatu] > kakiBebek[indBebek]) getBebek(indBebek+1,indSepatu);
        else getBebek(indBebek,indSepatu+1);
    }
}

int main(){
    cin>>N>>M;
    for (int i = 0; i < N; i++){
        cin>>kakiBebek[i];
    }

    for (int i = 0; i < M; i++){
        cin>>sepatu[i];
    }

    sort(kakiBebek,kakiBebek+N);
    sort(sepatu,sepatu+M);

    getBebek(0,0);
    cout<<res;
    
    
}