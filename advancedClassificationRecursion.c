#include <math.h>
#include "NumClass.h"
int reverseNum(int);
int createArmstrong(int, int);

int isPalindrome(int num) {
    if (num < 0)
        return 0;
    if (num == reverseNum(num))
        return 1;
    return 0;
}

int reverseNum (int num) {
    if (num == 0)
        return 0;
    int numLength = (int) log10(num);
    return (int) ((num % 10) * pow(10, numLength)) + reverseNum(num / 10);
}

int isArmstrong (int num) {
    if (num < 0)
        return 0;
    if (num == createArmstrong(num, (int) log10(num) + 1))
        return 1;
    return 0;
}

int createArmstrong (int num, int numLength) {
    if (num == 0)
        return 0;
    return (int) pow(num % 10, numLength) + createArmstrong(num / 10, numLength);
}