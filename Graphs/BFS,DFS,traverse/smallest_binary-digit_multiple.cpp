// C++ code to get the smallest multiple of N with 
// binary digits only. 
#include <bits/stdc++.h> 
using namespace std; 

// Method return true if N has only 1s and 0s in its 
// decimal representation 
bool isBinaryNum(int N) 
{ 
	while (N > 0) 
	{ 
		int digit = N % 10; 
		if (digit != 0 && digit != 1) 
			return false; 
		N /= 10; 
	} 
	return true; 
} 

// Method return t % N, where t is stored as 
// a string 
int mod(string t, int N) 
{ 
	int r = 0; 
	for (int i = 0; i < t.length(); i++) 
	{ 
		r = r * 10 + (t[i] - '0'); 
		r %= N; 
	} 
	return r; 
} 

// method returns smallest multiple which has 
// binary digits 
string getMinimumMultipleOfBinaryDigit(int N) 
{ 
	queue<string> q; 
	set<int> visit; 

	string t = "1"; 

	// In starting push 1 into our queue 
	q.push(t); 

	// loop untill queue is not empty 
	while (!q.empty()) 
	{ 
		// Take the front number from queue. 
		t = q.front();	 q.pop(); 

		// Find remainder of t with respect to N. 
		int rem = mod(t, N); 

		// if remainder is 0 then we have 
		// found our solution 
		if (rem == 0) 
			return t; 

		// If this remainder is not previously seen, 
		// then push t0 and t1 in our queue 
		else if(visit.find(rem) == visit.end()) 
		{ 
			visit.insert(rem); 
			q.push(t + "0"); 
			q.push(t + "1"); 
		} 
	} 
} 

// Driver code to test above methods 
int main() 
{ 
	int N = 12; 
	cout << getMinimumMultipleOfBinaryDigit(N); 
	return 0; 
} 

