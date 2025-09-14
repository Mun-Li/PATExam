#include<cstdio>

int main()
{
    int n = 0;

    scanf("%d", &n);
    if (n < 0) {
        printf("Negative Number");
    } else if (n % 2 == 0) {
        printf("Even Number");
    } else {
        printf("Odd Number");
    }
    
    return 0;
}
