#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

ll r,n,w,h;

ll xabs(ll x)
{
	if(x>0) return x;
	return -x;
}

ll xmax(ll x,ll y)
{
	if(x>y) return x;
	return y;
}

class point
{
	public:
	ll x,y;
	point(ll x,ll y) {this->x=x;this->y=y;}
	bool can(point &p)
	{
		ll left,right;
		left=r*xabs(p.x - this->x);
		right=xabs(p.y - this->y);
		if(left <= right) return true;
		return false;
	}
};

bool cmp(const point &p,const point &q)
{
	return (p.y < q.y);
}

int main()
{
	cin>>n>>r>>w>>h;
	vector<point> P;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		point temp(x,y);
		P.push_back(temp);
	}
	sort(P.begin(),P.end(),cmp);
	ll dp[n];
	//for(int i=0;i<P.size();i++) cout<<P[i].x<<" "<<P[i].y<<endl;
	for(int i=P.size()-1;i>=0;i--)
	{
		int m=1;
		for(int j=i+1;j<P.size();j++)
		{
			if(P[i].can(P[j]))
			{
				m=xmax(m,dp[j]+1);
			}
		}
		dp[i]=m;
	}
	int m=dp[0];
	for(int i=1;i<P.size();i++)
	{
		m=xmax(m,dp[i]);
	}
	cout<<m<<endl;
	return 0;
}
