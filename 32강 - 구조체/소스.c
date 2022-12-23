/*
▶ 기본자료형 및 응용자료형
char, int, double 등 이미 자료형의 크기나 데이터를 저장하는 방법, 연산방법 등이 컴파일러를 설계할 단계부터 구현이 되어있어서 내장되어있는 자료형을 기본자료형 또는 내장자료형이라고 한다. 또한 배열이나 포인터 등 사용자가 만들어내는 자료형을
응용자료형이라고 한다. 배열은 크기에 따라 다양한 형태로 배열을 만들 수 있으며 포인터는 *의 개수에 따라 다양한 포인터를 만들 수 있다. 응용자료형은 사용자 정의 자료형이라고도 한다. 구조체 또한 응용자료형이다.

▶ 구조체
배열은 형태가 같은 것을 모아서 만들어주지만, 구조체는 형태가 다른 것도 모아서 하나의 자료형으로 만들어 쓸 수 있다. 배열을 선언하면 메모리에 저장공간이 확보되며, int [5]형, double [4]형 등 자료형을 컴파일러가 인식할 수 있게 된다. 하지만 구조체는
어떤 자료형을 모아서 새로운 자료형으로 만들지를 미리 컴파일러에게 알려준 후 변수를 선언해야 한다. 즉 구조체를 사용하려면 가장 먼저 구조체의 형태를 컴파일러에게 알려줘야 한다.

▶ 구조체 형 선언
구조체의 형을 선언할 때는 struct 키워드를 사용하며, 구조체 형을 구분하기 위해 struct 뒤에 구조체 형의 이름을 식별자로서 붙인다. struct와 이름을 합친 것이 하나의 자료형이 된다. 그 후 중괄호 안에 어떠한 자료형을 모아서 만들 것인지를 쓴다. 즉
구조체의 맴버를 적는다. 맴버를 적을 때는 맴버의 자료형을 쓰고 어떤 맴버를 지정해서 쓸지에 대한 이름을 적는다. 학생의 정보를 저장할 수 있는 자료형을 구조체로 만드려고 한다. 이때 학생의 정보에는 int형 학번과 double 학점이 있다. 때문에 아래와 같이
구조체 형의 이름은 student로 했으며, 학번을 저장할 int형 변수 num과 doueble형 변수 grade를 멤버로 갖는다. 아래와 같이 구조체를 선언하면 struct student라는 새로운 자료형이 생기는 것이다.

	struct student
	{
		int num;
		double grade;
	};

멤버의 선언은 변수를 선언하는 것과 형태가 같다. 하지만 멤버의 선언은 컴파일러에게 어떤 맴버를 사용할지를 알려주는 역할만 할 뿐, 저장공간을 확보해주지는 않는다. 저장공간을 확보해주지 않기 때문에 초기화 또한 불가능하다. 즉 멤버 선언과 변수 선언은
서로 다르다. 구조체 형의 선언은 일반적으로 main 함수 위에 써서 모든 함수에서 사용할 수 있도록 해준다. 함수 안에 선언하면 선언된 함수 내에서만 사용할 수 있다.

▶ 구조체 변수 선언
구조체 형을 선언하여 새로운 자료형을 만들었으면 이 자료형으로 변수를 선언해야 한다. struct student의 변수 a를 선언하려면 아래와 같이 변수명 a 앞에 자료형 struct student를 써야 한다. 구조체 변수를 선언하면 구조체 맴버의 크기를 모두 합친 크기만큼
저장공간을 확보해준다. 아래의 코드가 실행되면 int형 4byte와 double형 8byte를 합쳐서 총 12byte가 할당된다. 할당된 12byte 크기 전체를 하나의 변수처럼 사용하며, 그 이름은 a가 된다.

	struct student
	{
		...
	};
	int main(void)
	{
		struct student a;
		...
	}

▶ 구조체 맴버의 사용
배열에 저장된 값을 사용할 때 배열명을 사용하지 않고 배열명에 인덱스를 이용해서 배열의 요소들을 사용한다. 구조체 또한 구조체 변수명을 사용하는 것이 아니라 구조체의 맴버에 접근햐여 값을 저장하거나 저장된 값을 사용해야 한다. 구조체의 맴버에 접근하기
위해 맴버접근연산자 .를 사용한다. 구조체 변수명 뒤에 .을 붙이고 맴버명을 붙여서 구조체의 맴버에 접근한다. 배열은 요소의 크기가 모두 같기 때문에 첫 번째 주소로부터 얼마나 떨어진 저장공간을 사용할지를 계산해 원하는 요소에 접근할 수 있다. 하지만
구조체는 맴버의 크기가 다를 수 있기 때문에 각각의 맴버를 구분할 수 있는 이름이 있어야 한다. 자료형이 struct student인 변수 a의 멤버 num에 접근하려면 a.num와 사용해야 한다. 이 표현은 int형 변수의 표현과 완전히 같기 때문에 아래와 같이 값을 대입할
수도 있고, 키보드로부터 입력받을 수도 있다. 또한 a.grade에도 값을 대입하거나 키보드로 입력받을 수 있다. 변수의 멤버는 연산 또한 가능하다.

	a.num = 201721026;
	scanf("%d", &a.num);
	a.grade = 4.5;
	scanf("%lf", &a.grade);

. -> () [] 위의 연산자 4개는 0순위이며, 항상 최우선으로 실행된다. 때문에 &a.num에서 a.num이 먼저 연산되어 변수 a의 멤버 num에 접근한 후 접근한 멤버 num의 주소값을 구한다. 때문에 주소연산을 할 때 괄호를 붙이지 않아도 된다.

▶ padding byte
자료형이 struct student인 변수 a는 멤버로 int형과 double형을 하나씩 갖는다. 때문에 구조체의 크기는 12가 된다. 하지만 실제로 sizeof 연산을 하여 크기를 계산하면 16byte가 나온다. 그 이유는 padding byte 때문이다. 시스템은 CPU가 메모리를 접근할 때 접근
효율을 높이기 위해 일정한 byte 단위로 접근하며, 이를 byte alignment라고 한다. 그 단위는 구조체에서 크기가 가장 큰 맴버를 기준으로 정한다. 따라서 메모리에 맴버들을 할당하는 단위는 8byte가 된다. 첫 번째 8byte에 멤버 num을 선언하고, 남은 4byte에는
double형을 선언할 수 없기 때문에 두 번째 8byte에 멤버 grade를 선언한다. 때문에 a의 크기는 16byte가 된다. 이때 num과 grade 사이에는 4byte의 padding byte가 생긴다. padding byte는 메모리를 너무 많이 차지하는 문제가 발생할 수도 있다. 기존의 struct
student을 더 많은 멤버를 갖도록 다음과 같이 수정하였다.

	struct student
	{
		char ch1;
		short num;
		char ch2;
		int score;
		double grade;
		char ch3;
	}

위의 구조체 형의 멤버들 중 가장 크기가 큰 8byte를 단위의 기준으로 한다. struct student의 멤버를 저장하기 위해 첫 번째 8byte를 할당하여 멤버를 처음부터 차례대로 할당한다. 이때 저장하려는 멤버의 자료형 크기가 기준 자료형의 크기, 즉 8byte보다 작으면
8byte 내에서 멤버의 자료형 크기가 기준이 된다. char형은 1byte이기 때문에 8byte의 어느 위치에든 저장할 수 있지만, short형은 2byte이기 때문에 8byte의 공간 내에서 2byte 단위로만 할당할 수 있다. char형 멤버 ch1은 8byte의 첫 번째 byte에 할당된다.
또한 short형 멤버 num은 2byte를 기준으로 할당되기 때문에 ch1 바로 다음 byte부터 할당되지 않고 세 번째 byte부터 할당된다. 이때 두 번째 byte는 padding byte가 된다. char형 멤버 ch2는 아무 데나 할당할 수 있기 때문에 5번째 byte에 할당된다. 그러면
총 3byte가 남아있는데 다음에 저장해야 할 멤버 score는 int형이기 때문에 저장할 수 없으며, 두 번째 8byte에 저장해야 한다. 이때 남은 3byte는 padding byte가 된다. score는 두 번째 8byte에 4byte를 기준으로 저장한다. 즉 첫 번째 byte부터 4byte가 할당된다. 
다음에 저장할 grade는 8byte이기 때문에 남은 4byte는 padding byte가 되고 세 번째 8byte에 grade를 저장한다. 그 후 마지막 ch3를 저장하기 위해 네 번째 8byte를 할당해 ch3를 저장하고, 남은 7byte는 padding byte가 된다. 즉 struct student가 메모리에
저장되는 구조는 다음과 같다. 즉 struct student 자료형은 총 32byte가 할당된다. 하지만 실제로 활용하는 공간은 17byte로 15byte가 padding byte로 채워져 낭비되고 있다.
	
	1번째	■□■■■□□□
	2번째	■■■■□□□□
	3번째	■■■■■■■■
	4번째   ■□□□□□□□

아래와 같이 num과 ch2의 선언 순서를 바꾸면 struct student의 저장공간은 이전보다 훨씬 줄어든다.

	struct student
	{
		char ch1;
		char ch2;
		short num;
		int score;
		double grade;
		char ch3;
	};

ch1, ch2, num, score가 모두 첫 번째 byte에 할당되고 grade는 두 번째 byte에 할당되며, 마지막 byte에 ch3가 저장되면 24byte만으로 struct student의 공간을 확보할 수 있다. 즉 멤버의 선언 순서를 잘 조절하면 padding byte를 줄여 더 효율적으로 공간을
활용할 수 있다. 하지만 padding byte를 줄이기 위해 멤버의 순서를 억지로 바꾸어 선언할 경우 가동성이 떨어질 수 있다. 때문에 메모리 공간의 효율성과 가독성을 모두 고려하여 코드를 작성해야 한다.

▶ 다양한 형태의 구조체 맴버
구조체의 맴버는 기본자료형 외에도 배열, 포인터, 이미 만들어진 다른 구조체 등 다양한 자료형을 사용할 수 있다. 구조체 struct student가 멤버로 이름, 나이, 키, 인삿말을를 갖도록 수정하려고 한다. 이때 이름을 저장할 멤버는 크기가 20인 char형 배열 name을
선언하며 나이를 저장할 int형 멤버 age와 키를 저장할 doule형 멤버 height를 갖는다. 또한 인삿말의 길이는 다양하기 때문에 일정한 길이의 배열을 선언하지 않고 입력받은 인삿말의 길이에 딱 맞게 동적할당하여 이를 연결할 수 있도록 char형 포인터 intro를
멤버로 갖는다. 이때 a.name으로 a의 멤버 name에 접근하면 1차원 배열 name의 배열명에 접근한 것이며, 배열명은 대입연산자의 왼쪽에 사용될 수 없기 때문에 a.name = "...";와 같이 사용할 수 없다. 대신 다음과 같이 strcpy 함수를 사용해야 한다. a.age와
a.height로 각 공간에 접근하여 값을 대입할 수 있다. intro는 char형 포인터이기 때문에 다음과 같이 문자열 상수를 대입할 수 있다. 하지만 이 공간은 문자열의 위치를 기억할 수 있지만 문자열 자체를 저장할 수 있는 공간은 아니기 때문에 문자열을 입력받거나
복사하려면 다음과 같이 동적으로 공간을 할당하여 이 공간을 가리키도록 해야 한다. 그 후 이 공간에 문자열을 저장해야 한다.

	struct student
	{
		char name[20];
		int age;
		double height;
		char* intro;
	}

	int main(void)
	{
		struct student a;
		strcpy(a.name, "Gil Min Seong");
		a.age = 24;
		a.height = 164.9;
		a.intro = "Hello, ...";
		a.intro = (char *)malloc(80);
		scanf("%s", a.intro);
		...
	}

▶ 구조체 형을 다른 구조체의 멤버로 사용
이미 만들어진 구조체 형을 새로운 구조체 형의 멤버로 사용할 수 있다. 아래의 struct profile은 나이, 키, 이름을 멤버로 갖는다. 또한 struct sudent가 이름, 나이, 키, 학번, 학점을 멤버로 갖도록 수정하려고 한다. 이때 이름, 나이, 키는 struct profile에
이미 선언되어 있다. 때문에 각각의 멤버를 전부 선언하지 않고 struc profile형 멤버 pf를 선언하였다. 그리고 나머지 학번, 학점을 num, grade로 선언하였다. 이때 멤버 pf는 struct profile형 구조체이기 때문에 name, age, height를 멤버로 갖는다.

	struct profile
	{
		char name[20];
		int age;
		double height;
	};

	struct student
	{
		struct profile pf;
		int num;
		double grade;
	};

main 함수에서 struct student형 변수를 선언하면 메모리 공간이 할당되며 그 이름은 a이다. 공간 a에는 세 개의 멤버 pf, num, grade가 저장된다. 또한 pf 역시 구조체이기 때문에 pf 안에 세 개의 멤버 name, age, height가 저장된다. a의 각 멤버에 접근하여 값을
대입하려면 아래와 같이 해야 한다. 이름을 저장하려면 먼저 a의 pf에 접근한 후 pf에서 name에 다시 접근해야 한다. 이렇게 접근한 것은 char형 배열의 배열명이기 때문에 strcpy를 이용해 문자열을 대입하거나 키보드로 입력받을 수 있다. 나이와 키 역시 pf에
먼저 접근한 후 age와 height에 접근해야 한다. 학번과 학점은 a.num, a.grade로 접근할 수 있다.

	int main(void)
	{
		struct student a;
		strcpy(a.pf.name, "길민성");
		a.pf.age = 24;
		a.pf.height = 164.9;
		a.num = 201721026;
		a.grade = 4.5;
	};

위와 같이 구조체가 다른 구조체 형을 멤버로 가질 수 있다. 

▶ 구조체 변수의 초기화
구조체 변수는 선언할 때 중괄호 안에 멤버를 나열하여 초기화할 수 있다. 즉 위에서 선언한 struct student형 변수 a는 아래와 같이 초기화를 할 수도 있다.

	int main(void)
	{
		struct student a = {{"길민성", 24, 164.9}, 201721026, 4.5};
		...
	}

▶ 구조체의 변수의 대입 연산
구조체 변수는 하나의 변수처럼 사용된다. 할당된 공간은 크고 복잡하게 되어있지만 공간 전체는 하나의 변수이고, 그 변수의 이름도 있다. 구조체 변수 자체는 하나의 기본 자료형 변수처럼 사용할 수 있다. 따라서 대입연산이 가능하다. struct student형 변수
b를 선언하여 위에서 선언 후 초기화한 a의 값을 복사하여 대입하려고 한다. 이때 대입연산자를 이용하지 않는다면 a의 각 멤버에 접근하여 값을 구한 후 b의 각 멤버에 접근하여 저장해야 한다. 하지만 아래와 같이 대입연산자를 이용하면 a의 모든 멤버의 값들이
복사되어 b에 저장된다. 대입연산이 가능하기 때문에 구조체 변수를 함수의 인수로 주거나 함수의 반환값으로 주는 것도 가능하다.

	int main(void)
	{
		struct student a = { ... }
		struct student b;
		b = a;
		...
	}

▶ 구조체 변수를 함수의 인수로 주고 반환받기
시력을 저장하는 double형 변수 left와 right가 선언되어 있다. 이때 함수 호출을 통해 두 개의 double형 변수에 저장된 값을 서로 바꾸려고 한다. 함수는 많은 인수를 받더라도 하나의 값만 반환할 수 있기 때문에 두 개의 값을 받아 두 개의 값을 반환할 수 없다. 
때문에 변수의 주소값을 인수로 받아 포인터에 저장해 간접참조 연산을 해야 한다. 하지만 구조체를 이용하면 두 개의 값을 동시에 반환할 수 있다. left와 right를 멤버로 갖는 하나의 구조체 변수를 선언해 이 변수를 함수의 인수로 주고 반환을 받으면 두 개의
값을 동시에 반환하는 기능을 할 수 있다. 아래와 같이 struct vision가 double형 멤버 left와 right를 갖도록 구조체 형태를 만든다. 또한 main 함수에는 struct vision형 변수 a가 선언되어 초기화되어 있다. 이때 변수 a를 인수로 주고 swap 함수를 호출하면 a의
멤버 left와 right에 저장된 값을 서로 바꿀 수 있어야 한다. swap 함수는 struct vision형 변수 a를 인수로 받아야 하기 때문에 매개변수 역시 struct vision형으로 선언한다. 함수 내부에서는 b에 저장된 멤버의 값을 서로 바꿔주고 다시 b를 반환한다. 이때
반환형은 struct vision형이 되어야 한다. 즉 swap(a)와 같이 호출하면 a의 멤버 값이 서로 바뀐 상태로 반환되고, 이 값을 a에 다시 대입해야 한다.

	struct vision
	{
		double left;
		double right;
	};

	struct vision swap(struct vision b)
	{
		double tmp;
		tmp = b.left; b.left = a.left; a.left = tmp;
		return b;
	}

	int main(void)
	{
		struct vision a = {1.0, 0.8};
		a = swap(a);
		...
	}

▶ 비트 필드 구조체
비트 필드 구조체란 맴버들을 선언할 때 맴버들의 크기를 bit 단위로 설정할 수 있는 구조체를 말한다. 저장하려는 데이터가 가질 수 있는 가짓수가 매우 적은 경우 bit 단위로 공간을 할당할 수 있다. 비트필드 구조체의 맴버를 선언할 때는 자료형과 변수명을 쓴
후 :을 붙이고 뒤에 저장할 bit의 크기를 적는다. 비트필드 구조체의 멤버들은 이미 크기를 bit 단위로 지정해주기 때문에 멤버의 이름 앞 자료형은 멤버의 자료형 및 크기를 의미하는 것이 아니다. 이 멤버는 형태를 갖지 않는다. 자료형은 멤버들이 가질 수 있는
최대 비트수를 의미한다. 또한 실제 할당되는 단위 크기가 된다. 아래에 선언된 struct bit_field는 7bit로 모든 데이터를 저장할 수 있다. 하지만 멤버가 unsigned int형으로 선언되었기 때문에 기준 단위는 4byte가 된다. 할당된 4byte에 멤버가 bit단위로 쪼개어
저장된다. 이때 왼쪽부터 할당되는지 오른쪽부터 할당되는지는 시스템마다 차이가 난다. 오른쪽부터 할당된다면 son은 32bit중 오른쪽 2bit가 할당되며 그 다음 2bit는 daughter, 그 다음 3bit는 pet을 위해 할당된다. 남은 25bit는 버려지는 공간이 된다. 멤버를
선언할 때 unsigned int형 대신 int형을 사용할 수도 있다. int형을 사용하면 음수까지 저장할 수 있으며, 가장 왼쪽 비트는 부호비트로 사용된다. int형 2bit는 -2에서 1까지의 수를 저장할 수 있다. 비트필드 구조체에서 signed형은 거의 사용되지 않는다.

	struct bit_field
	{
		unsigned int son : 2;
		unsigned int daughter : 2;
		unsigned int pet : 3;
	};

비트필드 구조체는 중간에 padding bit를 넣을 수 있다. struct bit_field를 아래와 같이 수정하였다. 멤버는 unsigned char형으로 선언했기 때문에 1byte가 기준 단위가 된다. 오른쪽부터 a, b, c가 각각 1, 2, 3bit씩 할당된다. 총 6bit가 할당되고 2bit가
남아있다. 이때 d는 할당될 공간이 없기 때문에 2bit는 버려지며, 이 공간은 padding bit가 된다. d를 저장하기 위해 새로운 1byte가 할당되어 오른쪽 4bit에 d가 저장되고 또 남은 4bit는 padding bit가 된다. 

	struct bit_field
	{
		unsigned char a : 1;
		unsigned char b : 2;
		unsigned char c : 3;
		unsigned char d : 4;
	};

이때 아래와 같이 비트 수는 그대로 두지만 멤버의 변수명 b의 이름을 생략하면 a 다음 2bit는 padding bit가 되어 건너뛰고 세 번째 비트부터 c가 할당된다. 즉 a와 c 사이에 2bit의 padding bit가 추가된 것이다. 중간에 padding bit를 넣으려면 bit수를
지정해주고 멤버명을 생략해야 한다.

	struct bit_field
	{
		unsigned char a : 1;
		unsigned char : 2;
		unsigned char c : 3;
		unsigned char d : 4;
	};

아래와 같이 비트명이 생략된 상태에서 비트수를 0으로 하는 경우도 있다. 이는 a를 선언하고 남은 bit는 모두 padding bit로 만든다는 뜻이다. a를 저장하기 위해 1byte가 할당되어 그 중 a를 위한 공간 1bit가 사용되면 7bit가 남아있다. 남은 7bit 모두를 padding
bit로 만든다. 때문에 c, d를 저장하기 위해 새로운 1byte가 할당된다.

	struct bit_field
	{
		unsigned char a : 1;
		unsigned char : 0;
		unsigned char c : 3;
		unsigned char d : 4;
	};

비트필드 구조체는 bit 단위로 데이터를 처리하기 때문에 주소값이 있을 수 없다. 따라서 맴버로 배열을 사용할 수 없다. 배열은 주소 연산을 통해 접근하는데 주소가 없기 때문에 멤버로 사용할 수 없다. 또한 맴버의 주소를 구할 수도 없다. 때문에 키보드로부터
직접 입력을 받을 수 없다. 입력받은 값을 저장하려면 임시변수를 선언하여 그 변수에 입력받은 후 구조체의 맴버에 저장해야 한다.
*/

#include <stdio.h>

struct student // 학생의 정보를 저장할 구조체 형을 선언한 것이다. struct student 자체가 하나의 자료형이 된다.
{
	int num;       // 학번을 저장할 맴버
	double grade;  // 학점을 저장할 맴버
};

struct student2
{
	char ch1;
	short num;
	char ch2;
	int score;
	double grade;
	char ch3;
};

struct student3
{
	char ch1;
	char ch2;
	short num;
	int score;
	double grade;
	char ch3;
};

struct student4
{
	char name[20]; // 맴버로 배열이 가능하다.
	int age;
	double height;
	char* intro;   // 맴버로 포인터가 가능하다.
};

struct profile
{
	char name[20];
	int age;
	double height;
};

struct student5
{
	struct profile pf; // student5의 맴버로 struct profile 형 구조체를 사용하고 있다.
	int num;
	double grade;
};

struct vision
{
	double left;
	double right;
};

struct vision swap(struct vision eyes);

struct bit_field
{
	unsigned int a : 2;  // unsigned int형 변수를 선언하였으며 저장공간은 2bit를 할당한다. 2bit는 4가지를 저장할 수 있으며, 정수는 0~3을 저장할 수 있다.
	unsigned int b : 3;  // 3bit는 0 ~ 7
	unsigned int c : 4;  // 4bit는 0 ~ 15
	unsigned int : 4;    // 4bit의 padding bit를 넣음
	unsigned int d : 4;  // c와 d 사이에는 4bit의 공간이 비어있음
	unsigned int : 0;    // 위의 맴버를 저장하고 남는 공간은 전부 padding bit를 채움
	unsigned int e : 4;  // 새로운 저장공간을 4byte 할당하여 그 공간에 변수를 저장함
};

struct bit_field2
{
	unsigned char a : 1;
	unsigned char b : 2;
	unsigned char c : 3;
	unsigned char d : 4;
};

int main(void)
{
	/*** 구조체 변수의 선언 ***/
	struct student a; // struct student형 변수 a를 선언한 것이다. int형 4byte, double형 8byte를 합친 12byte의 저장공간이 할당된다. 이 12byte를 변수처럼 사용하며, 그 이름은 a가 된다.
	a.num = 201721026;
	a.grade = 4.5;      // 변수 a의 맴버 grade에 접근하여 4.5를 저장하였다.

	/*** 구조체의 크기 ***/
	printf("sizeof(a): %d\n", sizeof(a));

	struct student2 b;
	printf("sizeof(b): %d\n", sizeof(b));

	struct student3 c;
	printf("sizeof(c): %d\n\n", sizeof(c));

	/*** 다양한 형태의 구조체 맴버 ***/
	struct student4 d;
	strcpy(d.name, "길민성"); // d.name은 배열명이므로 주소상수이다.
	d.age = 23;
	d.height = 164.4;
	d.intro = "Hello, I am a student at Ajou University.";

	/*** 구조체 형을 다른 구조체의 맴버로 사용 ***/
	struct student5 e; // strunct student형 구조체의 맴버에는 struct profile형 구조체 변수가 포함되어있다.
	strcpy(e.pf.name, "길민성"); // 구조체 안의 구조체에 있는 맴버에 접근하려면 접근연산자를 연속으로 쓴다.
	e.pf.age = 23;
	e.pf.height = 164.4;
	e.num = 201721026;
	e.grade = 4.5;

	/*** 구조체 변수의 대입 연산 ***/
	struct student5 f = { {"길민성", 23, 164.4}, 201721026, 4.5 }; // 구조체 변수의 초기화
	struct student5 g = f; // f와 g는 같은 구조체이므로 대입연산을 할 수 있다.

	/*** 구조체 변수를 함수의 인수로 주고 반환받기 ***/
	struct vision my_eyes = { 0.1, 0.2 };
	printf("left : %.1lf\n", my_eyes.left);
	printf("right: %.1lf\n\n", my_eyes.right);
	my_eyes = swap(my_eyes); // 구조체 변수 my_eyes를 함수의 인수로 넘기면 함수에서 두 맴버의 값을 바꾸고 바꾼 구조체 변수를 다시 반환한다. 이 값을 my_eyes에 대입하면 두 맴버값이 바뀌어 저장된다.
	printf("left : %.1lf\n", my_eyes.left);
	printf("right: %.1lf\n\n", my_eyes.right);
	
	/*** 비트 필드 구조체 ***/
	printf("sizeof(struct bit_field): %d\n", sizeof(struct bit_field));
	struct bit_field bf;
	// scanf("%d", &bf.a); // 비트필드 구조체의 맴버는 주소가 없기 때문에 주소 연산이 불가능하며, 키보드로부터 직접 입력을 받는 것또한 불가능하다.

	return 0;
}


struct vision swap(struct vision eyes)
{
	double tmp;
	tmp = eyes.left;
	eyes.left = eyes.right;
	eyes.right = tmp;

	return eyes;
}