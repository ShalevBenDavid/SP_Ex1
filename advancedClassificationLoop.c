// Made by Shalev and Yuval
#include <math.h>
#include "NumClass.h"

int isPalindrome(int num) {
	if (num < 0)
		return 0;
	if (num == 0)
		return 1;
	int temp = num;
	int numLength = 0;
	while (temp != 0) {
		temp /= 10;
		numLength++;
	}
	int numArray[numLength];
	for (int i = 0; i < numLength; i++) {
		numArray[i] = num % 10;
		num /= 10;
	}
	for (int i = 0; i <= numLength / 2; i++) {
		if (numArray[i] != numArray[numLength-i-1])
				return 0;
	}
	return 1;
}

int isArmstrong (int num) {
    if (num < 0)
		return 0;
	if (num == 0)
		return 1;
	int temp = num;
	double numLength = 0;
	int sum = 0;
	while (temp != 0) {
		temp /= 10;
		numLength++;
	}
    temp = num;
	while (temp != 0) {
		sum += (int) pow((temp % 10), numLength);
		temp /= 10;
	}
	return (sum == num)? 1 : 0;
}