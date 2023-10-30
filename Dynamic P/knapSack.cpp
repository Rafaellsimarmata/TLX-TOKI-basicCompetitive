#include <iostream>
#include <algorithm>
using namespace std;

int N,G;
pair<int,int> arr[100];
bool isCompute[100][100] = {0};
int memo[100][100];

int solveSolution(int n, int kapasitas){
    if(n == 0) return 0;

    if(isCompute[n][kapasitas]) return memo[n][kapasitas];

    int ret = solveSolution(n-1,kapasitas);
    if(arr[n].second <= kapasitas)
        ret = max(solveSolution(n-1,kapasitas-arr[n].second) + arr[n].first,ret);

    isCompute[n][kapasitas] = 1;
    memo[n][kapasitas] = ret;
    return ret; 
} 

int main(){
    cin>>N;
    for (int i = 1; i <= N; i++) {
        cin>>arr[i].first;
        cin>>arr[i].second;
    }
    cin>>G;

    cout<<solveSolution(5,14);

}