#include <stdio.h>

void checkPalindromeNumber() {
    int num, originalNum, reversedNum = 0, remainder;

    printf("Enter the number: ");
    scanf("%d", &num);

    originalNum = num;

    while (num > 0) {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num = num / 10;
    }

    if (originalNum == reversedNum) {
        printf("Output: Palindrome\n\n");
    } else {
        printf("Output: Not Palindrome\n\n");
    }
}

int main() {
    checkPalindromeNumber();
    
    return 0;
}