#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

void solve(ll x)
{
	if(x==3) {cout<<4<<endl; return;}
	if(x<7) {cout<<"No such base"<<endl; return;}
	x=x-3;
	ll limit=(ll)sqrt(x);
	vector<ll> ans; 
	for(ll i=1;i<=limit;i++)
	{
		if(x%i==0){
		if(i>=4)
		{
			ans.push_back(i);
		}
		if(x/i >= 4)
		{
			ans.push_back(x/i);
		}
	}
	}
	ll min=ans[0];
	for(int i=1;i<ans.size();i++)
	{
		if(ans[i] < min) min=ans[i];
	}
	cout<<min<<endl;
}

int main()
{
	ll x;
	while(cin>>x) solve(x);
	return 0;
}
