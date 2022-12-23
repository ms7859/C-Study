/*
▶ 이미 정의된 매크로(__FILE__, __FUNCTION__ 등)
#define을 이용하여 매크로 상수나 매크로 함수를 만들어 쓸 수 있다. 하지만 이미 컴파일러에 정의되어 있어서 그 내용을 바꾸거나 지울 수 없는 매크로가 있다. 
	__DATE__ : 컴파일을 시작한 날짜
	__TIME__ : 컴파일을 시작한 시간
	__FILE__ : 컴파일하는 파일명
	__FUNCTION__ : 매크로명이 사용된 함수
	__LINE__ : 행 번호

위의 매크로들 중 LINE과 FILE 매크로는 우리가 원하는 방식대로 사용할 수 있다. 이때 #line 지시자를 사용한다. #line를 사용하여 __LINE__의 행 번호의 시작값만 설정할 수도 있고, 행 번호의 시작값과 __FILE__이 치환되는 값을 같이 지정할 수도 있다. 하지만
__FILE__의 값만 바뀌도록 지정할 수는 없다. 아래의 첫 번째 문장은 __LINE__의 행 번호 시작값을 지정한 것이며, 두 번째 문장은 __LINE__의 행 번호 시작값과 __FILE__이 치환되는 파일의 이름을 모두 설정한 것이다. 이때 #line을 이용해 행번호를 지정해주는
것은 #line이 사용된 다음 행의 번호를 지정한 숫자로 계산한다. 아래의 코드에서 두 번째 문장에 의해 printf가 있는 문장의 행 번호는 100으로 계산된다. 때문에 출력값은 100이 된다.

	#line 100
	#line 100 "macro.c"
	printf("%d", __LINE__);

▶ 매크로 함수 연산자 #과 ##
매크로 함수를 만들 때 연산과 #과 ##를 사용할 수 있다.
	#  : 매크로 함수의 인수를 문자열로 치환한다.
	## : 두 인수를 붙여서 치환한다.

아래의 코드는 # 연산자를 이용해 매크로 함수 PRINT_EXPR(x)을 정의하였다. 이때 인수 x 앞에 #을 적어 x가 문자열 형태로 치환되도록 했다.

	#define PRINT_EXPR(x) printf(#x "= %d\n", x);

	int main(void)
	{
		int a = 10, b = 20;
		PRINT_EXPR(a + b);
		...
	}

이때 위와 같이 PRINT_EXPR이 호출되면 앞의 x는 "a + b"가 문자열로 치환되고 뒤의 x에는 a + b가 그대로 치환된다. 때문에 전처리과정이 끝나면 컴파일러가 컴파일할 코드는 아래와 같이 바뀐다.

	int main(void)
	{
		int a = 10, b = 20;
		printf("a + b" "= %d\n", a + b);
		...
	}

컴파일러는 문자열이 연속으로 사용하면 두 문자열을 붙여서 하나의 문자열처럼 번역한다. 즉 위의 코드는 아래의 코드처럼 번역된다.

	int main(void)
	{
		int a = 10, b = 20;
		printf("a + b = %d\n", a + b);
		...
	}

또한 아래의 코드는 ## 연산자를 이용해 매크로 함수 NAME_CAT(x, y) 함수를 선언하였다. ## 연산자는 두 인수를 붙여서 하나의 토큰으로 바꾼 후 치환한다.

	#define NAME_CAT(x, y) (x ## y)

	int main(void)
	{
		int a1, a2;
		NAME_CAT(a, 1) = 1;
		NAME_CAT(a, 2) = 2;
		...
	}

아래와 같이 매크로 함수를 사용하면 a와 1을 붙여서 치환하고 a와 2를 붙여 치환해 아래의 코드와 같이 바뀐다. 즉 변수 a1과 a2에 각각 1과 2를 대입할 수 있다.

	int main(void)
	{
		int a1, a2;
		a1 = 1;
		a2 = 2;
		...
	}

▶ 조건부 컴파일 지시자
조건부 컴파일 지시자는 코드 중 일부를 조건에 따라 선택적으로 컴파일할 수 있도록 해준다. 조건부 컴파일 지시자에는 #if, #else, #elif, #ifndef, #endif 등이 있다. 아래의 코드에서 조건식 1이 참이면 #if와 #elif 사이의 문장, 즉 컴파일할 문장 1을
컴파일한다. 또한 조건식1이 거짓이고 조건식2가 참일 때는 컴파일할 문장 2를 컴파일한다. 조건식1와 조건식2가 모두 거짓이면 컴파일할 문장 3을 컴파일한다. 조건식에는 괄호를 붙이지 않으며, 정수형 상수나 정수형 상수로 바뀔 수 있는 매크로 상수를 사용한다.
컴파일할 문장 또한 중괄호로 묶을 필요 없이 문장을 나열하면 된다. 

	#if 조건식1
		컴파일할 문장 1
	#elif 조건식2
		컴파일할 문장 2
	#else
		컴파일할 문장 3
	#endif

조건부 컴파일을 할 때는 연산자 defined와 !defined 연산자를 사용할 수 있다. 매크로명 앞에 사용하며, defined 연산자는 매크로명이 정의되어있다면 참, 정의되어있지 않으면 거짓이 된다. 아래의 코드는 BIT16이 정의되어 있다면 if와 endif 사이의 문장을
컴파일한다.

	#if defined BIT16
		컴파일할 문장
	#endif

위의 코드는 아래와 같이 간략하게 사용할 수 있다.

	#ifdef BIT16
		컴파일할 문장
	#endif

아래와 같이 조건으로 매크로명이 정의되어 있는지를 제외한 다른 조건이 있다면 defined 연산자를 사용해야 한다.

	#if (defined(BIT16) && (VER >= 6))
		컴파일할 문장
	#endif

조건부 컴파일 지시자를 사용할 때 #undef 지시자와 #error 지시자를 사용할 수 있다.
	#undef : 매크로명의 정의를 취소한다.
	#error : 지정한 메시지를 출력하고 컴파일을 중단한다. 조건을 검사하여 조건에 충족하지 못할 때 error 지시자를 사용해 메시지를 출력하고 컴파일을 종료할 수 있다.

	#undef BIT16
	#errer 컴파일러 버전은 6.0 이상이어야 합니다.

▶ #pragma 지시자
컴파일러의 컴파일 방법을 세부적으로 제어할 때 사용한다. 구조체를 정의할 때 byte alignment에 의해 padding byte가 들어가게 된다. 이때 byte alignment를 적용할 때 단위바이트를 1바이트로 계산하도록 하면 남는 바이트 없이 맴버들을 이어붙여서 사용할 수
있다. 이때 다음과 같이 pragma와 pack을 사용한다. 아래와 같이 pack에 1을 넣으면 byte alignment를 적용할 때 한 바이트 단위로 메모리를 할당하도록 한다. 이 경우 패딩바이트는 포함되지 않는다.

	#pragma pack(1)

scanf나 gets 함수를 사용하면 배열의 주소를 줘서 호출하는데, scanf나 gets 함수를 사용하면 입력받을 공간이 입력받은 데이터보다 작아서 할당되지 않는 공간을 침범하게 될 수도 있다. 이를 경고하기 위해 Visual C++ 컴파일러는 경고메시지를 출력한다. 이러한
경고메시지가 뜨지 않도록 하기 위해 다음과 같이 pragma 지시자를 사용해야 한다. 아래와 같이 코드를 작성하면 4996 경고 번호는 메시지가 뜨지 않는다.

	#pragma warning(disable:4996)
*/

#include <stdio.h>

#define PRINT_EXPR(x) printf(#x " = %d\n", x)
#define NAME_CAT(x, y) (x ## y)

#define VER 7 
#define BIT16 // 치환될 부분 없이도 매크로명을 정의할 수 있다.

typedef struct
{
	char ch;
	int i;
} Sample1;

#pragma pack(push, 1) // 현재 적용되고 있는 byte alignment 규칙을 저장하고 이후부터는 단위를 1byte로 측정한다.

typedef struct
{
	char ch;
	int i;
} Sample2;

#pragma pack(pop)    // push할 때 저장했던 byte alignment 규칙을 다시 적용하여 사용한다.

typedef struct
{
	char ch;
	int i;
} Sample3;

void func(void);

int main(void)
{
	/*** 이미 정의된 매크로 ***/
	printf("컴파일한 날짜와 시간 : %s, %s\n", __DATE__, __TIME__); //__DATE__와 __TIME__은 이미 정의된 매크로이며, 전처리를 거치면 각각 컴파일을 시작한 날짜와 시간이 문자열로 바뀐다.
	printf("파일명 : %s\n", __FILE__);     // __FILE__은 컴파일하는 파일명으로 바뀐다. 이때 파일명은 경로까지 포함된 파일명이다.
	printf("함수명 : %s\n", __FUNCTION__); // 매크로명 __FUNCTION__은 현재 main 함수에서 사용되었기 때문에 main으로 바뀐다.
	printf("행번호 : %d\n", __LINE__);     // __LINE__은 소스코드에서 현재 __LINE__의 행번호로 바뀐다.
#line 100 "macro.c" // 이후에 __LINE__을 사용할 때 다음 행의 행번호를 100으로 간주하여 계산한다. 또한 __FILE__은 macro.c로 바뀌게 된다. 이전에 사용된 매크로에는 영향을 주지 않는다.
	func();
	puts("");

	/*** 매크로 함수 연산자 #과 ## ***/
	int a1, a2;
	NAME_CAT(a, 1) = 10;    // 전처리 후 NAME_CAT(a, 1)은 (a1)으로 치환되어 (a1) = 10;으로 바뀐다. 변수 a1에 10을 대입한다.
	NAME_CAT(a, 2) = 20;
	PRINT_EXPR(a1 + a2);    // 전처리 후 이 문장은 printf("a1 + a2" " = %d\n", a1 + a2);로 바뀐다. 매크로 함수에서 #x는 인수가 문자열 형태로 치환되고, x에는 인수 그대로 치환된다.
	PRINT_EXPR(a2 - a1);
	printf("aa" "bb" "\n"); // 컴파일러는 문자열이 연속으로 사용되면 연속된 문자열을 붙여서 사용한다.
	puts("");

	/*** 조건부 컴파일 지시자 ***/
	int max;

#if VER >= 6
	printf("버전 %d입니다.\n", VER);
#else // VER이 6보다 작다면 아래의 메시지를 출력한 후 컴파일을 종료한다.
#error 버전은 6.0 이상이어야 합니다.
#endif

#ifdef BIT16             // 매크로명 BIT16은 정의되어있기 때문에 max에는 32767이 대입된다.
	max = 32767;
#else
	max = 2147483647;
#endif

	printf("int형 변수의 최댓값 : %d\n\n", max);

#undef BIT16    //  BIT16의 정의를 취소한다.

	/*** #pragma 지시자 ***/
	printf("Sample1 구조체의 크기 : %dbyte\n", sizeof(Sample1)); // 기존에는 byte alignment를 할 때 구조체 맴버에서 가장 큰 자료형의 크기가 기준이 된다.
	printf("Sample2 구조체의 크기 : %dbyte\n", sizeof(Sample2)); // byte alignment를 할 때 기준을 1byte로 한 후 Sample2를 선언하였다. 이때 패딩바이트는 들어가지 않아 크기는 5byte가 된다.
	printf("Sample3 구조체의 크기 : %dbyte\n", sizeof(Sample3)); // 기존에 사용하연 byte aligment의 규칙으로 다시 바꾼 후 Sample3을 선언하였다. Sample1와 크기가 같다.

	return 0;
}

void func(void)
{
	printf("\n");
	printf("파일명 : %s\n", __FILE__);     // __FILE__은 #line 지시자에 의해 macro.c로 바뀌었다.
	printf("함수명 : %s\n", __FUNCTION__); // 매크로명 __FUNCTION__은 현재 func 함수에서 사용되었기 때문에 func으로 바뀐다.
	printf("행번호 : %d\n", __LINE__);     // #line 지시자 다음의 행번호를 100으로 간주해 __LINE__의 행번호를 계산하여 바꾼다.
}