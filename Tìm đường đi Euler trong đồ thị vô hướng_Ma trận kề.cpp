#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n;
int a[100][100];
vector<int> v, ce;

void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	}
}

void checkDegree()
{
	for (int i=1;i<=n;i++)
	{
		int s=0;
		for (int j=1;j<=n;j++)
			s+=a[i][j];
		if (s%2)
			v.pb(i);
	}	
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

void solve()
{
	checkDegree();
	if (v.size()!=0&&v.size()!=2)
		cout<<"Khong co duong di Euler";
	else
	{
		dfs(v[0]);
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
