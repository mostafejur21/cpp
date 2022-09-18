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
    int sum=0;
    int original_n=n;
    while(n>0)
    {
        int lastDigit=n%10;
        sum+=pow(lastDigit, 3);
        n=n/10;
    }
    if(sum==original_n)
    {
        cout<<original_n<<" is armstong number"<<endl;

    }
    else{
        cout<<"This is not armstong number";
    }
}