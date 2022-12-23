/*
▶ 중첩 반복문

▶ break와 continue
break문은 가장 가까운 반복문이나 switch~case문 하나를 빠져나간다.
continue문은 가장 가까운 반복문의 블럭 끝으로 이동한다. 반복문을 빠져나간 것이 아니기 때문에 continue문을 만나면 아래의 코드는 실행하지 않고 바로 반복문의 마지막으로 이동하는 것이다.
*/

#include <stdio.h>

int main(void)
{
	/*** 중첩반복문 ***/
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("*");
		printf("\n");
	}
	printf("\n");

	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
			printf("%d * %d = %d\n", i, j, i * j);
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	printf("\n");

	/*** break와 continue ***/
	int a = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == 3)
			break; // for문을 빠져나간다. 즉, i가 3이 되면 for문이 끝난다.
		a++;
	}
	printf("%d\n", a); // a++을 세 번 실행

	a = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == 3)
			continue; // 아래의 코드를 건너뛰고 반복문의 마지막으로 이동한다. 즉, i가 3이면 a++;을 실행하지 않고 건너뛴다.
		a++;
	}
	printf("%d\n", a); // a++을 i가 3일 때를 제외한 9번 실행

	return 0;
}