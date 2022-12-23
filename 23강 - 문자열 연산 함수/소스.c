/*
문자열을 처리할 때는 함수를 이용한다. 문자열 연산 함수는 string.h에 선언되어 있다. 따라서 string.h를 include 해야 한다.

▶ strcpy(str1, str2):
strcpy 함수는 문자열이 저장될 위치의 주소값과, 문자열이 저장된 위치의 주소값을 인수를 받는다. 인수로 str1와 str2가 주어지면 strcpy 함수는 str2로 가서 주소연산을 하며 문자를 하나씩 읽어 str1에 저장한다. str2의 모든
문자를 복사하면 마지막에 NULL을 붙여준다. 그리고 복사받은 위치의 주소값, 즉 str1을 반환한다. 첫 번째 인수로는 문자열을 저장할 수 있는 char 배열의 배열명 또는 이 배열명을 저장하고 있는 char형 포인터 변수만 가능하다.
하지만 두 번째 인수로는 문자열의 위치값이면 모두 가능하다. 문자열이 저장된 배열의 배열명, 배열명을 저장하고 포인터, 문자열 상수, 문자열 상수의 주소값을 저장하고 있는 포인터가 가능하다.

▶ strncpy(str1, str2, n)
문자열 중 일부만 대입하는 함수이다. str2의 문자열 중 n개의 문자만 str1에 저장하며, 대입 후 마지막에 NULL문자를 붙이지 않는다. 주로 문자열의 일부만 수정하고 싶을 때 사용한다.

▶ strcat(str1, str2)
문자열 뒤에 다른 문자열을 이어주는 함수이다. str1 뒤에 str2를 이어서 붙인다. 즉, str1에서 NULL 문자를 찾아서, 그 위치에 str2에 저장된 문자열을 복사하여 저장한다. 이어붙이기를 완료한 후 마지막에 NULL을 붙인다.
strcat 함수는 str1에서 NULL 문자를 먼저 찾기 때문에 str1은 초기화 후 사용해야 한다.

▶ strncat(str1, str2, n)
문자열 중 일부만 이어주는 함수이다. str2의 문자열 중 앞에서 n개의 문자만 str1 뒤에 이어준다. 복사를 한 후 뒤에 NULL문자를 붙인다.

▶ strlen(str)
배열에 저장된 문자열의 길이를 int형으로 반환한다. sizeof 연산자는 배열 전체의 크기를 구하지만, strlen은 배열에 저장된 문자열의 길이를 구해준다. strlen 함수는 인수로 받은 str로 가서 NULL 문자를 만날 때까지 문자의
개수를 count하여 반환한다.

▶ strcmp(str1, str2)
두 문자열을 사전순으로 비교하는 함수이다. 비교할 때 아스키코드값을 사용한다. 두 문자열의 첫 번째 문자부터 문자가 서로 다를 때까지 계속해서 비교한다. 결과에 따라 다음과 같이 반환한다.
	str1 > str2  : 1 반환(str1이 사전에 늦게 나옴)
	str1 < str2  : -1 반환(str1이 사전에 먼저 나옴)
	str1 == str2 : 0 반환(두 문자열이 일치)

앞의 문자열에서 뒤의 문자열을 뺀 결과라고 생각하면 편하다. 이 함수를 다음과 같이 구현할 때 생길 수 있는 문제를 생각해보자.

	int my_strcmp(char* str1, char* str2)
	{
		while (*str1 == *str2)
		{
			str1++;
			str2++;
		}

		if (*str1 > * str2)     return 1;
		else if (*str1 < *str2) return -1;
		else					return 0;
	}

str1와 str2에 1씩 더하는 주소연산을 하면서 두 값이 가리키는 값이 서로 다를 때 while문을 빠져나와 다른 부분을 서로 비교하여 반환하도록 설계한 것이다. 하지만 비교하는 두 문자열이 완전히 같을 경우 NULL 문자를 만나도
멈추지 않고 계속해서 쓰레기값을 비교하게 된다. 때문에 *str1이 NULL이 되면, 즉 문자열이 끝나면 while문을 빠져나오도록 조건을 수정해야 한다. 위의 while문 조건은 두 문자가 서로 같고, str1이 끝나지 않은 동안 반복할 수
있도록 다음과 같이 작성해야 한다.

	int my_strcmp(char* str1, char* str2)
	{
		while ((*str1 == *str2) && (*str != '\0')) { ... }
		...
	}

이때 str1이 아니라 str2가 끝나지 않은 동안 반복을 하도록 작성해도 상관없다. 

▶ strncmp(str1, str2, n) 
두 문자열 중 앞에서 n개의 문자만 사전순으로 비교하는 함수이다. 반환값은 strcmp와 동일하다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* my_strcpy(char* str, char* str2);
char* my_strcat(char* str, char* str2);
int my_strlen(char* str);
int my_strcmp(char* str, char* str2);

int main(void)
{
	/*** strcpy 함수 ***/
	char str1[20] = "strawberry"; // 문자열이 저장될 공간
	char str2[20] = "banana";     // 복사될 문자열이 저장된 배열
	char* pstr = "peach";         // 문자열 상수를 저장하는 포인터 
	char* pstr2 = str2;           // 배열명을 저장하는 포인터

	strcpy(str1, "apple");	      // 문자열 상수
	strcpy(str1, str2);			  // 문자열이 저장된 배열의 배열명
	strcpy(str1, pstr);			  // 문자열 상수의 위치값을 저장하고 있는 포인터
	strcpy(str1, pstr2);		  // 배열명이 저장된 포인터

	/*** strcpy 함수 구현 ***/
	my_strcpy(str1, "apple");
	puts(str1);

	/*** strncpy 함수 ***/
	strcpy(str1, "mango tree");
	strncpy(str1, "apple pie", 5); // "apple pie" 중 앞에서 5문자인 "apple"만 str1에 저장한다. 복사 후 뒤에 NULL을 붙이지 않기 때문에 "mango tree"는 "apple tree"가 된다.
	puts(str1);

	/*** strcat 함수 ***/
	strcpy(str1, "apple");
	strcat(str1, " pie");
	puts(str1);

	/*** strcat 함수 구현 ***/
	strcpy(str1, "apple");
	my_strcat(str1, " pie");
	puts(str1);

	/*** strlen 함수 ***/
	char str[50];
	printf("문자열 입력: ");
	gets(str);
	int len = strlen(str);
	printf("len : %d\n", len);

	/*** strlen 구현 ***/
	int my_len = my_strlen(str);
	printf("my_len : %d\n", my_len);

	/*** strcmp 함수 ***/
	strcpy(str1, "pear");
	strcpy(str2, "peach");
	int cmp = strcmp(str1, str2);
	switch (cmp)
	{
	case 1:
		printf("%s는 %s보다 사전에 늦게 나온다.\n", str1, str2);
		break;
	case -1:
		printf("%s는 %s보다 사전에 먼저 나온다.\n", str1, str2);
		break;
	case 0:
		printf("%s와 %s는 같다.\n", str1, str2);
	}

	/*** strcmp 함수 구현 ***/
	int my_cmp = my_strcmp(str1, str2);
	printf("my_cmp : %d\n", my_cmp);

	return 0;
}

char* my_strcpy(char* str1, char* str2)
{
	char* po = str1;
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';

	return po;
}

char* my_strcat(char* str1, char* str2)
{
	char* po = str1;

	while (*str1 != '\0') str1++;
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';

	return po;
}

int my_strlen(char* str)
{
	int cnt = 0;
	while (*str != '\0')
	{
		cnt++;
		str++;
	}

	return cnt;
}

int my_strcmp(char* str1, char* str2)
{
	while ((*str1 == *str2) && (*str1 != '\0'))
	{
		str1++;
		str2++;
	}

	if (*str1 > * str2)
		return 1;
	else if (*str1 < *str2)
		return -1;
	else
		return 0;
}