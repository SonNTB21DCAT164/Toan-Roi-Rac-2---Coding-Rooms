#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n, u;
int a[100][100], check[100];
vector<int> adj[100];
vector<pair<int, int>> v;

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
	cin>>u;
}

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	check[u]=1;
	while (!q.empty())
	{
		int k=q.front();
		q.pop();
		for (int i=0;i<adj[k].size();i++)
		{
			if (!check[adj[k][i]])
			{
				q.push(adj[k][i]);
				check[adj[k][i]]=1;
				v.pb({k, adj[k][i]});	
			}
		}
	}	
}

int main()
{
	input();
	bfs(u);
	if (v.size()<n-1)
		cout<<"Do thi khong lien thong";
	else
	{
		for (auto i:v)
			cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}
