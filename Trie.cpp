typedef struct trie
{
	typedef struct node
	{
		node* nxt[2];
		int cnt = 0;

		node()
		{
			nxt[0] = nxt[1] = NULL;
			cnt = 0;
		}

	}Node;

	Node* head;

	trie() { head = new Node(); }

	void insert(int x)
	{
		Node* cur = head;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			if(!cur -> nxt[b])
				cur -> nxt[b] = new Node();
			cur = cur -> nxt[b];
			cur -> cnt++;
		}
	}

	void remove(int x)
	{
		Node* cur = head;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			cur = cur -> nxt[b];
			cur -> cnt--;
		}
	}

	int maxxor(int x)
	{
		Node* cur = head;
		int ans = 0;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			if(cur -> nxt[!b] && cur -> nxt[!b] -> cnt > 0)
			{
				ans += (1LL << i);
				cur = cur -> nxt[!b];
			}
			else
				cur = cur -> nxt[b];
		}
		return ans;
	}
}Trie;
