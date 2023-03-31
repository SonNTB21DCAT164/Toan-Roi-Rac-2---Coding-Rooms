#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ii pair<int, int> 

int n, s, t;
int a[100][100], d[100], truoc[100];
vector<ii> adj[100];
 
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j]!=0)
				adj[i].pb({j, a[i][j]});
		}	
	}
	cin>>s>>t;	
}

void dijkstra(int s)
{
	for (int i=1;i<=100;i++)
		d[i]=1e9;
	memset(truoc, 0, sizeof(truoc));
	d[s]=0;
	truoc[s]=-1;
	priority_queue<ii, vector<ii>, greater<ii>> q;
	q.push({0, s});
	while (!q.empty())
	{
		ii top=q.top();
		q.pop();
		int u=top.second;
		int dis=top.first;
		if (d[u]!=dis)	
			continue;
		for (int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i].first;
			int w=adj[u][i].second;
			if (d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push({d[v], v});
				truoc[v]=u;
			}
		}
	}	
	if (!truoc[t])
		cout<<"Khong ton tai duong di";
	else
	{
		int u=truoc[t];
		cout<<t<<" <- ";
		while (u!=s)
		{
			cout<<u<<" <- ";
			u=truoc[u];
		}
		cout<<s<<endl<<d[t];
	}
}

int main()
{
	input();
	dijkstra(s);
	return 0;
}
