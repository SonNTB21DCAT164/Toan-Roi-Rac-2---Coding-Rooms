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
			tam1++;
		if (s1==s2)
			tam2++;
	}
	return (tam1==2&&tam2==n-2);
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
	for (int i=1;i<=n;i++)
	{
		memset(check, 0, sizeof(check));
		res.clear();
		dfs(i);
		if (res.size()==n)
			return true;
	}
	return false;
}

int main()
{
	input();
	if (tplt()&&checkDegree())
		cout<<"La do thi nua Euler";
	else
		cout<<"Khong phai do thi nua Euler";	
	return 0;
}
