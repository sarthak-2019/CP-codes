// Merge Sort tree to give number of elemets >=k in range(l,r)
struct mergesort_tree
{
    int N;
    vector<vector<int>> seg;
    void fill(int n)
    {
        N = n;
        seg.resize(4 * n + 5);
    }

    void build(int *A, int l, int r, int ind)
    {
        if (l == r) {
            seg[ind].pb(A[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(A, l, mid, 2 * ind);
        build(A, mid + 1, r, 2 * ind + 1);
        merge(seg[2 * ind].begin(), seg[2 * ind].end(), seg[2 * ind + 1].begin(), seg[2 * ind + 1].end(), back_inserter(seg[ind]));
    }

    int range_query(int ind, int l, int r, int i, int j, int k)
    {
        if (i <= l && j >= r)
            return seg[ind].size() - (lower_bound(seg[ind].begin(), seg[ind].end(), k) - seg[ind].begin());
        if (i > r || j < l)
            return 0;
        int mid = (l + r) / 2;
        int left = range_query(2 * ind, l, mid, i, j, k);
        int right = range_query(2 * ind + 1, mid + 1, r, i, j, k);
        return left + right;
    }
};
