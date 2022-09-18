#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int a,b,c;
    cin>>a>>b>>c;
    if(a*a==b*b+c*c)
    {
        cout<<true;
    }
    else{
        cout<<false;
    }
}