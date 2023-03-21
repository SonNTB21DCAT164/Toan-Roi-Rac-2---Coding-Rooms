#include <bits/stdc++.h>

using namespace std;

int n, u;
int a[100][100], check[100], x[100];

void input()
{
	memset(check, 0, sizeof(check));
	memset(x, 0, sizeof(x));
	memset(a, 0, sizeof(a));
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	}	
	cin>>u;
	x[1]=u;
	check[u]=1;
}

void hamilton(int k)
{
	for (int i=1;i<=n;i++)
	{
		if (a[x[k-1]][i])
		{
			if (k==n+1&&i==x[1])
			{
				for (int j=1;j<=n;j++)
					cout<<x[j]<<" ";
				cout<<x[1]<<endl;
			}
			else if (!check[i])
			{
				x[k]=i;
				check[i]=1;
				hamilton(k+1);
				check[i]=0;
			}
		}
	}
}

int main()
{
	input();
	hamilton(2);
	return 0;
}
