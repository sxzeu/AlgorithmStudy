#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int output = 0;
    int i = 1;

    while (i <= n) 
    {
        output += (n - i + 1);
        i *= 10;
    }
    printf("%d\n", output);

    return 0;
}