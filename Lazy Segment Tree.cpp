#include <bits/stdc++.h>
using namespace std;
#define endl            "\n"
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define bs              binary_search
#define pqb             priority_queue<int>
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define pi              3.14159265358979323846
#define ps(x,y)         fixed<<setprecision(y)<<x
#define test(x)         int x; cin>>x; while(x--)
void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
// int pow(int a, int b)
// {
// 	int res = 1;
// 	while (b > 0)
// 	{
// 		if (b % 2)
// 			res = (res * a);
// 		a = (a * a);
// 		b >>= 1;
// 	}
// 	return res;
// }
/****************CODE BEGINS**************/
int lazy[100] = {0};
void build_tree(int *A, int l, int u, int *tree, int ind)
{
	if (l == u) {
		tree[ind] = A[l];
		return;
	}
	int mid = (l + u) / 2;
	build_tree(A, l, mid, tree, 2 * ind);
	build_tree(A, mid + 1, u, tree, 2 * ind + 1);
	tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
	return;
}
void updates(int *tree, int ss, int se, int l, int u, int val, int ind)
{
	if (lazy[ind] != 0)
	{
		tree[ind] += (se - ss + 1) * lazy[ind];
		if (ss != se)
		{
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	if (l > se || u < ss)
		return;
	if (l <= ss && se <= u)
	{
		tree[ind] += (se - ss + 1) * val;
		if (ss != se)
		{
			lazy[2 * ind] += val;
			lazy[2 * ind + 1] += val;
		}
		return;
	}
	int mid = (ss + se) / 2;
	updates(tree, ss, mid, l, u, val, 2 * ind);
	updates(tree, mid + 1, se, l, u, val, 2 * ind + 1);
	tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
	return;
}
int query(int *tree, int ss, int se, int l, int u, int ind)
{
	if (lazy[ind] != 0)
	{
		tree[ind] += (se - ss + 1) * lazy[ind];
		if (ss != se)
		{
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	if (l > se || u < ss)
		return 0;
	if (l <= ss && se <= u)
	{
		return tree[ind];
	}
	int mid = (ss + se) / 2;
	int left = query(tree, ss, mid, l, u, 2 * ind);
	int right = query(tree, mid + 1, se, l, u, 2 * ind + 1);
	return (left + right);
}
void solve()
{
	int num;
	cin >> num;
	int A[num];
	for (int i = 0; i < num; i++)
		cin >> A[i];
	int *tree = new int[4 * num + 1];
	build_tree(A, 0, num - 1, tree, 1);
	int q;
	cin >> q;
	while (q--)
	{
		int k;
		cin >> k;
		if (k == 1)
		{
			int x, y;
			cin >> x >> y;
			cout << query(tree, 0, num - 1, x, y, 1) << endl;
		}
		if (k == 2)
		{
			int x, y, val;
			cin >> x >> y >> val;
			updates(tree, 0, num - 1, x, y, val, 1);
		}
	}
}
int32_t main()
{
	c_p_c();
	// test(x)
	solve();
	return 0;
}