// Made by Shalev and Yuval
#include <math.h>
#include "NumClass.h"
#include <stdbool.h>

int isPalindrome(int num) {
	if (num < 0)
		return false;
	if (num == 0)
		return true;
	int numLength = (int) log10(num) + 1;
	int numArray[numLength];
	for (int i = 0; i < numLength; i++) {
		numArray[i] = num % 10;
		num /= 10;
	}
	for (int i = 0; i <= numLength / 2; i++) {
		if (numArray[i] != numArray[numLength-i-1])
				return false;
	}
	return true;
}

int isArmstrong (int num) {
    if (num < 0)
		return false;
	if (num == 0)
		return true;
	int temp = num;
	double numLength = (int) log10(num) + 1;
	int sum = 0;
	while (temp != 0) {
		sum += (int) pow((temp % 10), numLength);
		temp /= 10;
	}
	return (sum == num)? true : false;
}