#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tarian{
    int nilai;
    char jenisGerakan;
};

vector <int> skorTotal;
int n,r,y,j;
bool isUsed[10] = {0};
tarian arr[10];

void getSkor(int x,int skor ,char prev, bool yakin){
    if (x >= r){
        skorTotal.push_back(skor);
        return;
    }

    for (int i = 0; i < n; i++){
        if (!isUsed[i]){
            int tempNilai;
            isUsed[i] = 1;

            if(prev == 'P') tempNilai = arr[i].nilai*2;
            else if (prev == 'L') tempNilai = arr[i].nilai / 2;
            else tempNilai = arr[i].nilai;

            if (yakin) tempNilai += y;

            getSkor(x+1,skor+tempNilai,arr[i].jenisGerakan,(yakin || arr[i].jenisGerakan == 'Y'));
            isUsed[i] = 0;
        }
    }
}

int binarySearch(int target){
    int left = 0;
    int right = skorTotal.size() - 1;
    int mid;

    while (left <= right){
        mid = (left + right) / 2;
        if (skorTotal[mid] <= target)
            left = mid + 1;
        else 
            right = mid - 1;
    }
    if(skorTotal[mid] <= target) return mid + 1;
    else return mid;
}

int main(){
    string subSoal;
    getline(cin,subSoal);
    cin>>n>>r>>y>>j;

    for (int i = 0; i < n; i++){
        cin>>arr[i].nilai>>arr[i].jenisGerakan;
    }

    getSkor(0,0,'B',false);
    sort(skorTotal.begin(),skorTotal.end());

    for (int i = 0; i < j; i++){
        int k;
        cin>>k;
        int size = skorTotal.size();
        int ind = binarySearch(k);
        cout<<size - ind<<endl;
    }
    
    

}