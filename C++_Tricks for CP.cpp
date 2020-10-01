// Tricks for Competitive Programming

// To Check if the number is odd or even using bitwise


if (num & 1) 
   cout << "ODD"; 
else
   cout << "EVEN"; 

// End

// Fast Multiplication or Division by 2

n = n << 1;   // Multiply n with 2 
n = n >> 1;   // Divide n by 2 

// End

// Swapping Two Numbers using Xor

a ^= b; 
b ^= a; 
a ^= b;

// End

// Don't use strlen to traverse the string instead use

for(int i=0;s[i];i++)

// End

// Calculate Number of digits using log instead of using loop

int digits=log10(number)+1;

// End

// To check if a number is a power of Two

bool check(int N)
{
	return N && !(N&(N-1));
}

// End

// Built in algorithms for checking if a a array has positive or negative numbers

 // Checking if no element is negative 
none_of(arr, arr+size, [](int x){ return x<0; })? 
      cout << "No negative elements" : 
      cout << "There are negative elements"; 

 // Checking if any element is negative 
any_of(arr, arr+size, [](int x){ return x<0; })? 
          cout << "There exists a negative element" : 
          cout << "All are positive elements"; 

// Checking if all elements are positive 
all_of(arr, arr+size, [](int x) { return x>0; })? 
      cout << "All are positive elements" : 
      cout << "All are not positive elements"; 

// Note: Here size=the size of the declared Array arr.
// End

// Use Auto keyword instead of lengthy for loop in all Data Structures such as listed
// Power Of Auto

int A[n];
for(auto i:A)
{
	cout<<i<<" ";	
}

vector<int>V;
for(auto i:V)
{
	cout<<i<<" ";
}
set<int>st;
for(auto i:st)
{
	cout<<i<<" ";
}

map<int,int>mp;
for(auto i:mp)
{
	cout<<i.first<<" "<<i.second<<endl;
}

// Note: You can also change value of data structures using for auto loop
// For That You need to put a ampersand when declaring a auto keyword like this-
for(auto &i:name_of_the_data_structure)
	{}

// Note: Always make a habit to declare auto keyword in for loop with an ampersand
// End

// Get Rid of all the includes by using only one include

#include <bits/stdc++.h>

// End

// I see a lot of programmer code like this

pair<int, int> p;
vector<int> v;
// ...
p = make_pair(3, 4);
v.push_back(4); v.push_back(5);

//while you can just do that

pair<int, int> p;
vector<int> v;
// ...
p = {3, 4};
v = {4, 5};

//Use emplace_back instead of push_back

// Most of Programmer code-
vector<pair<int,int>>vec;
vec.push_back(make_pair(2,3));

//while you can just do that

vector<pair<int,int>>vec;
vec.emplace_back(2,3);

// End