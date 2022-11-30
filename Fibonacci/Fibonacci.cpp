#include <iostream>

/*
 * Chapter VI Big O - Example 13
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

int main()
{
	printf("%i", fib(17));
}
