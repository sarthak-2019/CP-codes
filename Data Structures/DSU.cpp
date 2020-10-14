const int N = 1e6 + 5;
// Array Containing parents of nodes
int parent[N];
// Number of nodes ponting to same parent
int size[N];
// To give number of coonected components in graph
int connected;
// Intialize Parent array


void make_parent(int num)
{
    for (int i = 1; i <=num; i++)
        parent[i] = i;
    for (int i = 1; i <=num; i++)
        size[i] = 1;
    connected = num;
}
// Finding the superparent by Path Compression
int find(int node)
{
    if (node == parent[node])
        return node;
    else
        return parent[node] = find(parent[node]);
}
void unite(int x, int y)
{
    int parent_x = find(x);
    int parent_y = find(y);
    if (parent_x != parent_y)
    {
        parent[parent_x] = parent[parent_y];
        size[parent_y] += size[parent_x];
        size[parent_x] = 0;
        connected--;
    }
}
