#include <bits/stdc++.h>

using namespace std;

int n;
int a[100][100], check[100];

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
	for (int i=1;i<=n;i++)
	{
		int s=0;
		for (int j=1;j<=n;j++)
			s+=a[i][j];
		if (s%2)
			return false;
	}	
	return true;
}

void dfs(int u)
{
	check[u]=1;
	for (int i=1;i<=n;i++)
	{
		if (!check[i]&&a[u][i])
			dfs(i);
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
		cout<<"La do thi Euler";
	else
		cout<<"Khong phai do thi Euler";
	return 0;
}
