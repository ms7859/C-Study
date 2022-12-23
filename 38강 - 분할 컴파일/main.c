/*
▶ 분할 컴파일 방법
프로젝트에 여러 개의 파일을 포함시키고 개별적으로 컴파일한 후에 링크 단계에서 합친다. 예를 들어 키보드로부터 두 개의 정수를 입력받아 그 평균을 구해 화면에 출력하는 프로그램을 작성하려고 한다. 이때 main.c와 sub.c 파일 두 개로 작성하려고 한다.
main.c에는 main 함수를 작성하고, sub.c에는 데이터를 입력받는 input_date 함수와 두 정수의 평균을 구해서 반환하는 average 함수를 작성한다. 즉 프로젝트에는 두 개의 소스파일 main.c와 sub.c가 포함되어 있다. 이 파일은 독립적으로 컴파일되어 object 파일
두 개가 만들어진다. 이렇게 만들어진 object 파일은 링크 단계를 수행하고 나면 하나의 실행파일로 만들어진다. 즉, 하나의 프로그램을 여러 개의 파일로 나누어 작성하여 독립적으로 컴파일 한 후 하나로 묶어서 최종적으로 프로그램을 만든다.

소스코드를 컴파일하는 단위는 파일이다. 때문에 각 파일은 독립적으로 컴파일을 할 수 있어야 하며, 컴파일에 필요한 모든 선언이 필요하다. 여러 파일에서 printf 함수를 사용한다면 이 함수를 사용하는 모든 파일에서 stdio.h를 include해야 사용할 수 있다. 또한
이미 만들어진 소스 파일이나 개체 파일도 프로젝트에 포함할 수 있다. 다음은 main.c에 저장되어 있는 코드이다. main.c 파일은 printf 함수가 사용되었기 때문에 stdio.h를 include해야 한다. 또한 sub.c 함수에 정의되어 있는 input_data 함수와 average 함수를
사용하고 있다. 하지만 컴파일을 하려면 두 함수의 형태를 컴파일러가 알아야 하기 때문에 input_data와 average 함수의 선언은 main.c에 포함되어 있어야 한다. 아래와 같이 작성해야 main.c 파일의 컴파일이 가능하다. 또한 아래의 파일이 컴파일되면 object 파일
main.obj가 생성된다. 하지만 프로젝트 이름으로 실행파일이 만들어진 것은 아니다.

	#include <stdio.h>

	void input_data(int *, int *);
	double average(int, int);

	int main(void)
	{
		int a, b;
		double avg;

		input_data(&a, &b);
		avg = average(a, b);

		printf("%d와 %d의 평균 : %.1f\n", a, b, avg);

		return 0;
	}

input_data와 average는 main.c의 파일에 정의해도 되지만, 새로운 소스파일 sub.c에 정의할 수도 있다. sub.c에 저장된 소스코드는 다음과 같다. sub.c에는 printf 함수와 scanf 함수가 사용되었다. sub.c를 컴파일하려면 두 함수가 선언되어 있어야 하기 때문에
sub.c 파일 역시 stdio.h를 include해야 한다. sub.c가 컴파일되면 object 파일 sub.obj가 생성된다.

	#include <stdio.h>

	void input_data(int* pa, int* pb)
	{
		printf("두 정수 입력: ");
		scanf("%d%d", pa, pb);
	}

	double average(int a, int b)
	{
		int tot;

		tot = a + b;
		return tot / 2.0;
	}

위와 같이 두 개의 소스파일 main.c와 sub.c를 저장하고 컴파일하면 두 개의 object파일이 생성되며, 두 object 파일이 link 과정을 거치면 프로젝트 이름의 실행파일이 생성된다.

▶ 분할 컴파일에서 extern과 static의 용도
분할 컴파일된 여러 개의 파일에서 데이터를 공유하거나 공유를 제한할 수 있다. 다른 파일에 있는 전역변수를 사용하려면 extern 키워드를 사용해 선언한다. 또한 키워드 static은 하나의 파일에서 전역 변수로 사용되고 있는 변수를 다른 파일로 공유할 수 없게끔
차단하는 역할을 한다. 키보드로부터 양수를 반복적으로 입력받아 입력받은 양수의 전체 합을 구해 입력받은 양수의 수로 나누어 평균을 구해서 양수의 개수와 전체 합, 평균을 출력하는 프로그램을 만드려고 한다. 이때 세 개의 파일로 분할하여 main.c, input.c,
average.c 파일을 만든다. 이때 각 파일에 포함할 함수와 전역변수는 다음과 같다.

- main.c
	main 함수와 양수의 합, 평균, 개수를 출력하는 print_data 함수
	int cnt
	static int tot
	
- input_data.c
	양수를 입력받아 데이터를 누적하는 input_data 함수
	extern int cnt
	int tot

- average.c
	입력받은 데이터의 평균을 구해서 반환하는 average 함수
	extern int cnt
	extern int tot

main.c 파일의 코드는 아래와 같다. main.c에는 전역변수로 int형 변수 cnt와 tot를 갖는다. cnt는 입력받은 양수의 개수를 저장하며, 입력받은 양수의 전체 합은 tot에 저장한다. 이때 main.c의 cnt 변수는 input_data.c와 average.c에서도 사용할 수 있어야 한다.
하지만 tot는 static으로 선언하여 다른 프로그램에서 사용하지 못하도록 선언하였다.

	#include <stdio.h>

	int input_data(void);
	double average(void);
	void print_data(double);

	int cnt = 0;
	static int tot = 0;

	int main(void)
	{
		double avg;

		tot = input_data();
		avg = average();
		print_data(avg)

		return 0;
	}

input_data.c 파일의 코드는 아래와 같다. main.c의 전역변수 cnt를 사용하기 위해 cnt를 extern으로 선언하였다. cnt는 input.c에서 새로운 전역변수 cnt를 선언하는 것이 아니라 main.c의 cnt를 사용하겠다는 의미이다. 또한 input_data.c 파일의 input_data
함수는 입력받은 파일을 계속 누적해야 한다. 하지만 main.c의 전역변수는 tot는 static에서 선언하였기 때문에 input_data.c 파일에서는 사용할 수 없다. 따라서 input_data.c 파일에서 전역변수 tot를 선언하여 이 변수에 입력받은 변수를 누적한 후 input_data
함수가 누적된 데이터를 반환하도록 설계하였다. main.c의 전역변수 tot와 input_data.c의 전역변수 tot는 이름만 같을뿐 다른 변수이다.

	#include <stdio.h>

	extern int cnt;
	int tot = 0;

	int input_data(void)
	{
		int pos;

		while (1)
		{
			...
			tot += pos;
		}

		return tot;
	}

average.c 파일의 코드는 아래와 같다. average.c 파일의 average 함수는 입력받은 양수의 합을 개수로 나누어야하기 때문에 main.c의 cnt 변수와 input.c의 tot 변수를 공유해야 한다. 때문에 아래와 같이 cnt와 tot를 extern으로 선언하였다. 이떄 main.c에도
cnt 전역변수가 있지만 static으로 선언되어 다른 파일에서는 공유가 불가능하기 때문에 input.c의 tot 변수가 공유된다.

	extern int cnt;
	extern int tot;

	double average(void)
	{
		return tot / (double)cnt;
	}

▶ 헤더 파일의 필요성
1. 헤더파일은 각 파일에 공통으로 필요한 코드를 모아서 만든다. 함수를 호출하거나 구조체를 사용하려면 사용 전에 함수를 선언하고 구조체 형을 선언해야 컴파일할 수 있다. 이러한 함수나 구조체가 여러 파일에서 필요하다면 필요한 파일마다 선언을 해야 한다.
하지만 헤더파일에 함수의 원형과 구조체 형을 선언하여 저장한 후 그 헤더파일을 include만 하면 함수의 선언문과 구조체 형의 선언문이 파일에 포함되어 사용할 수 있다. 또한 다른 파일에 선언된 전역변수를 여러 파일에서 사용해야 한다면 헤더파일에 extern
선언을 해서 사용할 수 있다.

2. 헤더 파일의 수정 내용을 빠르고 정확하게 반영한다. 헤더파일을 사용하지 않고 파일에 직접 선언한다면 나중에 원형을 수정할 때 선언된 파일을 모두 수정해야 하지만, 헤더 파일에 저장하여 include 하면 헤더 파일에서만 수정하면 모든 파일에 반영된다.

3. 다른 프로그램에 헤더 파일의 내용을 재활용한다. 

▶ 헤더 파일의 중복 문제 포함 문제와 해결 방법
헤더파일 point.h에는 아래와 같이 구조체 Point의 형태가 선언되어있다.

	typedef struct
	{
		int x;
		int y;
	}Point;

또한 헤더파일 line.h에는 아래와 같이 구조체 Line의 형태가 선언되어 있다. 이때 구조체 Point형이 필요해 point.h를 include하였다.

	#include "point.h"

	typedef struct
	{
		Point first;
		Point second;
	}Line;

이때 main 함수에서 Point형 변수와 Line형 변수를 선언하기 위해 point.h와 line.h를 모두 include하였다. 하지만 line.h에는 point.h가 이미 include되어있기 때문에 point.h와 line.h를 모두 호출하면 point.h가 두 번 포함되어 Point 구조체의 형태가 두 번
선언되는 문제가 발생한다. 이러한 문제를 해결하기 위해 #ifndef ~ #define ~ #endif를 사용해야 한다. 즉 point.h를 아래와 같이 수정해야 한다. 아래의 코드는 _POINT_H_가 정의되었는지 확인하여 정의되지 않았을 때 _POINT_H_를 정의한 후 Point형 구조체 형을
선언한다.

	#ifndef _POINT_H_

	#define _POINT_H_
	typedef struct
	{
		int x;
		int y;
	}Point;

	#endif

point.h를 위와 같이 수정하고 다시 main.c에서 point.h와 line.h를 모두 include하였다. main.c에는 point.h가 두 번 include된다. 하지만 첫 번째 include된 코드에서는 _POINT_H_가 정의되어있지 않기 때문에 _POINT_H_를 정의한 후 Point형 구조체의 형을
선언한다. 하지만 두 번째 include된 코드에서는 이미 _POINT_H_가 정의되어있기 때문에 Point형 구조체의 형을 선언하지 않는다. 즉 Point형 구조체 형이 중복으로 선언되는 문제를 해결할 수 있다. 위와 같이 헤더파일을 작성할 때는 헤더파일의 이름으로 된
매크로명이 정의되어 있는지 먼저 확인한 후 정의가 안 되어있을 때 헤더파일의 이름으로 매크로명을 정의한 후 헤더파일의 내용이 컴파일되도록 코드를 작성해야 중복으로 선언되는 것을 방지할 수 있다.
*/

#include <stdio.h>
#include "point.h"
#include "line.h"

void input_data(int*, int*); // 정의는 다른 파일에서 하더라도 컴파일을 위해 함수 선언은 필요하다.
double average(int, int);

int input_data2(void);     // 양수를 입력하고 그 합을 반환
double average2(void);     // 평균을 구하여 반환
void print_data2(double);  // 출력함수
int cnt = 0;               // 입력한 양수의 수 누적
static int tot = 0;        // 입력한 양수의 합. static 키워드를 사용해 사용 범위를 main.c 파일로 제한하였다.

int main(void)
{
	/*** 분할 컴파일 방법 ***/
	int a, b;   // 두 정수를 입력받아 저장할 변수 a, b
	double avg; // 두 정수의 평균을 저장할 변수 avg

	input_data(&a, &b);  // 키보드로 입력받아 a, b에 저장하는 것은 input_data 함수가 한다.
	avg = average(a, b); // average 함수로 두 정수의 평균을 구해 반환받는다.

	printf("%d와 %d의 평균은 %.1lf입니다.\n\n", a, b, avg);


	/*** 분할 컴파일에서 extern과 static의 용도 ***/
	double avg2;              // 입력한 양수의 평균

	tot = input_data2();
	avg2 = average2();
	print_data2(avg2);

	/*** 헤더 파일의 중복 문제 포함 문제와 해결 방법 ***/
	Line l = { {1, 2}, {5, 6} }; // line.h를 include 했기 때문에 Line 구조체형을 사용할 수 있다.
	Point p;                     // point.h를 include 했기 때문에 Point 구조체형을 사용할 수 있다.

	p.x = (l.first.x + l.second.x) / (2.0);
	p.y = (l.first.y + l.second.y) / (2.0);  // p에는 선 l의 중점의 좌표가 저장된다.
	printf("선의 가운데 점의 좌표: (%d, %d)\n", p.x, p.y);

	return 0;
}

void print_data2(double avg)
{
	printf("입력한 양수의 개수 : %d\n", cnt);
	printf("전체 합과 평균 : %d, &.1lf\n\n", tot, avg); // cnt와 tot는 전역변수이기 때문에 print_data2 함수에서 사용할 수 있지만, avg2는 인수로 받아서 사용해야 한다.
}