#include "bits/stdc++.h"
using namespace std;
bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.second.second > b.second.second;
}
int main(){
    int j;
    int n,c,s;
    int d=0,p=0;
    cin>>n;
    vector<pair<int, pair<int, int>>> v;
    for(int i =1; i<=n; i++){
        cin>>j>>c>>s;
        v.push_back(make_pair(j, make_pair(c,s)));

    }
    sort(v.begin(), v.end(), comp);
    /*for(int i = 0; i<v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
    }*/
     int slot[100]={0};
     int jobid[100]={0};

	    
	    
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=v[i].second.first;j>=1;j--)
	        {
	            if(slot[j]==0 & jobid[j]==0)
	            {
	                slot[j]=v[i].second.first;
                    jobid[j]=v[i].first;
	                d++;
	                p+=v[i].second.second;
	                break;
	            }
	        }
	    }
		cout<<"maximum number of slot is: "<<d<<endl;
		cout<<"the taken job_ids are: "<<endl;
		// for (int i = 0; i < n; i++){
		// 	if(slot[i]!=0){
		// 		cout<<slot[i]<<" ";
		// 	}
		// }
		// cout<<endl;
        for (int i = 0; i < n; i++){
			if(jobid[i]!=0 & slot[i]!=0){
				cout<<slot[i]<<"-->"<<jobid[i]<<endl;
			}
		}cout<<endl;
	    cout<<"Total maximum profit is: " << p <<endl;
	return 0;
}