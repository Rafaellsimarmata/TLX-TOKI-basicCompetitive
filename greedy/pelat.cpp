#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int N;
vector <pair <ll,int>> pelatHarga;
ll uang,frequent[10];
ll hargaPlatIndex[10];

int main(){
    cin>>N;
    
    for (int i = 0; i <= N; i++){
        pair <ll,int> temp;
        cin>>temp.first; //harga
        temp.second = i;
        pelatHarga.push_back(temp);
        hargaPlatIndex[i] = temp.first;
        frequent[i] = 0;
    };

    cin>>uang;
    sort(pelatHarga.begin(),pelatHarga.end());

    if(uang < pelatHarga[0].first){
        cout<<0;
        return 0;
    }

    if (N == 0){
        cout<<1<<endl<<0<<endl<<0;
        return 0;
    }

    // inisiasi nomor pertama dari plat dengan harga terendah
    // 1. plat pertama tidak boleh diisi dengan 0
    int indPlatFisrt = (pelatHarga[0].second == 0)? pelatHarga[1].second : pelatHarga[0].second;

    if(uang < hargaPlatIndex[indPlatFisrt]){
        cout<<1<<endl<<0<<endl<<0;
        return 0;
    }

    uang -= hargaPlatIndex[indPlatFisrt];
    frequent[indPlatFisrt]++;

    // inisiasi baris selanjutnya dengan harga terendah
    // boleh diisi dengan angka 0
    int nextIndexLowestPrice = pelatHarga[0].second;

    for (int i = 1; i <= N; i++){
        if(pelatHarga[i].first == pelatHarga[0].first) nextIndexLowestPrice = max(nextIndexLowestPrice,pelatHarga[i].second);
    }

    if(uang >= hargaPlatIndex[nextIndexLowestPrice]){
        ll jumlahBeli = uang/hargaPlatIndex[nextIndexLowestPrice];
        uang -= jumlahBeli * hargaPlatIndex[nextIndexLowestPrice];
        frequent[nextIndexLowestPrice] += jumlahBeli;
    }

    // get length 
    ll length = 0;
    for (int i = 0; i <= N; i++){
        length += frequent[i];
    }
    

    // naikkan nilai angka pertama, jika cukup
    int tempBesar = N;
    while (uang < hargaPlatIndex[tempBesar] - hargaPlatIndex[indPlatFisrt] && tempBesar > indPlatFisrt )tempBesar--;
    if(tempBesar > indPlatFisrt){
        uang -= hargaPlatIndex[tempBesar] - hargaPlatIndex[indPlatFisrt];
        frequent[indPlatFisrt]--;
        frequent[tempBesar]++;
    }

    // naikkan nilai baris selanjutnya, jika cukup
    while (uang > 0 && tempBesar > nextIndexLowestPrice && frequent[nextIndexLowestPrice] > 0){
        ll temp = hargaPlatIndex[tempBesar] - hargaPlatIndex[nextIndexLowestPrice];
        if(uang >= temp){
            ll jumlahBeli = uang/temp;
            if(jumlahBeli > frequent[nextIndexLowestPrice]) jumlahBeli = frequent[nextIndexLowestPrice];
            uang -= temp * jumlahBeli;
            frequent[tempBesar] += jumlahBeli;
            frequent[nextIndexLowestPrice] -= jumlahBeli;
        }else{
            tempBesar--;
        }
    }

    // Output 
    cout<<length<<endl;

    int tot = 0;
    int indexPlat = N;
    // 50 index awal
    while (tot <= 50 && indexPlat >= 0){
        for (int i = 0; i < frequent[indexPlat]; i++){
            if (tot == 50) break;
            cout<<indexPlat;
            tot++;
        }
        indexPlat--;
    }

    cout<<endl;
    tot = 0;
    if(length > 50){
        indexPlat = 0;
        vector <int> res;
        // 50 index akhir
        while (tot <= 50 && indexPlat <= 9){
            for (int i = 0; i < frequent[indexPlat]; i++){
                if (tot == 50) break;
                res.push_back(indexPlat);
                tot++;
            }
            indexPlat++;
        }
        for (int i = 49; i >= 0; i--){
            cout<<res[i];
        }
    }else{
        indexPlat = N;
        // 50 index awal
        while (tot <= 50 && indexPlat >= 0){
            for (int i = 0; i < frequent[indexPlat]; i++){
                if (tot == 50) break;
                cout<<indexPlat;
                tot++;
            }
            indexPlat--;
        }
    }
    cout<<endl;
    
}