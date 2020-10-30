  
struct Gauss 
{
	int bits = 60;
	vector<int> table;
	
	Gauss()
	{
		table = vector<int> (bits, 0);
	}

	Gauss(int _bits) 
	{
		bits = _bits;
		table = vector<int> (bits, 0);
	}
 
	int size() 
	{
		int ans = 0;
		for(int i = 0; i < bits; i++) 
		{
			if(table[i]) 
				ans++;
		}
		return ans;
	}
 
	bool can(int x) 
	{
		for(int i = bits - 1; i >= 0; i--) 
			x = min(x, x ^ table[i]);
		return x == 0;
	}
 
	void add(int x) 
	{
		for(int i = bits - 1; i >= 0 && x; i--) 
		{
			if(table[i] == 0) 
			{
				table[i] = x;
				x = 0;
			} 
			else 
				x = min(x, x ^ table[i]);
		}
	}
 
	int getBest() 
	{
		int x = 0;
		for(int i = bits - 1; i >= 0; i--) 
			x = max(x, x ^ table[i]);
		return x;
	}
 
	void merge(Gauss &other)
	{
		for(int i = bits - 1; i >= 0; i--)
			add(other.table[i]);
	}
};
