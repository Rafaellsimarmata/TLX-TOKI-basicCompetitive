#include <iostream>
using namespace std;

int dataBebek[100001];
int i = 0;

void getJumlah(int right, int left,int x, int y){
    if (right > left){
        return;
    }else{
        int mid;
        while (right <= left){
            mid = (right + left) / 2;

            if (dataBebek[mid] <= x){
                right = mid + 1;
            }else if(dataBebek[mid] > y){
                left = mid - 1;
            }else{
                i++;
                break;
            }
        }
        getJumlah(right,mid-1,x,y);
        getJumlah(mid+1,left,x,y);
    }
}

int main(){
    int n,q,x,y;
    cin>>n;
    
    for (int i = 0; i < n; i++){
        cin>>dataBebek[i];
    }
    cin>>q;

    for (int j = 0; j < q; j++){
        cin>>x>>y;
        getJumlah(0,n-1,x,y);
        cout<<i<<endl;
        i = 0;
    }  
}