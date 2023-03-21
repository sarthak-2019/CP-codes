#include <bits/stdc++.h>
using namespace std;

void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int i, j, p = 0,t = 0, h = 1;

	for (i = 0; i < M - 1; i++) // The value of h would be "pow(d, M-1)%q" 
		h = (h * d) % q; 

	// we Calculate the hash value of pattern and first window of text 
	for (i = 0; i < M; i++) { 
		p = (d * p + pat[i]) % q; 
		t = (d * t + txt[i]) % q; 
	} 

	//  we slide text one by one in the pattern
	for (i = 0; i <= N - M; i++) { 

		if (p == t) { 	//If the hash values match then only check for characters on by one 
			/* Check for characters one by one */
			for (j = 0; j < M; j++) { 
				if (txt[i + j] != pat[j]) 
					break; 
			} 


			if (j == M) // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
				printf("Pattern found at index %d \n", i); 
		} 
		
		if (i < N - M) { // now we Calculate hash value for next window of text:
			t = (d * (t - txt[i] * h) + txt[i + M]) % q; 


			if (t < 0) //if we get negative then 
				t = (t + q); 
		} 
	} 
} 

int main() 
{ 
	char txt[] = "ANOM is learning"; 
	char pat[] = "ANOM"; 
	int q = 101; 
  int d=256;
	search(pat, txt, q); 
	return 0; 
} 
