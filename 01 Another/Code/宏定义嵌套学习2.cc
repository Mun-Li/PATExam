// example 2
#include <cstdio>
#define TO_STRING2(x) a_##x
#define TO_STRING1(x) #x
#define TO_STRING(x) TO_STRING1(x)

#define PARAM(x) #x
#define ADDPARAM(x) INT_##x
 
int main()
{
	const char *str = TO_STRING(TO_STRING2(PARAM(ADDPARAM(1))));
	printf("%s\n",str); //输出: a_PARAM(INT_1)
	return 0;
}


