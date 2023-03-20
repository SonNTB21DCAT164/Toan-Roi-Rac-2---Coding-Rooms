#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n;
int a[100][100], check[100];
vector<int> res;

void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	}
}

bool checkDegree()
{
	int tam=0;
	for (int i=1;i<=n;i++)
	{
		int s=0;
		for (int j=1;j<=n;j++)	
			s+=a[i][j];
		if (s%2)
			tam++;
	}	
	return tam==0||tam==2;
}

void dfs(int u)
{
	check[u]=1;
	res.pb(u);
	for (int i=1;i<=n;i++)
	{
		if (!check[i]&&a[u][i])
			dfs(i);	
	}	
}

bool tplt()
{
	memset(check, 0, sizeof(check));	
	res.clear();
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (!check[i])
		{
			ans++;
			dfs(i);
		}
	}
	return ans==1;
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
