#include <iostream>
#include <string>
#include <cmath>

using std::string;

/*
 * Chapter VI Big O - Example 12
 */


void permutation(string str, string prefix); // Forward Declaration for second function so first function knows it exists.

void permutation(string str)
{
	permutation(str, "");
}

void permutation(string str, string prefix)
{
	if (str.length() == 0)
		// Recursive case - stops the recursive function from being infinite
		printf("%s\n", prefix.c_str()); // O(n) time
	else
	{
		for (int i{ 0 }; i < str.length(); i++)
		{
			string rem = str.substr(0, i) + str.substr(i + 1);
			permutation(rem, prefix + str[i]); // This line and above take O(n) time combined due to string concatenation

			// Each node in our tree corresponds to O(n) work.

			// Picturing the function calls is interesting. Huge tree created.

			// Example str "alex": we branch 3 times from root - "alex" - then three times from each node. Then 2 times. Then 1 time.
			// Gives us 4 * 3 * 2 * 1 leaf nodes or n! (n factorial).

			// Each leaf node is attached to path with n nodes. At most n * n! nodes. (fewer than that in fact)

			// TOTAL WORST RUNTIME (Upperbound) = O(n * n * n!) == O( (n + 2)! ) != O(n!). Most interviews would expect you to get this far at most.

			// We can get tighter bound, but I am going to stop here for now. Has to do with Euler's Number (e) which we can drop some constants and get runtime of O (n * n!) == O( (n + 1)! )
		}
	}
}



int main()
{
	string str = "alex";
	permutation(str);
	printf("Number of permutations for string of length %i: %i", str.length(), (int)std::tgammaf(str.length() + 1));
	//tgamma calculates factorial of n - 1 so add 1 to length
}