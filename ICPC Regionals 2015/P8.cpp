#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

vector<ll> to(ll x)
{
	vector<ll> ans;
	while(x)
	{
		ans.push_back(x%10);
		x=x/10;
	}
	/*
	cout<<"printing ..." <<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<endl;
	*/
	return ans;
}

void solve(ll x)
{
	vector<ll> ans;
	cout<<x<<" ";
	ans=to(x);
	ll count=0;
	while(ans.size()!=1)
	{
		count++;
		ll temp=1;
		for(int i=0;i<ans.size();i++) temp=temp*ans[i];
		if(temp==0) break;
		ans.clear();
		ans=to(temp);
	}
	cout<<count<<endl;
}

int main()
{
	ll x;
	while(cin>>x) solve(x);
	return 0;
}
