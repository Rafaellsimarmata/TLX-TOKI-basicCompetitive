#include <iostream>
using namespace std;

int t,n,tebakan[5];
int jumlahPertandingan;
pair <int,int> versus[15];
bool answer;

void checkTebakan(int pertandinganKe, int tempSkor[]){
    if (pertandinganKe >= jumlahPertandingan){
        bool check = true;
        for (int i = 0; i < n; i++)
            if (tempSkor[i] != tebakan[i]) 
                check = false;

        if (check == true) answer = true;
        return;
    }else{
        int a = versus[pertandinganKe].first;
        int b = versus[pertandinganKe].second;  

        int skorBaru[n];

        for (int i = 0; i < n; i++) 
            skorBaru[i] = tempSkor[i];
        // tim A menang  
        skorBaru[a] += 3;
        checkTebakan(pertandinganKe+1,skorBaru);

        for (int i = 0; i < n; i++) 
            skorBaru[i] = tempSkor[i];
        // tim B menang 
        skorBaru[b] += 3;
        checkTebakan(pertandinganKe+1,skorBaru);

        for (int i = 0; i < n; i++) 
            skorBaru[i] = tempSkor[i];
        // seri 
        skorBaru[a] += 1;
        skorBaru[b] += 1;
        checkTebakan(pertandinganKe+1,skorBaru);
        return;
    }


    
}

int main(){
    cin>>t;
    for (int i = 0; i < t; i++){
        answer = false;
        cin>>n;
        jumlahPertandingan = n*(n-1)/2;

        for (int j = 0; j < n; j++){
            cin>>tebakan[j];
        }

        int ind = 0;
        for (int l = 0; l < n; l++){
            for (int j = l+1; j < n; j++){
                versus[ind] = {l,j};
                ind++;
            }
        }

        int tempSkor[n];
        fill(tempSkor,tempSkor+n,0);
        checkTebakan(0,tempSkor);

        if (answer)cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    
    
}