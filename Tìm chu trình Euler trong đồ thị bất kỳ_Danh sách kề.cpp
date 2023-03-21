#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n, u;
int a[100][100];
set<int> adj[100];
vector<int> ce;

void input()
{
	cin>>n;	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j])
				adj[i].insert(j);
		}
	}
	cin>>u;
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
			int x=*adj[k].begin();
			st.push(x);
			adj[k].erase(x);
			adj[x].erase(k);
		}
		else
		{
			ce.pb(k);
			st.pop();
		}
	}	
}

int main()
{
	input();
	dfs(u);
	for (int i=ce.size()-1;i>=0;i--)
		cout<<ce[i]<<" ";
	return 0;
}
