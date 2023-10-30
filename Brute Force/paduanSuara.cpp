#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001],maxDuck,minDuck,n,k;
vector <int> ans;

void cetak(){
    for (int i = 0; i < k-1; i++){
        cout<<ans[i]<<" ";
    }
}

void getBatas(int maxGroup, int minGroup,int ind){
    if(maxGroup + minGroup == 1){
        cetak();
        exit(0);
    }
    
    if((arr[ind + maxDuck ] != arr[ind+maxDuck+1]) && maxGroup>0){
        ans.push_back(arr[ind+maxDuck]+1);
        getBatas(maxGroup-1, minGroup,ind+maxDuck);
        ans.pop_back();
    }

    if((arr[ind + minDuck ] != arr[ind+minDuck+1]) && minDuck>0){
        ans.push_back(arr[ind+minDuck] + 1);        
        getBatas(maxGroup, minGroup-1,ind+minDuck);
        ans.pop_back();
    }
}

int main(){
    int maxGroup,minGroup;
    cin>>n;

    for (int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    cin>>k;
    sort(arr,arr+n+1);

    minDuck = n/k; // 1
    maxDuck = minDuck+1; //2
    maxGroup = n % k; //3
    minGroup = k - maxGroup; //2
    getBatas(maxGroup,minGroup,0);
    
    


    // 21 22 || 24 || 26 26 || 28 211 || 500 
    

}