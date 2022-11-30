#include <iostream>

/*
 * Chapter VI Big O - Example 16
 * What is the runtime of this function?
 *
 * Algo Walkthrough:
 * powersOf2(50)
 *		-> powersOf2(50)
 *			 powersOf2(25)
 *				-> powersOf2(12)
 *					-> powersOf2(6)
 *						-> powersOf2(3)
 *							-> powersOf2(1)
 *								-> print and return 1
 *							print and return 2
 *						print and return 4
 *					print and return 8
 *				print and return 16
 *			print and return 32
 *
 *	The runtime is the number of times we can divide n by 2 until we get to best case (1).
 *	This means O(log n) runtime.
 *	Algo prints a value each time it is called. # of prints = # of calls
 *	Therefore, the number of times the function is called must equal the number of powers of 2 between 1 and n.
 *
 *	There are Log n powers of 2 between 1 and n. Therefore, Runtime of O(log n)
 *	How does the runtime change as N gets bigger. Runtime increase by 1 each time N doubles in size.
 *	The number of calls is x in this equation: 2^x = N. This is what a Log is.
 */			

int powersOf2(int n)
{
	// Function prints powers of 2 from [1,n]
	if (n < 1) return 0;
	if(n == 1)
	{
		printf("1\n");
		return 1;
	}

	int prev = powersOf2(n / 2);
	int curr = prev * 2;
	printf("%i\n", curr);
	return curr;
}

int main()
{
	int powOf2 = powersOf2(524288);
}
