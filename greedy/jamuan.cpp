#include <iostream>
#include <algorithm>
using namespace std;

pair <int,int> arr[100002];
int N;
int Jumlah = 0;

bool sortEnd(pair <int,int> a,pair <int,int> b){
    return a.second < b.second;
}

void getJumlah(int prevEnd, int ind){
    if(ind >= N) return;
    else{
        if (arr[ind].first < prevEnd) getJumlah(prevEnd,ind+1);
        else if (arr[ind].first >= prevEnd){
            Jumlah++;
            getJumlah(arr[ind].second,ind+1);
        }
    }
}

int main(){
    cin>>N;
    
    for (int i = 0; i < N; i++){
        int start,duration,end;
        cin>>start>>duration;
        end = start + duration;
        arr[i].first = start;
        arr[i].second = end;
    };

    sort(arr,arr+N,sortEnd);
    getJumlah(0,0);
    cout<<Jumlah;
    
}