#define _CRT_SECURE_NO_WARNINGS 

#include "Stack.h"

//void Test1(ST* pst)
//{
//	STInis(pst);
//	STPush(pst, 1);
//	STPush(pst, 2);
//	STPush(pst, 3);
//	STPush(pst, 4);
//
//	printf("%d\n", STTop(pst));
//
//	STPop(pst);
//	printf("%d\n", STTop(pst));
//
//	STPop(pst);
//	printf("%d\n", STTop(pst));
//
//
//	bool ret = STEmpty(pst);
//	if (ret)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//
//	printf("%d\n",STSize(pst));
//
//	STDestroy(pst);
//}

void Test2(ST * pst)
{
	STInis(pst);
	/*STPush(pst, 1);
	STPush(pst, 2);
	STPush(pst, 3);
	STPush(pst, 4);*/

	for (int n = 1; n <= 4; n++)
	{
		STPush(pst, n);
		printf("%d ", STTop(pst));
	}

	printf("\n");

	//访问栈中所有元素
	while (!STEmpty(pst))
	{
		printf("%d ", STTop(pst));
		STPop(pst);
	}

	//
	//入栈顺序不一定是出栈顺序，可以边入边出
	//

	STDestroy(pst);
}

int main()
{
	ST pStack;
	
	//Test1(&pStack);
	Test2(&pStack);

	return 0;
}