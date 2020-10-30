/* Author VS_CODE */

#include<bits/stdc++.h>
#define int long long
#define TCI int t;cin>>t;while(t--)
#define run(n) for(int i=1;i<=n;i++)
#define cinl for(int i=0;i<n;i++)
#define ln "\n"
#define vpair vector< pair <int , int > >
#define fr first
#define sc second
#define pb emplace_back
#define vint vector<int>
using namespace std;

void online()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/* CODE STARTS HERE */
void multiply(vint &V,int &n, int num)
{
	int carry=0;
	for(int i=0;i<n;i++)
	{
		int pro=V[i]*num+carry;
		V[i]=pro%10;
		carry=pro/10;
	}

	while(carry!=0)
	{
		V[n]=carry%10;
		carry=carry/10;
		n++;
	}
}


void bigfactorial(int number)
{
	vint V(1000,0);
	V[0]=1;
	int n=1;
	for(int i=2;i<=number;i++)
	{
		multiply(V,n,i);
	}
	for(int i=n-1;i>=0;i--)
		cout<<V[i];
	cout<<ln;
	
}

void solve()
{
	int n;
	cin>>n;
	bigfactorial(n);
}

/* CODE ENDS HERE AND MAIN STARTS */

int32_t main()
{
	online();
	// TCIddddd
	solve();
}