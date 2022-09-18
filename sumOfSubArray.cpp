#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int currentSum = 0;
    for(int i=0;i<n; i++){
        currentSum = 0;
        for(int j=i;j<n;j++){
            currentSum += arr[j];
            cout<<currentSum<<endl;

        }
    }
}