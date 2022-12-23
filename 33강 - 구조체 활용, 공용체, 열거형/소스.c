/*
구조체는 하나의 변수지만 자료가 복잡하고 크기 때문에 구조체를 복사해서 사용하는 것은 부담이 된다. 따라서 함수의 인수로 줄 때 구조체 자체를 인수로 주는 대신 구조체의 주소를 넘기는 경우가 많다.

▶ 구조체 포인터와 -> 연산자
구조체 변수는 주소가 있으며, 구조체의 주소를 저장하는 포인터를 구조체 포인터라고 한다. 구조체의 포인터에 간접참조연산을 하면 그 구조체가 되며, 구조체 멤버에 접근할 수 있다. 세 과목의 점수를 모아서 처리할 구조체 struct score을 다음과 같이
선언하였다. 그리고 main 함수에서 struct score형 변수 a를 선언하여 각 멤버에 정수를 대입하였다. 

	struct score
	{
		int kor;
		int eng;
		int mat;
	};

	int main(void)
	{
		struct score a;
		a.kor = 90;
		a.eng = 80;
		a.mat = 75;
		...
	}

이때 변수 a는 주소값을 갖고 있으며, 이 주소값을 구조체 포인터에 대입하여 포인터를 가지고 각 멤버에 접근할 수 있다. a의 주소값 &a를 저장할 포인터 sp를 아래와 같이 선언하였다. 포인터는 포인터 이름 앞에 *을 붙이고 가리키는 자료형을 쓴다. &a가
가리키는 자료형이 struct score이기 때문에 다음과 같이 구조체 포인터 sp를 선언하여 a의 주소를 저장하였다. sp는 a 전체공간을 가리키게 된다. 이때 sp에 * 연산을 하면 그 결과값은 a가 된다. 때문에 a.kor으로 a의 멤버 kor에 접근하듯 (*sp).kor으로 a의
멤버 kor에 접근할 수 있다. 간접참조연산자 *는 멤버접근연산자 .보다 연산순위가 느리기 때문에 *sp.kor와 같이 사용하면 sp.kor이 먼저 연산되어 sp의 멤버 kr이 가리키는 것을 구하게 된다. 하지만 sp는 4byte 포인터이기 때문에 멤버가 없다. 따라서 *sp를
괄호로 감싸 *sp를 먼저 연산하여 a를 구한 후 멤버 kor에 접근해야 한다. 

	int main(void)
	{
		...
		struct score *sp = &a;
		(*sp).kor = 90;
		(*sp).mat = 80;
		...
	}

구조체 포인터로 멤버에 접근하려면 괄호, 간접참조연산자, 멤버접근연산자 세 개를 전부 사용해야 하며, 이러한 연산은 너무 번거롭다. 때문에 이를 한꺼번에 수행해주는 연산자 ->를 사용한다. ->의 왼쪽에는 구조체 포인터가 오며 오른쪽에는 멤버명이 온다.
즉 위의 코드는 아래와 같이 수정될 수 있다. (*sp).kor와 sp->kor은 완벽하게 같은 연산이다. 다음과 같이 키보드로부터 입력을 받거나 연산에 사용될 수도 있다.

	int main(void)
	{
		...
		sp -> kor = 90;
		sp -> mat = 80;
		...
		scanf("%d", &sp->kor);
		int total = sp->kor + sp->mat + sp->eng;
		...
	}

▶ 구조체 변수를 함수에서 포인터로 처리하기
위에서 선언한 구조체 변수 a의 멤버를 출력하는 함수 print_st를 작성하려고 한다. 이때 인수로 a를 넘기면 a와 똑같은 구조의 매개변수를 할당하여 이 공간에 a의 멤버를 모두 복사하여 저장해야 한다. 이러한 과정은 너무 복잡하기 때문에 인수로 구조체 변수명을
넘기는 대신 구조체의 주소값을 인수로 넘기는 것이 바람직하다. 변수 a의 주소값을 인수로 받을 수 있는 함수 print_st를 아래에 선언하였다. 매개변수는 struct score형 변수의 주소값을 저장해야 하기 때문에 struct score형 포인터를 선언해야 한다. 매개변수
p는 a를 가리키고 있기 때문에 *p 연산을 통해 변수명 a를 구할 수 있으며, 변수명 a에 멤버접근연산을 하여 각 멤버에 접근할 수 있다. 또한  -> 연산을 사용하여 멤버에 접근할 수 있다.

	void print_st(struct score *p)
	{
		printf("%d\n", (*p).kor);
		printf("%d\n", p->eng);
		...
	}

print_st 함수는 p가 가리키는 구조체 변수의 값을 출력하는 것이다. 때문에 이 함수는 p가 가리키는 구조체 변수의 값을 수정해서는 안 된다. 이를 위해 매개변수를 아래와 같이 constant로 선언하면 *p로 값을 수정할 수 없기 때문에 print_st 함수는 원본의
값을 수정할 수 없는 함수가 된다.

	void print_st(const struct score *p)
	{
		...
	}

▶ 구조체 배열
구조체 변수가 많이 필요할 경우 구조체 배열을 사용한다. 지인의 주소록을 저장하기 위해 아래와 같이 struct address 구조체 형을 선언하였다. 주소록에는 이름, 나이, 전화번호, 주소에 대한 정보가 포함되어 있다. 이때 많은 지인의 주소록을 만드려면 구조체
배열을 선언해야 한다. 아래와 같이 구조체 배열을 선언하면 struct address형 변수 5개가 연속적으로 할당되며, 이 전체 공간의 이름은 a이다. 배열 a의 요소는 5개이며, 각각 a[0], a[1], ... a[4]로 나타낼 수 있다. 이때 각 요소는 모두 구조체이다. 배열 a를
초기화하려면 중괄호에 각 요소의 초기값을 적어야 하며, 각 요소는 구조체이기 때문에 중괄호를 열어 멤버의 초기값을 적어야 한다. 이때 첫 번째 지인의 이름을 출력하려면 첫 번째 지인에 먼저 참조한 후 멤버 name에 접근해야 한다. 즉 아래와 같이 a[0].name으로
접근하여 출력해야 한다. age 역시 첫 번째 지인인 a[0]에 먼저 접근하여 a[0].age로 멤버를 참조해야 한다.

	struct address
	{
		char name[20];
		int age;
		char tel[20];
		char addr[80];
	};

	int main(void)
	{
		struct address a[5] = { {"길민성", 24, "010-1234-5678", 경산시 진량읍" }, {	... }, ... , { ... } };
		printf("%s\n", a[0].name);
		printf("%d\n", a[0].age);
		...
	}

수 있 구조체 배열을 선언할 경우 구조체를 저장할 수 있는 공간이 연속적으로 할당되며 그 크기는 구조체의 크기에 배열요소의 개수를 곱한 값이다.

▶ 구조체 배열을 처리하는 함수
위에서 선언한 구조체 배열 a를 출력하는 함수 print_ary를 작성하려고 한다. 이때 배열명만 알면 모든 배열요소에 접근할 수 있기 때문에 배열명을 인수로 준다. 배열명은 첫 번째 요소의 주소값이고, 요소의 형태는 struct address이기 때문에 struct address의
주소값이 print_ary 함수의 인수로 넘어간다. 때문에 매개변수는 struct address 포인터를 선언해야 한다. 매개변수 p는 구조체 배열의 주소값이 저장되어 있다. 때문에 p에 -> 연산을 하여 각 멤버에 접근할 수 있다. 반복문을 통해 5번 반복하여 p가 가리키는
구조체의 멤버를 출력하도록 하였다. 이때 한 구조체의 멤버를 모두 출력하면 p에 1을 더하여 다음 구조체를 가리키도록 하였다.

	void print_ary(struct address *p)
	{
		for (int i = 0; i < 5; i++)
		{
			printf("이름: %s\n", p->name);
			printf("나이: %s\n", p->age);
			...
			p++
		}
	}

또한 p는 포인터이고 포인터에 배열명이 저장되어 있다. 때문에 포인터를 배열명처럼 사용하여 각 요소에 접근할 수 있다. 즉 p[0]은 첫 번째 배열 요소에 접근하고 p[1]은 두 번째 배열 요소를 접근한다. 때문에 p[i].name은 i번째 요소의 멤버 name에 접근하면
p의 값을 수정하지 않고 모든 요소에 접근할 수 있다.

	void print_ary(struct address *p)
	{
		for (int i = 0; i < 5; i++)
		{
			printf("이름: %s\n", p[0].name);
			printf("나이: %s\n", p[1].age);
			...
		}
	}

(*(p + i)).name
이때 *(p + i)는 p[i]와 같은 연산: p[i].name
또한 (*p).name은 p->name와 같은 연산: (p + i)->name

▶ 자기 참조 구조체
자기 참조 구조체는 맴버에 자기 자신의 변수의 주소를 저장하는 포인터가 있는 구조체이다. 연결 리스트를 만들 때 필수적으로 사용되는 구조체이다. 아래의 구조체 struct list형은 struct list형 포인터를 멤버로 갖고 있다. 즉 자기 자신의 주소를 저장할 수
있는 포인터가 멤버로 선언되어 있다.

	struct list
	{
		int num;
		struct list *next;
	};

이때 아래와 같이 struct list의 변수 a, b, c를 선언하여 초기화하였다. 이때 선언되지 않은 멤버 next는 NULL 포인터로 초기화된다. 구조체 a, b, c의 저장공간이 할당되며, padding byte가 없으면 8byte씩 할당된다. 이때 a, b, c가 각각 100, 200, 300번지부터
할당되었다고 하자. a의 num에는 10, b의 num에는 20, c의 num에는 30이 저장되어 있으며, a, b, c의 next에는 모두 NULL 포인터가 저장되어 있다. 이때 a.next는 struct list형 구조체 변수의 주소를 저장할 수 있으므로 아래와 b의 주소값을 저장할 수 있다. 또한
b.next에는 c의 주소값이 저장되어 있다. a.next에는 200번지가 저장되어 b 전체를 가리키고 있으며, b.next 300번지가 저장되어 c 전체 공간을 가리키고 있다. 때문에 a에만 접근할 수 있으면 모든 변수에 접근할 수 있다. 이와 같이 연결된 구조를 연결 리스트라고
한다. 양쪽으로 연결되어 있으면 double linked list이고, 아래와 같이 한쪽으로만 연결되어 있으면 single linked list라고 한다. a.num으로 a의 멤버 num에 접근할 수 있다. 또한 a.next는 b를 가리키고 있으므로 a.next->num은 b의 멤버 num에 접근하게 된다.
또한 a.next는 b를 가리키고 있으므로 a.next->next는 b의 멤버 next에 접근하고, b의 멤버 next는 c를 가리키고 있기 때문에 a.next->next->num은 c의 멤버 num에 접근하게 된다.

	int main(void)
	{
		struct list a = {10}, b = {20}, c = {30};
		a.next = &b;
		b.next = &c;
		a.num
		a.next -> num;
		a.next -> next -> num;
		...
	}

위와 같이 a로 b, c 모두에 접근할 수 있지만 100개가 연결되어 있다면 위와 같이 접근하는 것은 불편하다. 때문에 구조체 포인터가 각 구조체 변수의 위치를 기억해 가리키는 구조체를 하나씩 이동해가며 멤버를 사용하도록 코딩하는 것이 더 효율적이다. 구조체
포인터 tp를 선언하여 최초에는 변수 a를 가리키도록 하였다. 이때 a의 num에 접근하려면 tp->num와 같이 사용할 수 있다. tp가 다음 변수인 b를 가리키도록 tp의 값을 수정해야 한다. 이때 b의 주소값은 a의 next에 저장되어 있으며, a의 next는 tp->next로 접근할
수 있다. 때문에 tp = tp->next;가 실행되면 tp는 b를 가리키게 된다. 이러한 과정을 계속 반복하면 tp는 계속해서 다음 변수를 가리키게 된다. tp가 c를 가리키는 상황에서 tp = tp->next;가 실행되면 tp에는 NULL 포인터가 저장된다. 때문에 list의 끝에 도달하면
tp에는 NULL 포인터가 저장되며, tp가 NULL 포인터가 아닌 동안 반복하면 리스트의 모든 변수에 접근할 수 있다. 리스트의 모든 변수를 출력한 후 다시 처음부터 하려면 tp에 a의 주소값을 저장하면 된다.

	int main(void)
	{
		struct list a = {10}, b = {20}, c = {30};
		a.next = &b; b.next = &c;

		struct list *tp = &a;
		while (tp != NULL)
		{
			printf("%d", tp->num);
			tp = tp->next;
		}
		...
	}

일반적으로 연결 리스트의 각 요소는 변수 이름을 사용하지 않는다. 변수 이름이 있으면 굳이 연결 리스트를 만들 이유가 없다. 보통 동적 할당을 하여 이들을 연결하여 처리한다. 때문에 리스트의 시작 위치값을 기억해두어야 한다. 일반적으로 아래와 같이 포인터
head를 선언하여 head에 연결 리스트의 첫 번째 요소의 주소값을 저장한다. 이러한 포인터를 헤드 포인터라고 하며, 리스트의 각 요소는 node라고 한다.

	int main(void)
	{
		struct list a = {10}, b = {20}, c = {30};
		a.next = &b; b.next = &c;
		struct list *head = &a;

		struct list *tp = head;
		while (tp != NULL)
		{
			...
		}
		...
	}

▶ 공용체(union)
공용체는 구조체와 거의 비슷하다. 구조체와의 차이점은 다음과 같다.

1. 확보되는 저장공간과 사용방법
 구조체: 각 맴버들이 독립된 저장공간을 가지고 있다. 따라서 맴버가 많으면 그만큼 많은 저장공간을 할당해야 한다.
 공용체: 맴버가 많아도 맴버 중 크기가 가장 큰 맴버만큼만 저장공간이 확보된다. 나머지 맴버들은 이 공간을 공유한다.

2. 형태의 선언 방법
 공용체는 형태를 선언할 때 키워드 union을 사용한다. 그 외에는 구조체와 같다.

3. 초기화
 구조체: 중괄호 안에 멤버의 초기값을 나열하여 초기화한다. 각각의 맴버는 중괄호에 적힌 순서대로 초기화된다.
 공용체: 중괄호 안에 하나의 초기값만 쓰며, 첫 번째 맴버가 초기화된다. 다른 맴버로 초기화하려면 = {.맴버 = 초기값} 형태로 저장해야 한다.

아래의 코드는 학생의 정보를 저장할 공용체 union student의 형태를 선언하여 union student형 변수 a를 선언하는 문장이다. 변수 a가 구조체였다면 padding byte를 포함하여 num와 grade를 합한 크기만큼의 저장공간이 할당되지만 변수 a는 공용체이기 때문에
가장 크기가 큰 double형, 즉 8byte의 저장공간이 할당된다. 100번지부터 할당되었다면 107번지까지 할당되며, 이 전체 공간의 이름은 a이다. grade 멤버는 8byte의 저장공간을 모두 사용하지만 num 멤버는 100번지부터 103번지까지 4byte를 사용한다. a의 멤버에
접근하는 방법은 구조체와 동일하다. a.num에 정수를 대입하면 100번지부터 103번지에 정수값이 2진수 비트열로 변환되어 저장된다. 또한 printf 함수로 a.num을 출력하면 저장된 정수값이 출력된다. 이때 a.grade에 실수를 저장하면 100번지부터 107번지에 실수값을
IEEE754의 기준에 맞게 2진수 비트열로 저장한다. 이전에 저장한 정수값은 지워지고 새로운 실수가 저장되기 때문에 a.grade를 출력하면 정상적으로 출력되지만 a.num을 출력하면 이전의 값이 출력되지 않고 이상한 값이 출력된다. 

	union student
	{
		int num;
		double grade;
	}

	int main(void)
	{
		union student a;
		a.num = 201721026;
		printf("%d", a.num);
		a.grade = 4.5;
		printf("%d", a.num);
		printf("%lf", a.grade);
	}

또한 아래의 코드는 union student형 변수 b를 선언과 동시에 초기화하는 것이다. 아래와 같이 공용체는 중괄호 안에 하나의 값만 쓰며, 공용체의 첫 번째 멤버가 중괄호 안의 값으로 초기화된다. 즉 b가 선언되면서 b.num이 201721026으로 초기화된다. grade를
초기화하려면 아래와 같이 중괄호 안에 .grade = 4.5와 같이 써야 한다. 아래의 코드에서 c가 선언되면서 c.grade가 4.5로 초기화된다.

	int main(void)
	{
		union student b = { 201721026 };
		union student c = { .grade = 4.5 };
		...
	}

공용체는 한 번의 하나의 값만 대입하여 사용할 수 있으며, 멤버의 변수가 많더라도 저장공간이 늘어나지 않는다. 즉 공용체는 메모리를 효율적으로 관리할 수 있지만 가독성이 떨어지고 사용하기 불편하기 때문에 메모리가 충분하다면 가급적 사용하지 않는 것이
좋다. 어떤 저장공간을 다양한 자료형으로 사용해야 할 경우 공용체를 사용할 수 있다.

▶ 열거형(enum)
구조체나 공용체는 그 변수를 구성하는 형태들을 맴버로 나열한다. 하지만 열거형은 그 형태가 이미 int형으로 정의가 되어있고, 열거형 변수에 넣을 값들을 나열한다. 즉, 열거형 변수를 선언하면 4byte의 저장공간이 할당되며, 중괄호에 나열한 값들을 이 공간에
대입할 수 있다. 열거형을 선언할 때는 키워드 enum을 사용한다. 계절에 관련된 값들을 저장할 변수를 선언하려고 한다. 이를 위해 아래와 같이 열거형을 선언하였다. 이때 열거형의 이름은 enum season이 된다. 아래의 선언은 enum season형 변수에 spring,
summer, fall, winter의 값을 넣어서 쓰겠다는 것을 컴파일러에게 알리는 것이다.

	enum season { spring, summer, fall, winter };

위에서 선언한 열거형의 변수는 아래와 같이 선언할 수 있다. 아래의 코드는 enum season형 변수 a를 선언한 것이다. 아래의 코드가 실행되면 4byte의 int형 저장공간이 할당되며 그 이름은 a가 된다. 변수 a에는 열거 멤버값들을 대입하여 쓸 수 있다.

	enum season a;
	a = fall;

spring, summer, fall, winter와 같은 열거 멤버들은 컴파일 과정에서 정수값으로 바뀌며 그 값은 앞에서부터 차례대로 0, 1, 2, 3이다. 즉 위의 코드는 a에 3을 대입하는 것과 같다. 또한 멤버의 값을 아래와 같이 직접 정해줄 수도 있다. 아래와 같이 spring을
10으로 바꾸면 spring은 10이 되며, 그 다음 값들은 1씩 증가하여 summer, fall, winter는 각각 11, 12, 13이 된다.

	enum season { spring = 10, summer, fall, winter }
	
하지만 열거형 변수는 int형 변수와 똑같으며, 열거형 변수에 열거형 멤버를 대입하는 것은 int형 변수에 정수를 대입하는 것과 같다. 때문에 위와 같이 enum season형 변수에 fall을 대입하는 것은 int형 변수 a에 3을 대입하는 것과 같은 동작을 한다. 하지만
정수값을 직접 사용하여 코드를 작성하면 정수가 어떤 값을 의미하는지 알 수 없지만 열거형을 사용하면 정수를 기호화하여 코드를 작성할 수 있으며, 코드의 가독성이 높아진다. 

▶ typedef를 사용한 형 재정의
구조체, 공용체 등의 자료형은 자료형의 이름이 길고 어려워서 사용하는 데 불편함이 있다. 기존에 사용하던 자료형을 다른 새로운 이름으로 재정의하여 사용할 수 있는데 이때 typedef를 사용한다. 키워드 typedef는 형을 재정의해준다. 변수 선언문 앞에 typedef
키워드를 붙여주면 변수명은 자료형의 이름으로 바뀌며, 그 이름을 자료형으로써 사용할 수 있다. 아래와 같이 int형 변수 INT를 선언하면 INT는 변수명이지만, 변수의 선언문 앞에 typedef를 붙이면 INT는 형태명으로 바뀐다. 아래와 같이 선언한 이후로는 int형
변수를 선언할 때 int를 사용할 수도 있고 INT를 사용할 수도 있다.

	// int INT;
	typedef int INT;

	int a;
	INT b;

또한 아래의 선언문은 int형 포인터 IP를 선언하는 것이다. 하지만 선언문 앞에 typedef를 붙이면 변수명 IP는 형태명이 되며, 이후로 IP를 이용해 변수를 선언하면 int형 포인터가 선언된다. 때문에 아래와 같이 ap에 a의 주소값을 저장할 수 있다.

	// int* IP;
	typedef int* IP;

	IP ap, bp;
	ap = &a;

아래와 같이 선언된 구조체 형으로 구조체 변수 Student를 선언할 수 있다. 이때 변수 선언문 앞에 typedef를 붙이면 Student는 형태명으로 바뀌어 struct student 대신 Student로 구조체 변수를 선언할 수 있다. 아래의 변수 선언문은 Struct형 변수 st와
Struct형 포인터 pst를 선언하는 문장이다. 구조체의 형태를 재정의할 때 변수명과의 구분을 위해 관례적으로 앞 글자를 대문자로 쓴다.

	struct student
	{
		...
	};

	int main(void)
	{
		// struct student Student;
		typedef struct student Student;

		Student st, *pst;
		...
	}

구조체는 구조체의 형을 선언하는 동시에 변수 선언을 할 수 있다. 맴버를 나열한 후 중괄호를 닫고 세미콜론을 찍기 전에 변수명을 쓰면 선언한 형태의 구조체 변수가 선언된다. 아래의 코드는 구조체의 형 struct student를 선언하면서 struct student형 변수
Student를 동시에 선언하는 것이다. 이러한 선언을 함수 밖에 하면 Student는 전역변수가 된다.

	struct student
	{
		...
	} Student;

이러한 선언문 앞에도 아래과 같이 typedef을 쓰면 그 변수명은 형태명이 되며, 이 이후로 struct student 대신 Student를 이용해 변수를 선언할 수 있다.

	typedef struct student
	{
		...
	} Student;

또한 아래와 같이 타입 재정의문을 구조체 형 선언 앞에 위치시킬 수도 있다. 타입 재정의문을 먼저 쓰면 자기참조구조체를 선언할 때 재정의된 이름을 자기참조구조체의 선언문 안에서 쓸 수 있다. 즉 아래와 같이 사용할 수 있다.

	typedef struct student Student;
	struct student
	{
		Student* next;
		...
	};
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct score
{ // 구조체 포인터 설명에 필요한 구조체 형
	int kor;
	int eng;
	int mat;
};

struct address
{ // 구조체 배열 설명에 필요한 구조체 형
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

struct list
{// 자기 참조 구조체
	int num;
	struct list* next; // 구조체 struct list는 struct list 변수의 주소값을 저장할 수 있는 포인터 변수를 맴버로 가지고 있다.
};

union student
{ // 공용체 설명에 필요한 공용체 형
	int num;      
	double grade; 
};

typedef struct point
{ // 구조체에서 typedef를 이용해 형 선언과 동시에 이름 재정의
	char name;
	int x_pos;
	int y_pos;
}Point; // 구조체의 형태를 선언할 때 세미콜론 앞에 변수명을 써서 변수를 선언할 수 있다. 하지만 앞에 typedef를 쓰면 변수명 Point는 struct point 자료형의 이름이 된다.

typedef struct
{ // 구조체에서 typdef로 이름을 재정의할 때 이름을 생각하기도 함
	char name;
	int x_pos;
	int y_pos;
}Point2; // 구조체의 이름을 생략하고 바로 바꿀 이름을 기술하기도 한다. 이 구조체 형의 변수는 Point2를 사용하여 할 수 있다.


typedef struct list List; // struct list의 자료형을 미리 List로 재정의할 수 있다.
struct List
{
	int num;
	List* next;   // 자기참조 구조체에서 포인터를 선언할 때 struct list 대신에 List를 사용할 수 있다.
};

void print_st(const struct score*);
void print_ary(const struct address*);

int main(void)
{
	/*** 구조체 포인터와 -> 연산자 ***/
	struct score a;
	struct score *sp = &a; // 구조체 포인터 sp를 선언하여 a를 가리키도록 했다.
	a.kor = 90;
	a.eng = 80;
	a.mat = 75;
	(*sp).kor = 95;         // * 연산은 . 연산보다 우선순위가 느리기 때문에 *sp를 괄호로 감싸야한다.
	sp->kor = 80;           // 위 연산과 완벽하게 같다.
	printf("정수 입력: ");
	scanf("%d", &sp->kor);  // 주소연산 또한 할 수 있다. -> 연산은 우선순위가 가장 높기 때문에 &보다 먼저 계산된다.

	/*** 구조체 변수를 함수에서 포인터로 처리하기 ***/
	print_st(&a);    // print_st 함수의 인수로 a의 주소값을 넘긴다.

	/*** 구조체 배열 ***/
	struct address b[3] = { {"길민성", 23, "010-8833-7859", "경북 경산시"},
		{"이종민", 23, "010-0000-0000", "경북 경산시"},
		{"공종현", 23, "010-0000-0000", "경북 경산시"}, };

	printf("이름: %s\n", b[0].name);
	printf("나이: %d\n\n", b[0].age);   // 배열의 요소 또한 구조체이므로 맴버접근연산자를 사용할 수 있다.

	/*** 구조체 배열을 처리하는 함수 ***/
	print_ary(b);  // 구조체 배열의 배열명을 인수로 준다.

	/*** 자기 참조 구조체 ***/
	struct list x = { 10 }, y = { 20 }, z = { 30 }; // 두 번째 맴버는 NULL로 초기화된다.

	x.next = &y;     // x.next는 struct list형 구조체 변수의 주소값을 저장할 수 있다. y는 struct list형 구조체 변수이기 때문에 x.next에 &y를 저장할 수 있으며, x.next는 y 전체를 가리키게 된다.
	y.next = &z;     // y.next가 z 전체를 가리키고 있다.

	printf("x.num: %d\n", x.num);                         // 구조체 x의 맴버 num에 접근하여 출력할 수 있다.
	printf("x.next->num: %d\n", x.next->num);             // x.next는 y를 가리키고 있으며 x.next->num은 x.next가 가리키는 구조체의 맴버 num, 즉 y의 맴버 num를 참조한다.
	printf("x.next->next->num: %d\n\n", x.next->next->num); // x.next->next는 y의 맴버 next이며 이 맴버는 z의 주소값이 저장되어있다. 따라서 x.next->next->num은 구조체 z의 num를 참조한다.

	struct list* tp = &x;       // struct list형 구조체를 가리킬 수 있는 포인터 변수 tp를 선언하여 x를 가리키도록 초기화하였다.
	struct list* head = &x;     // 리스트의 시작 위치값을 저장하기 위해 head를 사용한다.
	while (tp != NULL)
	{
		printf("tp->num: %d\n", tp->num); // 최초로 실행할 때 tp는 x를 가리키고 있으므로 x의 맴버 num이 출력된다.
		tp = tp->next;       // tp->next에는 tp 다음 구조체의 주소가 저장되어있으므로 tp는 다음 구조체를 가리키게 된다. 이 과정을 반복하면 tp에 z.next가 저장되며, 이 값은 NULL이므로 반복문을 빠져나온다.
	}
	puts("");

	/*** 공용체 ***/
	union student c; // c에는 unions student에서 크기가 가장 큰 double형의 크기인 8byte만큼 공간이 확보된다. double형 맴버 grade는 8byte 전체를 사용하며 int형 맴버 nun은 앞에서부터 4byte만 사용한다.
	printf("sizeof(c): %d\n", sizeof(c));
	c.num = 201721026;             // 공용체는 구조체와 같이 맴버참조연산을 하여 맴버에 접근한다.
	printf("c.num: %d\n", c.num);
	c.grade = 3.5;                 // 전에 저장된 num의 값은 지워지고 새로운 실수값이 IEEE754에 맞게 저장된다.
	printf("c.grade: %lf\n", c.grade);
	printf("c.num: %d\n\n", c.num);  // c.num은 정상적으로 출력되지 않는다.

	union student d = { 201721026 };    // 첫 번째 맴버인 num으로만 초기화가 가능하다. 만약 grade로 초기화를 하려면 형태를 선언할 때 grade를 가장 위에 써야 한다.
	union student e = { .grade = 4.5 }; // 형태를 바꾸지 않고 grade로 초기화를 하는 방법

	/*** 열거형 ***/
	enum season {spring, summer, fall, winter}; // enum season 이라는 열거형의 변수에 spring, summer 등의 값들을 넣어서 사용하겠다고 컴파일러에게 알려주는 것이다.
	enum season f;                              // enum season형 변수를 선언할 수 있다.
	f = spring;                                 // enum season형 변수 f에 enum season의 맴버값을 넣을 수 있다. 0이 저장된다.
	printf("spring: %d\n\n", f);

	enum shape {point, line, tri = 3, rect, octa = 8}; // point, line은 0, 1이고, tri는 3으로 지정해주었으며 그 다음 맴버 rect는 4가 된다. octa는 8로 지정해주었다. 

	/*** 열거형 ***/
	typedef int INT;  // INT는 int 자료형으로써 사용할 수 있다.
	INT g, h;         // int형 변수 g, h가 선언된다.
	typedef int* IP;  // IP는 int*형으로써 사용할 수 있다.
	IP gp, hp;        // int*형 변수 gp, hp가 선언된다.
	gp = &g, hp = &h;

	typedef struct score Score; // struct score형 구조체 변수를 선언할 때 Score를 사용할 수 있다.
	Score i, *pi;               // struct score형 구조체 변수와 struct score형 포인터 변수가 선언된다.

	Point A, B;                 // struct point형 구조체 변수가 선언된다.

	return 0;
}


void print_st(const struct score* p)
{
	// 매개변수는 struct score형 변수의 주소값을 저장해야 하므로 struct score*로 선언한다.
	// 자료형 앞에 const를 붙이면 p로 간접참조하여 값을 수정하지 못하며, 함수에서는 값을 수정할 수 없게 된다.
	printf("국어: %d\n", (*p).kor);
	printf("영어: %d\n", p->eng);
	printf("수학: %d\n", p->mat);     // . 연산자와 -> 연산자를 모두 사용할 수 있다.
}

void print_ary(const struct address* p)
{
	// 인수는 struct address형 배열의 배열명이므로 struct address*형으로 선언해야 한다.
	// p에는 구조체 배열 첫 번째 요소의 주소값, 즉 &b[0]이 저장되어있다.
	for (int i = 0; i < 3; i++)
	{
		printf("이름    : %s\n", p->name);    // 최소 실행시 p에는 첫 번째 요소의 주소값이 저장되어있기 때문에 p->name은 첫 번째 구조체의 name 맴버에 접근한다.
		printf("나이    : %d\n", p->age);     // 포인터 변수에 배열명이 저장되어있으므로 p[i].age와 같이 변수를 배열명처럼 사용할 수 있다.
		printf("전화번호: %s\n", p->tel);
		printf("주소    : %s\n\n", p->addr);
		p++;                                  // p가 다음 구조체를 가리킬 수 있도록 주소연산을 해준다.
	}
}