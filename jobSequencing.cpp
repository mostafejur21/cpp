#include<bits/stdc++.h>
using namespace std;

int main() 
{
	
       int n,taskID,deadline=0,profit=0;
	    cin>>n;
	    
	    vector<pair<int, int>> v(n);
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>taskID;
	        cin>>v[i].second>>v[i].first;
	    }
	    
	    sort(v.begin(),v.end(),greater<pair<int, int>>());
	    vector<int> slot(n);

	    for(int i=0;i<n;i++)
	    {
	        for(int j=v[i].second;j>=1;j--)
	        {
	            if(slot[j]==0)
	            {
	                slot[j]=v[i].first;
	                deadline++;
	                profit+=v[i].first;
	                break;
	            }
	        }
	    }
		for (int i = 0; i < n; i++)
	{
		if (slot[i] != 0) {
			cout << slot[i] << " ";
		}
	}cout<<endl;

	    cout<<"maximum number of slot is: "<<deadline<<endl;
	    cout<<"Total maximum profit is " << profit <<endl;
	return 0;
}