#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n;
int a[100][100], check[100];
vector<int> adj[100];

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
	int tam=0;
	for (int i=1;i<=n;i++)
	{
		if (adj[i].size()%2)
			tam++;
	}	
	return tam==0||tam==2;
}

void dfs(int u)
{
	check[u]=1;
	for (int i=0;i<adj[u].size();i++)
	{
		if (!check[adj[u][i]])
			dfs(adj[u][i]);
	}
}

bool tplt()
{
	int res=0;
	memset(check, 0, sizeof(check));
	for (int i=1;i<=n;i++)
	{
		if (!check[i])
		{
			res++;
			dfs(i);
		}
	}	
	return res==1;
}

int main()
{
	input();
	if (checkDegree()&&tplt())
		cout<<"La do thi nua Euler";
	else
		cout<<"Khong phai do thi nua Euler";
	return 0;
}
