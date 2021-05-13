int countDerangements(int n)
{
  if (n == 1) return 0;
  if (n == 2) return 1;
  return (n - 1) * (countDerangements(n - 1) + countDerangements(n - 2));
}



// https://codeforces.com/problemset/problem/888/D
