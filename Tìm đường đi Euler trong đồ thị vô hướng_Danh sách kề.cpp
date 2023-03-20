#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n;
int a[100][100];
set<int> s[100];
vector<int> v, ce;

void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j])
				s[i].insert(j);
		}
	}	
}

void checkDegree()
{
	for (int i=1;i<=n;i++)
	{
		if (s[i].size()%2)
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
		if (s[k].size()!=0)			// neu danh sach ke cua k van con phan tu
		{
			int x=*s[k].begin();	// lay ra phan tu dau tien trong danh sach ke cua k
			st.push(x);
			s[k].erase(x);			// line 44, 45: xoa canh (x, k)
			s[x].erase(k);			
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
