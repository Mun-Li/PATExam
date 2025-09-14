#include<cstdio>
int main()
{
    int n = 0;
    scanf("%d", &n);

    // switch case 语句都要不记得了哈哈
    // 只能是判断常量表达式一不一样, 而不是如if else那样呢
    // 每个case不需要大括号括起来, 但最后记得加break
    switch(n) {
        case 0:
            printf("Zero");
            break;
        case 1:
            printf("One");
            break;
        case 2:
            printf("Two");
            break;
        case 3:
            printf("Three");
            break;
        case 4:
            printf("Four");
            break;
        case 5:
            printf("Five");
            break;
        default:
            printf("Greater than 5");
            // break;  不需要break
    }
    return 0;
}
