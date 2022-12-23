/*
입력한 양수의 개수를 저장하기 위한 변수는 main.c의 전역변수 cnt를 공유하여 사용하도록 선언했고, 입력한 양수의 합을 누적하기 위한 전역변수 tot를 선언하였다.
main 함수에서 전역변수 tot가 있지만 static 키워드를 사용하여 사용범위를 제한했기 때문에 이 파일에서는 main 함수의 tot 변수를 사용할 수 없다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int cnt;         // main.c 파일에 선언된 전역변수 cnt 공유
int tot = 0;            // 전역변수 tot 선언

int input_data2(void)
{
	int pos;            // 양수 저장

	while (1)
	{
		printf("양수 입력: ");
		scanf("%d", &pos);
		if (pos < 0) break;
		cnt++;
		tot += pos;
	}

	return tot;
}