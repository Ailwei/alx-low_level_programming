#include "main.h"

int _sqrt_recursive_helper(int n, int start, int end);

int _sqrt_recursion(int n)
{
	return _sqrt_recursive_helper(n, 0, n);
}

int _sqrt_recursive_helper(int n, int start, int end)
{
	if (start > end)
		return -1;

	int mid = start + (end - start) / 2;
	int square = mid * mid;

	if (square == n)
		return mid;
	else if (square < n)
		return _sqrt_recursive_helper(n, mid + 1, end);
	else
		return _sqrt_recursive_helper(n, start, mid - 1);
}
