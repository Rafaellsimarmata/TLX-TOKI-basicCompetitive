#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct berlian{
    int weight;
    int price;
};


int kapasitas,N;
berlian listBerlian[101];
ll arr[2][2001];
bool taken[101][2001];
vector <int> ans;

void pushAns(int N, int cap){
    if(N == 0) return;
    if(taken[N][cap]){
        ans.push_back(N);
        pushAns(N-1,cap-listBerlian[N].weight);
    }else pushAns(N-1,cap);
}

int main(){ 
    cin>>kapasitas>>N;

    for (int i = 1; i <= N; i++){
        cin>>listBerlian[i].weight>>listBerlian[i].price;
    }

    for (int i = 0; i <= kapasitas; i++){
        arr[0][i] = 0;
    }

    for (int i = 1; i <= N; i++){
        int iNow = i % 2;
        int iPrev = 1 - iNow;

        for (int c = 0; c <= kapasitas; c++){
            ll best = arr[iPrev][c];
            taken[i][c] = 0;
            if(c >= listBerlian[i].weight){
                ll temp = arr[iPrev][c-listBerlian[i].weight] + listBerlian[i].price;
                if(best < temp || (best == temp && (c-listBerlian[i].weight > c) || (best == temp && (c-listBerlian[i].weight <= c)))){
                    taken[i][c] = 1;
                    best = temp;
                }
            }
            arr[iNow][c] = best;
        }
    }
    // cout<<arr[N % 2][kapasitas];
    // cout<<endl;
    pushAns(N,kapasitas);

    for (int i = ans.size()-1; i >= 0 ; i--){
        cout<<ans[i]<<endl;
    }
    
    
    
    
    
    
    
    
    
}