#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n;
int a[100][100], check[100];
vector<int> adj[100];
vector<int> res;

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

bool checkDegree()
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
		if (d!=adj[i].size())
			return false;
	}
	return true;
}

void dfs(int u)
{
	check[u]=1;
	res.pb(u);
	for (int i=0;i<adj[u].size();i++)
	{
		if (!check[adj[u][i]])
			dfs(adj[u][i]);	
	}	
}

bool tplt()
{
	for (int i=1;i<=n;i++)
	{
		memset(check, 0, sizeof(check));
		res.clear();
		dfs(i);
		if (res.size()==n)
			return true;
	}	
	return false;
}

int main()
{
	input();
	if (checkDegree()&&tplt())
		cout<<"La do thi Euler";
	else
		cout<<"Khong phai do thi Euler";
	return 0;
}