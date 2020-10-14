// Code as per 1 based indexing for Query and update operations
struct data
{
    //Use required attributes
    int x;

    //Default Values
    data() : x(1e11) {};
};
struct segtree
{
    int N;
    vector<data> seg;
    void fill(int n)
    {
        N = n;
        seg.resize(4 * n + 5);
    }

    // Chnage this Unite funtion as per ques
    void unite(data &par, data &l, data &r)
    {
        par.x = min(l.x, r.x);
    }

    void build(int *A, int l, int r, int ind)
    {
        if (l == r) {
            seg[ind].x = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(A, l, mid, 2 * ind);
        build(A, mid + 1, r, 2 * ind + 1);
        unite(seg[ind], seg[2 * ind], seg[2 * ind + 1]);
    }

    data range_query(int ind, int l, int r, int i, int j)
    {
        if (i <= l && j >= r)
            return seg[ind];
        if (i > r || j < l)
            return data();

        int mid = (l + r) / 2;
        data left = range_query(2 * ind, l, mid, i, j);
        data right = range_query(2 * ind + 1, mid + 1, r, i, j);
        data cur;
        unite(cur, left, right);
        return cur;
    }

    void point_update(int ind, int l, int r, int pos, int val)
    {
        // Leaf Node
        if (pos > r || pos < l)
            return;
        // Change as per reqirement of ques
        if (l == r) {
            seg[ind].x = val;
            return;
        }
        int mid = (l + r) / 2;
        point_update(2 * ind, l, mid, pos, val);
        point_update(2 * ind + 1, mid + 1, r, pos, val);
        unite(seg[ind], seg[2 * ind], seg[2 * ind + 1]);
    }

    data query(int i, int j)
    {
        return range_query(1, 1, N, i, j);
    }
    void update(int pos, int val)
    {
        point_update(1, 1, N, pos, val);
    }
};
