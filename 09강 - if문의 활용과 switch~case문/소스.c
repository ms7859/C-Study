/*
▶ 중첩 if문
if문이 중첩으로 사용될 수 있다. if문이 중첩되었다는 것은, if문으로 실행할 문장 안에 또 if문이 있다는 뜻이다. 아래의 코드는 조건문1이 참일 때 if (조건문1) 블록 안의 문장을 실행하며, 블록 안의 문장은 if문이기 때문에 조건문2를 검사하여 실행문1
또는 실행문2를 실행한다.

	if (조건문1)
	{
		if (조건문2)
		{
			실행문1;
		}
		else
		{
			실행문2;
		}
	}

위의 코드는 아래와 같이 사용할 수도 있다. 아래의 코드는 위의 코드와 같은 동작을 한다. 하지만 아래의 코드는 불필요한 조건 검사를 한다. 아래의 코드는 조건문1을 두 번 검사하며, 조건문1이 참일 경우 조건문2를 두 번 검사하며, 이 역시 불필요한 검사이다.

	if (조건문1 && 조건문2)
	{
		실행문1;
	}
	if (조건문1 && !조건문2)
	{
		실행문2;
	}

아래의 코드는 조건문1이 참이면, 조건문2를 검사하여 참이면 실행문1을 실행하고 거짓이면 아무것도 실행하지 않는다. 또한 조건문1이 거짓이면 실행문2를 실행한다.

	if (조건문1)
	{
		if (조건문2)
		{
			실행문1;
		}
	}
	else
	{
		실행문2
	}

if의 실행문이 전부 한 문장이기 때문에 아래와 같이 중괄호를 생략하여 작성할 수 있을 것 같다. 

	if (조건문1)
		if (조건문2)
			실행문1;
	else
		실행문2;

하지만 실행 결과는 위의 코드와 다르다. else는 가장 가까운 if문과 결합한다. 즉 else문은 if (조건문2)와 결합하여 아래의 코드와 같이 실행될 것이다. 이때 if ~ else 구문은 한 구문으로 보기 때문에 if문의 실행문으로 사용될 때 괄호를 생략할 수 있다.

	if (조건문1)
	{
		if (조건문2)
		{
			실행문1;
		}
		else
		{
			실행문2;
		}
	}

아래 코드와 같이 if ~ else if ~ else 구문 역시 중첩된 if문이다.

	if (조건문1)
	{
		실행문1;
	}
	else if (조건문2)
	{
		실행문2;
	}
	else
	{
		실행문3;
	}

if ~ else if ~ else 구문은 아래와 같이 여러 개의 if문이 중첩되어 사용된 것이다. 하지만 위의 코드와 같이 if ~ else if ~ else를 하나의 구문으로 보고 코드를 작성하는 것이 더 편리하며, 코드의 가독성 또한 높아진다.

	if (조건문)
	{
		실행문1;
	}
	else
	{
		if (조건문2)
		{
			실행문2;
		}
		else
		{
			실행문3;
		}
	}

▶ switch ~ case문
switch ~ case문은 다중선택 구문을 만든다. 아래의 코드에서 조건식은 정수식만 가능하다. 상수, 변수, 연산식을 사용할 수 있으며, 그 값은 정수여야 한다. switch문은 조건식에 따라 제어를 이동하는데, 그 위치를 알려주는 것이 case문이다. 조건식과 일치하는
상수로 제어를 이동하게 된다. 즉, case는 제어를 이동할 위치를 나타내는 레이블 역할을 한다. 그 후 break를 만나기 전까지 아래의 문장을 실행하다가 break문을 만나거나 switch문의 끝에 다다르면 switch문을 벗어난다. 만약 조건식과 일치하는 case가 없을
경우 아무 것도 하지 않고 그냥 벗어난다. 또한 제어를 상수3의 위치로 옮길 경우 실행문3을 실행하면 switch문을 빠져나오기 때문에 마지막 break는 꼭 필요한 것은 아니지만 나중에 코드가 수정될 수 있기 때문에 break를 쓰는 것이 좋다.

	switch(조건식)
	{
	case 상수1:
		실행문1;
		break;
	case 상수2:
		실행문2;
		break;
	case 상수3:
		실행문3;
		break;
	}

아래의 코드와 같이 default를 추가하면, 일치하는 상수가 없을 때 그냥 빠져나가는 것이 아니라 default로 이동한다. 따라서 실행문4를 실행한 후 switch문을 벗어난다. default는 반드시 코드의 마지막에 와야 하는 것은 아니며, 코드의 어디든 올 수 있다. 먼저
모든 case를 살펴보고 일치하는 상수가 없을 때 default로 이동하는 것이다.

	switch(조건식)
	{
	case 상수1:
		실행문1;
		break;
	case 상수2:
		실행문2;
		break;
	case 상수3:
		실행문3;
		break;
	default:
		실행문4;
		break;
	}

if문은 조건에 따라 문장의 실행 여부를 결정하거나 실행할 문장을 선택할 수 있다. 하지만 switch문은 조건식에 맞는 case의 위치로 제어를 옮길 뿐 특정 case의 문장만 실행하도록 하는 것이 아니다. 즉 아래의 코드에서 조건식이 상수1일 경우 제어가
case 상수1:으로 이동하여 실행문1을 실행하고 switch문을 벗어나는 것이 아니라 break나 switch문의 끝을 만날 때까지 switch문을 실행한다. 때문에 조건식이 상수1이라면 실행문1부터 실행문4까지 모두 실행한 후 switch문의 끝에 도달하여 switch문을 벗어나게
된다. switch문을 벗어나도록 하는 것은 break문으로만 하며, 원하는 기능에 따라 break문을 사용할 수도, 사용하지 않을 수도 있다. 하지만 대부분의 경우 switch ~ case문은 다중선택구문으로 사용하여 case에 맞는 곳으로 이동한 후 다음 case문 이전에 break를
사용하여 switch문을 실행하도록 한다.

	switch(조건식)
	{
	case 상수1:
		실행문1;
	case 상수2:
		실행문2;
	case 상수3:
		실행문3;
	default:
		실행문4;
	}

switch문은 조건식으로 실행할 문장을 선택하는 것이 아니라, 조건식에 맞는 위치로 제어를 옮기는 것이며, 옮길 위치는 case문으로 결정한다. 하지만 case는 다중선택문으로 많이 쓰이기 때문에 case가 끝나면 break문으로 case문을 벗어나는 것이 대다수이다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int rank, price;
	printf("rank 입력(1 ~ 5): "); scanf("%d", &rank);

	// 아래의 코드는 case가 끝날 때마다 break를 사용했기 때문에 rank에 따라 price가 결정된다.
	price = 0;
	switch (rank) // rank가 3이기 때문에 case 3:으로 이동한다.
	{
	case 1:
		price = 300;
		break;
	case 2:
		price = 200;
		break;
	case 3:
		price = 100;
		break;			// break문에 의해 switch문을 빠져나온다.
	default:
		price = 50;
		break;
	}
	printf("상금은 %d입니다.\n", price);

	// 아래의 코드는 case문이 없기 때문에 rank의 값과 무관하게 price는 항상 50이 된다.
	price = 0;
	switch (rank) // 현재 rank가 3이기 때문에 case 3:으로 제어가 이동하여 price는 100이 된다. 하지만 break문이 없기 때문에 switch문을 벗어나지 않으며, 아래의 문장에 의해 price는 50이 된다.
	{
	case 1:
		price = 300;
	case 2:
		price = 200;
	case 3:
		price = 100;
	default:
		price = 50;
	}
	printf("상금은 %d입니다.\n", price);

	// break를 사용하지 않고 첫 번째 switch문과 같은 동작을 하려면 아래와 같이 작성해야 한다. 
	price = 0;
	switch (rank) // 현재 rank가 3이기 때문에 case 3:으로 제어가 이동하여 price는 100이 된다. 하지만 break문이 없기 때문에 switch문을 벗어나지 않으며, 아래의 문장에 의해 price는 50이 된다.
	{
	case 1:
		price += 100;
	case 2:
		price += 100;
	case 3:
		price += 50;
	default:
		price += 50;
	}
	printf("상금은 %d입니다.\n", price);

	return 0;
}