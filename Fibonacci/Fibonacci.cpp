#include <iostream>
#include <vector>
using std::vector;
/*
 * Chapter VI Big O - Example 13 (calculate single fib number) and Example 14 (Printing all Fib numbers)
 * We can use the pattern established earlier for recursive calls O(branches ^ depth)
 */

int fib(int n)
{
	// Calculates Fibonacci number of n
	if (n <= 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2); // Two branches per call; Therefore runtime is O(2^depth) O(2 ^ n). This would suffice in interview.

	// We could get tighter runtime using very complicated math. It's actually closer to O(1.6 ^ n). The reason its not 2 is because at the bottom of the call stack, there is sometimes only 1 call. A lot of nodes are at the bottom (as in most trees). Single vs double call makes big difference

	// Generally algos with multiple recursive calls, expect exponential runtime.
}

void allFib(int n)
{
	// What is the time complexity?
	// My initial thoughts: runtime is going to be O(n) to print the numbers
	for (int i{ 0 }; i <= n; i++)
	{
		printf("%i ", fib(i)); // the call to calculate the Fibonacci number is still O(2 ^ n)
	}

	// Therefore, the runtime would be O(n) * O(2 ^ n) == O(n * 2 ^ n). Can we drop n?
	// This was my rushed conclusion, and the book specifically says it's a common mistake

	// The error in this logic is that n is changing. fib(n) takes O(2^n) time, but it depends what the value of n is.
	/* Let's walk through calls:
	 * fib(1) -> 2^1 steps
	 * fib(2) -> 2^2 steps
	 * fib(n) -> 2^n steps
	 * Therefore, total work = 2^1 + 2^2 + 2^3 + ... + 2^n
	 * Refer to pg 45. This is a 2^(n+1) - 2 algo.
	 * Therefore, runtime for this (horrible) algo is still O(2^n)
	 */
}

/*
 * Example 15: Let's cache the previously computed values in an array. If the number has been computed, just return the cache. What is runtime now?
 * I got quite a bit carried away tinking with this caching code to make it work correctly in C++. This is my solution to cache probably a better way
 * Messed around in debugger and memory view to see the array caching the values as you step through. One thing I miss about C++ is looking through the memory and assembly code created. But in c#, I can basically look at decompile the source code almost perfect compared to even the most complex recursive descent algorithms used by PE decompilers like Ida Pro.
 */

int fibCache(int n, vector<int>* memo)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	try
	{
		if (memo->at(n - 2) > 0)
			return memo->at(n - 2); // subtract two because caching starts at number 2
	}
	catch(std::exception e)
	{
		// The at method of std::vector class checks whether n is out of bounds. If so exception is thrown.
		// Catch the exception and continue.
		std::cerr << e.what() <<  " | Caching: ";
	}

	memo->push_back(fibCache(n - 1, memo) + fibCache(n - 2, memo)) ;
	return memo->back();
}

void allFibCache(int n)
{
	vector<int> memo;
	for(int i = 0; i < n; i++)
	{
		printf("%i: %i\n", i, fibCache(i, &memo));
	}
}



int main()
{
	allFibCache(23);
}
