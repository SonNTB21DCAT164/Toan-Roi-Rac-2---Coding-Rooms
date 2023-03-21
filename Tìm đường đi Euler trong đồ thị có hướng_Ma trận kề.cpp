#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n;
int a[100][100];
vector<int> v1, v2, ce;

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
	int tam1=0, tam2=0;
	for (int i=1;i<=n;i++)
	{
		int s1=0, s2=0;
		for (int j=1;j<=n;j++)
		{
			s1+=a[i][j];
			s2+=a[j][i];
		}
		if (s1-s2==1||s2-s1==1)
		{
			tam1++;
			v1.pb(i);
		}
		if (s1==s2)
		{
			tam2++;
			v2.pb(i);
		}
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
				a[k][i]=0;
				check=true;
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
