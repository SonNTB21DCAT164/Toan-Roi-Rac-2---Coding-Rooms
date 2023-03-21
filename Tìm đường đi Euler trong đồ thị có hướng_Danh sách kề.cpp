#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n;
int a[100][100];
vector<int> adj[100];
vector<int> v1, v2, ce;

void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j])
				adj[i].pb(j);	
		}	
	}	
}

void checkDegree()
{
	for (int i=1;i<=n;i++)
	{
		int d=0;
		for (int j=1;j<=n;j++)
		{
			for (int k=0;k<adj[j].size();k++)
			{
				if (adj[j][k]==i)
					d++;
			}
		}
		if (adj[i].size()-d==1||d-adj[i].size()==1)
			v1.pb(i);
		if (adj[i].size()==d)
			v2.pb(i);
	}
}

void dfs(int u)
{
	stack<int> st;
	st.push(u);
	while (!st.empty())
	{
		int k=st.top();
		if (adj[k].size())
		{
			int x=adj[k][0];
			st.push(x);
			adj[k].erase(adj[k].begin());
		}
		else
		{
			ce.pb(k);
			st.pop();
		}
	}
}

void solve()
{
	checkDegree();
	if (v1.size()!=2||v2.size()!=n-2)
		cout<<"Khong co duong di Euler";
	else
	{
		dfs(v1[0]);
		for (int i=ce.size()-1;i>=0;i--)
			cout<<ce[i]<<" ";	
	}	
}

int main()
{
	input();
	solve();
	return 0;
}
