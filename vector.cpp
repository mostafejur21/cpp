#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>a, pair<int,int>b){
    return a > b;
}
int main() 
{
	
       int n,a,c=0,s=0;
	    cin>>n;
	    
	    vector<pair<int,int>> v(n);
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>a;
	        cin>>v[i].second>>v[i].first;
	    }
	    
	    sort(v.begin(),v.end(),comp);
	    int slot[a]={};
	    
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=v[i].second;j>=1;j--)
	        {
	            if(slot[j]==0)
	            {
	                slot[j]=v[i].first;
	                c++;
	                s+=v[i].first;
	                break;
	            }
	        }
	    }
		cout<<"maximum number of slot is: "<<c<<endl;
		cout<<"the taken jobs are: ";
		for (int i = 0; i < n; i++){
			if(slot[i]!=0){
				cout<<slot[i]<<" ";
			}
		}
		cout<<endl;
	    cout<<"Total maximum profit is: " << s <<endl;
	return 0;
}