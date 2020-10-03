#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define TC ll t;cin>>t; for(ll _ = 1;_ <=t;_ ++)
#define bs binary_search
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define vvll vector<vector<ll>>
#define sll stack<ll>
#define qll queue<ll>
#define vll vector<ll>
#define vpll vector<pll>
#define vc vector <char>
#define F first
#define S second
#define MOD 10e9 + 7
#define mxn 10e18
#define ln "\n"
#define print cout<<"Case #"<<_<<": "<<ans<<ln;

using namespace std;

void merge(ll arr[] , ll s , ll e)
{
	ll m = (s + e )/2;
	ll i = s ;
	ll j =  m + 1;
	ll k = 0;
	ll temp[e -  s + 1];

	while(i <= m && j <= e)
	{
		if(arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	while(i <= m)
	{
		temp[k++] = arr[i++];
	}

	while( j <= e)
	{
		temp[k++] =  arr[i++];
	}

	ll x =  s;
	while(x <= e)
	{
		arr[x] = temp[x -  s];
		x++;
	}
}

void mergesort(ll arr[] , ll s , ll e)
{
	if(s >= e)
		return;
	ll m = (s + e) / 2;

	mergesort(arr , s , m);
	mergesort(arr, m + 1 , e);
	merge(arr , s , e);

}

void solve()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i = 0 ; i < n ; i++)
	{
		cin>>arr[i];	
	}

	mergesort(arr, 0 , n-1);


	cout<<"\nAfter Sorthing >> ";

	for(ll i = 0 ; i < n; i++)
	{
		cout<<arr[i]<<", ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
	return 0;
}
