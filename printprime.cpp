#include<iostream>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);        
        freopen("output.txt","w",stdout);
    #endif

    int a,b;
    cin>>a>>b;
    // int num;
    for(a; a<=b;a++){
    int i;
        for(i=2;i<a;i++){
            if(a%i==0){
                break;
            }
        }
        if(i==a){
            cout<<a<<endl;
        }
    }   
    return 0;
}