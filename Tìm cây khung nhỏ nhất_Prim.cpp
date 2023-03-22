#include <bits/stdc++.h>

using namespace std;
#define pb push_back

struct edge{
	int u, v, w;	
};

int n, u;
int a[100][100], check[100];	// check=1 => dinh thuoc V(T)
								// check=0 => dinh thuoc V
vector<pair<int, int>> adj[100]; // danh sach ke co trong so cua n dinh

void input()
{
	memset(check, 0, sizeof(check));
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j])	
			{
				adj[i].pb({j, a[i][j]});
				adj[j].pb({i, a[i][j]});	
			}	
		}	
	}	
	cin>>u;
}

void prim(int k)
{
	vector<edge> res;	// cay khung rong
	int s=0;	// do dai cay khung cuc tieu
	check[k]=1;		// dua k vao V(T), loai k khoi V
	while (res.size()<n-1)
	{
		int x, y;	// 2 dinh can dua vao cay khung
		int z=INT_MAX;	// do dai canh nho nhat ung voi 2 dinh x, y
		for (int i=1;i<=n;i++)
		{
			if (check[i])	// neu i thuoc V(T)
			{
				for (pair<int, int> a : adj[i])	// duyet danh sach ke cua i
				{
					int j=a.first, trongso=a.second;
					if (!check[j] && trongso<z)	// neu j thuoc V va (i, j) la nho nhat 
					{
						z=trongso;
						x=j;	// tiep tuc duyet danh sach ke cua j
						y=i;	
					}
				}
			}
		}
		if (z==INT_MAX)
		{
			cout<<"Do thi khong lien thong";
			return;
		}
		res.pb({x, y, z});	// them canh (x, y) vao cay khung
		s+=z;		// cap nhat do dai cay khung
		check[x]=1;		// dua x vao V(T), loai x khoi V 
	}
	for (int i=0;i<res.size();i++)
	{
		if (res[i].u>res[i].v)
			swap(res[i].u, res[i].v);
		cout<<res[i].u<<" "<<res[i].v<<endl;
	}
	cout<<s;
}

int main()
{
	input();
	prim(u);
	return 0;
}
