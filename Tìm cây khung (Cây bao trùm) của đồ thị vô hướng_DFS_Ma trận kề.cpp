#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n, u;
int a[100][100], check[100];
vector<pair<int, int>> v;

void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cin>>a[i][j];	
	}	
	cin>>u;
}

void dfs(int u)
{
	check[u]=1;
	for (int i=1;i<=n;i++)
	{
		if (!check[i]&&a[u][i])
		{
			v.pb({u, i});
			dfs(i);
		}
	}
}

int main()
{
	input();
	dfs(u);
	if (v.size()<n-1)
		cout<<"Do thi khong lien thong";
	else
	{
		for (int i=0;i<v.size();i++)
			cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}
