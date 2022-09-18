#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int reverse=0;
    while(n>0){
        int lastDigit= n%10;
        reverse=reverse*10+lastDigit;
        n= n/10;

    }
    cout<<reverse;

    return 0;

} 