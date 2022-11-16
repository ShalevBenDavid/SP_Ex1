// Made by Shalev and Yuval
#include <math.h>
#include "NumClass.h"

int factorial (int n) {
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int isStrong (int num) {
    if (num <= 0) {
        return 0;
    }
    int temp = num;
    int sum = 0;
    while (temp != 0 ) {
        sum += factorial(temp % 10);
        temp = temp / 10;
    }
    return (sum == num) ? 1 : 0;
}

int isPrime (int num) {
    if (num < 1)
		return 0;
	for (int i = 2; i <= sqrt(num); i++)
		if (!(num % i))
			return 0;
	return 1;
}
