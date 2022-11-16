// Made by Shalev and Yuval

#include <math.h>
#include "NumClass.h"

int isPalindrome(int num) {
	if (num < 0)
		return 0;
	if (num = 0)
		return 1;
	int temp = num;
	int numLength = 0;
	while (temp != 0) {
		num /= 10;
		numLength++;
	}
	int numArray[numLength];
	for (int i = 0; i < numLength; i++) {
		numArray[i] = num % 10;
		num /= 10;
	}
	for (int i = 0; i <= numlength / 2; i++) {
		if (numArray[i] != numArray[numLength-i-1])
				return 0;
	}
	return 1;
}

int isArmstrong (int num) {
	if (num < 0)
		return 0;
	if (num = 0)
		return 1;
	int temp = num;
	double numLength = 0;
	int sum = 0;
	while (temp != 0) {
		num /= 10;
		numLength++;
	}
	while (num != 0) {
		sum += pow((num % 10), numLength);
		num /= 10;
	}
	return (num == sum)? 1 : 0;
}
