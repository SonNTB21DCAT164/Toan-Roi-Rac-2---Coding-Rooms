#include <bits/stdc++.h>

using namespace std;
#define pb push_back

struct edge{
	int u, v, w;	
};

int n;
int a[100][100], sz[100], parent[100];
vector<edge> canh;

void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j]!=0&&i<j)
				canh.pb({i, j, a[i][j]});
		}
	}
}

void make_set() // tao cac tap hop roi nhau
{
	for (int i=1;i<=n;i++)
	{
		parent[i]=i;	// ban dau moi phan tu dai dien cho chinh no
		sz[i]=1;		// ban dau moi tap hop chi co 1 phan tu
	}
}

int find(int v)	// tim phan tu dai dien cho 1 tap hop
{
	if (v==parent[v])
		return v;
	return parent[v]=find(parent[v]);
}

bool Union(int a, int b) // kiem tra xem co the gop 2 phan tu vao 1 tap hop hay ko
{
	a=find(a);
	b=find(b);
	if (a==b)
		return false; // khong the gop => tao thanh chu trinh
	if (sz[a]<sz[b])
		swap(a, b);
	parent[b]=a;
	sz[a]+=sz[b];
	return true;
}

bool cmp(edge a, edge b)
{
	if (a.w!=b.w)
		return a.w<b.w;
	else if (a.u!=b.u)
		return a.u<b.u;
	return a.v<b.v;
}

void kruskal()
{
	vector<edge> res; // khoi tao cay khung rong
	int s=0;		// do dai cay khung cuc tieu
	sort(canh.begin(), canh.end(), cmp);
	for (int i=0;i<canh.size();i++)
	{
		if (res.size()==n-1)
			break;
		edge a=canh[i];
		if (Union(a.u, a.v))
		{
			res.pb(a);
			s+=a.w;
		}
	}
	if (res.size()!=n-1)
		cout<<"Do thi khong lien thong";
	else
	{
		for (int i=0;i<res.size();i++)
			cout<<res[i].u<<" "<<res[i].v<<endl;
		cout<<s;
	}
}

int main()
{
	input();
	make_set();
	kruskal();
	return 0;
}
