#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n, u;
int a[100][100];
vector<int> ce;

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
	stack<int> st;
	st.push(u);
	while (!st.empty())
	{
		int k=st.top();
		bool check=false;
		for (int i=1;i<=n;i++)
		{
			if (a[k][i])
			{
				st.push(i);
				check=true;
				a[k][i]=a[i][k]=0;
				break;
			}	
		}	
		if (!check)
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
