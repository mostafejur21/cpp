#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r",stdin);
        freopen("output.txt", "w",stdout);
    #endif
int n;
cin>>n;
int counter=1;
for(int i= 1; i<=n; i++){
    for(int j=1; j<=i; j++){
        cout<<counter<<" ";
        counter++;
    }
    cout<<endl;
}
return 0;
}