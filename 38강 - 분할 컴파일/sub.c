/*
sub.c를 작성하여 ctrl + f7을 눌러 컴파일하면 "C:\Users\ms785\source\repos\38강 - 분할 컴파일\38강 - 분할 컴파일\Debug"에 sub.obj의 개체 파일이 생성된다. main.c 역시 작성 후 컴파일하면 main.obj라는
개체 파일이 생성된다. 두 개체 파일을 link하면 하나의 실행파일이 만들어진다. 실행파일은 "C:\Users\ms785\source\repos\38강 - 분할 컴파일\Debug"에 38강 - 분할 컴파일.exe로 생성된다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_data(int* pa, int* pb)
{
	printf("두 정수 입력 : ");
	scanf("%d%d", pa, pb);
}

double average(int a, int b)
{
	return (a + b) / 2.0;
}