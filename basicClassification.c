// Made by Shalev and Yuval

#include <math.h>
#include "NumClass.h"

int isStrong (int num) {
  int sum = 0;
  while (num != 0 ) {
	  sum += factorial(num % 10);
	  num = num / 10;
  }
  return (sum == n) ? 1 : 0;
}

int factorial (int n) {
	int result = 1;
	for (int i = 2; i <= n; i++)
		result *= i;
	return result;
}

int isPrime (int num) {
	if (num < 1)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
		if (num % i == 0)
			return 0;
	return 1;
}
