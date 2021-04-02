// Priority Queue To sort in ascending order as per a 
// If a will be equal then it will sort in ascending order as per b
struct help
{
  int a;
  int b;
};
struct compare {
  bool operator()(help p1, help p2)
  {
    if (p1.a == p2.a)
      return p1.b > p2.b;
    else
      return p1.a > p2.a;
  }
};
void solve ()
{
  priority_queue<help, vector<help>, compare >pq;
}


// Ques ---https://codeforces.com/problemset/problem/962/D
