#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
#define ll long long

ll xabs(ll x)
{
	if(x>0) return x;
	return -x;
}

class point
{
	public:
	ll x,y;
	point(ll x,ll y) {this->x=x;this->y=y;}
	ll dist(point &b)
	{
		return (xabs(this->x - b.x) + xabs(this->y - b.y));
	}
};

int main()
{
	vector<point> Q;
	string s;
	int row=0;
	while(cin>>s)
	{
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='x')
			{
				point temp(row,i);
				Q.push_back(temp);
			}	
		}
		row++;
	}
	set<ll> S;
	for(int i=0;i<Q.size();i++)
	{
		for(int j=i+1;j<Q.size();j++)
		{
			ll temp=Q[i].dist(Q[j]);
			S.insert(temp);
		}
	}
	cout<<S.size()<<endl;
}
