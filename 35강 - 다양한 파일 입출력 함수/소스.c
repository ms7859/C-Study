/*
▶ fgets, fputs 함수
데이터를 한 줄씩 파일로 입출력하는 함수이다. fputs는 인수로 문자열의 첫 번째 주소값과 저장할 파일을 가리키는 포인터를 준다. fgets는 문자열을 저장할 배열명, 출력 문자의 최대 개수, 출력할 파일 포인터를 준다. a.txt에 "apple"을 입력하고 b.txt에
저장된 데이터를 한 줄 가져와 str에 저장하려면 다음과 같이 코드를 작성해야 한다.

	char* fp = fopen("a.txt", "r");
	char* ofp = fopen("b.txt", "w");
	char str[20];

	fputs("apple", ofp);
	fgets(str, sizeof(str), fp);

▶ 다양한 형태로 입력하는 fscanf 함수
파일에 데이터가 수치값 형태로 되어있으면 한 줄 전체를 하나의 문자열로 입력한 후에 다시 수치값으로 바꾸는 복잡한 과정이 필요하다. 이런 경우에 형식에 따라 자동으로 데이터를 변환하여 입출력하는 함수를 사용하는 것이 더 편리하다. score.txt에는 아래와
같이 학생 세 명의 점수가 저장되어 있다. 이때 score.txt에서 이름과 점수를 읽어 각 학생의 총점과 평균을 구하는 프로그램을 만드려고 한다. 

	길민성 70 85 95 
	이종민 60 85 90
	공종현 90 50 40

이름은 문자열이기 때문에 char형 배열에 저장해야 한다. 또한 점수 역시 문자열 형태로 입력되어 있지만 이를 수치값 형태로 바꾸어서 저장해야한다. fgets로 한 줄 전체를 가져오면 문자열에서 점수 부분은 따로 뽑아서 수치값으로 바꿔야 하는 복잡한 과정이
필요하다. 이때 문자열은 문자열대로, 수치값 형태의 문자열은 수치값을 바꾸어 데이터를 가져오는 함수가 fscanf 함수이다. fscanf 함수는 첫 번째 인수로 파일포인터를 주고, 두 번째 인수부터는 scanf 함수와 같이 변환 문자와 저장할 변수의 주소값을 준다.
즉 아래의 코드가 실행되면 score.txt의 파일에서 문자열 "길민성"은 문자열의 형태로 가져와 name 배열에 저장하고 문자열 "70", "85", "95"는 수치값 70, 85, 95로 변환하여 각각 kor, eng, mat로 변환한다.

	FILE* fp;
	char name[20];
	int kor, eng, mat, total;
	double avg;

	fp = fopen("a.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%s%d%d%d", name, &kor, &eng, &mat);
	tot = kor + eng + mat;
	avg = tot / 3.0;

fscanf 함수 역시 함수가 호출될 때 이미 파일의 끝이라면 -1을 반환한다.

▶ 형식에 맞춰 파일로 출력하는 fprintf 함수
위에서 구한 점수의 총합과 평균을 화면에 출력하려면 아래와 같이 코드를 작성해야 한다.

	printf("%10s%5d%7.1lf\n", name, tot, avg);

하지만 이를 파일로 출력하려면 아래와 같이 코드를 수정해야 한다.

	FILE* ofp;
	ofp = fopen("score2.txt", "w");

	fprintf(ofp, "%10s%5d%7.1lf\n", name, tot, avg);

▶ 파일의 끝을 확인하는 feof 함수
파일의 끝을 확인하는 함수이다. 인수로 검사할 파일의 포인터를 주며, 파일의 끝이라면 1을 반환하고 파일의 끝이 아니라면 0을 반환한다. feof의 반환값이 참이 아닌동안 반복문을 실행하여 파일의 끝까지를 입력받을 수 있다.

▶ 버퍼 공유 문제와 fflush 함수
파일 입출력함수는 같은 입력 버퍼와 출력 버퍼를 공유한다. 입력함수들이 버퍼를 공유함으로써 생기는 문제가 있다. 다음의 데이터가 저장된 input.txt 파일에서 나이와 이름을 입력받아 출력하는 프로그램을 만드려고 한다.

	23
	Gil MS

나이를 입력받기 위해 fscanf 함수에 변환문자 %d를 사용하여 호출하였다. 또한 이름을 입력받기 위해 fgets 함수를 호출하였다. 최초로 fscanf 함수가 호출되면 데이터를 가지러 input.txt 파일의 스트림 파일이 가리키는 버퍼로 간다. 이때 버퍼가 비어있기 때문에
하드디스크에서 input.txt 파일에 저장된 데이터 전체를 가져와 버퍼에 저장한다. 즉 "23\nGil MS\n"이 버퍼에 저장된다. 버퍼가 채워졌기 때문에 fscanf 함수는 버퍼에서 "23"을 가져와 수치값 23으로 바꾸어 age에 저장한다. 그 후 fgets 함수가 호출되고,
데이터를 가지고 버퍼로 간다. 이전 scanf 함수에 의해 23이 입력되고 \n이 남아있기 때문에 데이터를 가지러 가서 처음 만나는 문자는 개행문자이다. 하지만 fgets 함수는 개행문자까지를 읽도록 설계되어 있기 때문에 개행문자만 가지고 와서 name에 개행문자를
저장하고 NULL 문자를 저장하고 입력을 마친다.

	FEIL* fp;
	int age;
	char name[20];
	fp = fopen("a.txt", "r");

	fscanf(fp, "%d", &age);
	fgets(name, sizeof(name), fp);


이러한 문제를 해결하기 위해 23 뒤의 개행문자를 제거하는 작업이 필요하다. 이를 위해 fscanf 함수를 호출한 후 fflush 함수를 호출하면 버퍼에 있는 모든 데이터가 삭제되며, 이름을 입력받지 못하는 문제점을 여전히 해결하지 못한다. fflush 함수는 입력파일에
대해서는 사용하면 안 되며, 표준으로 정의 또한 되어있지 않다. 키보드로 입력할 때는 fflush를 사용할 수 있다. fflush 함수 대신에 fgetc 함수를 호출하여 버퍼로부터 개행문자 하나만 가져와 제거하면 된다. 즉 아래와 같이 fgetc 함수를 호출하면 23 뒤의
개행문자가 제거되기 때문에 fgets 함수는 이름을 제대로 가져올 수 있다.

	fscanf(fp, "%d", &age);
	fgetc(fp);
	fgets(name, sizeof(name), fp);

▶ fread와 fwrite 함수
fread와 fwrite는 변환 없이 바로 입출력을 하는 함수이다. 이 함수는 형식에 따라 입출력을 하지 않기 때문에 변환과정을 수행하지 않는다. 대량의 데이터를 빠르게 출력하고 입력해야 할 때 메모리에 있는 비트열를 그대로 떠서 파일로 출력하여 저장하고, 그
파일을 그대로 가져와 메모리에 넣으면 그 데이터를 사용할 수 있다. 아래와 같이 변수 a를 할당하여 10을 저장하였다. 이때 a가 100번지부터 할당되었다면 103번지까지 총 4byte가 할당되며, 이 공간에는 10진수 10이 2진 비트열 형태로 저장되어 있다. a에 저장된
값을 fprintf 함수에 변환문자 %d를 사용하여 파일로 출력한다면 a에 저장된 10의 2진 비트열을 '1'의 아스키코드값, '0'의 아스키코드값의 비트열로 바꾸어서 저장하며, 그 크기는 2byte가 된다. 하지만 변환 과정을 거치지 않고 4byte의 비트열을 그대로 출력하려면
fwrite 함수를 호출해야 한다. fwrite 함수는 인수로 출력할 데이터가 있는 메모리의 위치, 출력할 데이터의 크기, 개수, 파일포인터를 준다. 아래의 코드는 100번지부터 a의 크기에 개수인 1을 곱한 4byte 만큼의 비트열을 fp가 가리키는 파일을 저장한다.

	FILE* fp;
	int a = 10;
	fp = fopen("b.txt", "wb");

	fwrite(&a, sizeof(a), 1, fp);

fwrite 함수로 파일을 출력할 떄는 반드시 binary 모드로 파일을 열어야 한다. binary 모드로 파일을 개방하지 않으면 기본적으로 텍스트 모드로 개방되는데 fwrite 함수도 binary 모드와 text 모드에 따라 각각 출력하는 방법이 다르게 설계되어 있다. 따라서
원하지 않는 방식대로 출력할 가능성이 있다. 우리가 출력해야 할 값은 10인데 이를 개행문자로 생각하여 carriage return, 개행문자 이렇게 2byte의 문자를 출력할 수도 있다. 때문에 있는 그대로 파일로 출력하려면 반드시 binary 모드로 개방해야 한다. fwrite
함수로 파일에 있는 그대로 출력한 비트열을 다시 메모리에 갖다 놓으려면 fread 함수를 호출해야 한다. fread 함수 역시 읽어들일 공간의 주소값, 크기, 개수, 파일 포인터를 인수로 준다. 즉 아래와 같이 b.txt를 rb로 열어 fread 함수를 호출해야 한다.

	FILE& fp;
	int a;
	fp = fopen("b.txt", "rb");

	fread(&a, sizeof(a), 1, fb);

구조체의 경우 형식에 따라 출력하려면 맴버의 형식에 맞게 하나씩 입출력해야 하지만 fread와 fwrite에 구조체 변수의 주소와 크기, 개수를 주면 구조체를 변환 없이 저장할 수 있다. 배열은 배열은 배열의 시작 위치인 배열명, 배열요소의 크기, 배열요소의 개수를
인수로 주어 배열을 저장할 수 있다. 정수는 4byte 크기로 표현되지만 5자리 이상의 정수를 아스키코드로 변환하여 저장하면 크기가 4byte보다 커질 수 있다. 따라서 변환을 하지 않고 저장하는 것이 더 효율적인 방법이 될 수도 있다. 하지만 비트열을 바로
저장하면 우리가 눈으로 볼 수 있는 코드로 변환되지 않기 때문에 파일을 열어서 직접 확인은 할 수 없다.

▶ 파일 입출력 함수 정리

	ch = fgetc(fp)					하나의 문자 입력
	fgets(str, sizeof(str), fp)		한 줄의 문자열 입력
	fscanf(fp, "%d", &a)			형식에 따라 입력
	fread(&a, sizeof(a), 1, fp)		변환 없이 입력

	fputc(ch, ofp)					하나의 문자 출력
	fputs(str, sizeof(str), ofp)	한 줄의 문자열 출력 
	fprintf(ofp, "%d", a):			형식에 따라 출력
	fwrite(&a, sizeof(a), 1, ofp)	변환 없이 입력

▶ 개방 모드('+' 모드)
	"r+" : 읽기모드로 파일을 열었지만 출력함수로 쓸 수도 있다.
	"w+" : 쓰기모드로 파일을 열었지만 입력함수로 읽을 수도 있다. rewind 함수에 파일포인터를 인수로 주고 호출하여 그 버퍼에서 현재 읽는 위치를 맨 앞으로 옮길 수 있다.
	"a+" : append 모드로 파일을 열었지만 읽을 수도 있다. rewind 함수나 fseek 함수를 호출하여 위치지시자를 조절할 수 있다.

fseek(fp, offset, wherefrom) 함수는 버퍼에서 위치지시자를 원하는대로 옮길 수 있는 함수이다. 첫 번째 인수는 파일포인터이며 두 번째 인수는 기준점으로부터 몇 바이트 떨어진 곳인지를 정수로 주고, 세 번째 인수는 기준점을 정하기 위해 사용한다. 세 번째
인수는 하나의 정수값으로, 기호로써 정의되어있다. 기호에는 SEEK_SET, SEEK_CUR, SEEK_END이 있다.
	SEEK_SET: 파일의 첫 번째 바이트를 기준으로 한다. 이때 offset은 음수를 사용할 수 없다.
	SEEK_CUR: 현재의 위치지시자를 기준으로 한다.
	SEEK_END: 파일의 마지막 바이트를 기준으로 한다. offset은 음수가 되어야 한다.

출력을 마치면 위치지시자는 맨 끝에 있기 때문에 위치지시자를 읽을 데이터로 옮겨야 데이터를 읽을 수 있다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	/*** fgets와 fputs 함수 ***/
	FILE* fp = fopen("a.txt", "w"); // 파일 개방
	// 검사 생략
	fputs("apple apple apple apple apple apple\nstrawberry strawberry strawberry strawberry", fp); // fp가 가리키는 파일에 문자열 입력
	fclose(fp);

	FILE* fp2 = fopen("a.txt", "r");
	char str[20];                   // 문자열을 가져와 저장할 변수
	// 검사 생략
	fgets(str, sizeof(str), fp2);   // fp2에서 데이터를 한 줄 가져와 str에 저장한다. 이때 저장할 문자의 개수는 최대 20개이다.
	printf("%s\n\n", str);
	fclose(fp2);

	/*** fscanf와 frpintf 함수 ***/
	char name[20]; // 이름을 저장할 char형 배열
	int a, b, c;
	FILE* fp3 = fopen("score.txt", "r");
	FILE* ofp3 = fopen("score2.txt", "w");
	// 검사 생략
	while (!feof(fp3))
	{
		fscanf(fp3, "%s%d%d%d", name, &a, &b, &c);            // 아스키코드값으로 저장된 데이터를 변환문자에 맞게 입력받아 변환하여 각각의 변수에 넣는다.
		int total = a + b + c;
		double avg = total / 3.0;
		fprintf(ofp3, "%10s %5d %7.1lf\n", name, total, avg); // 변수에 저장된 비트열을 변환문자에 맞게 아스키코드값으로 변환하여 ofp3에 출력한다.
	}
	fclose(fp3); fclose(ofp3);

	/*** 버퍼 공유 문제와 fflush 함수 ***/
	FILE* finput;
	int age;
	char name2[20], name3[20];
	finput = fopen("buffer_problem.txt", "r");
	// 검사 생략
	fscanf(finput, "%d", &age);      // 17을 입력받아 수치값으로 바꾸어 age에 저장한다.
	fgetc(finput);                   // 17을 입력받고 남은 \n 문자를 입력받는다. 버퍼에 입력된 \n 문자를 소모하기 위한 것이다.
	fgets(name2, sizeof(name2), finput); // 이름이 name2에 저장된다. 이름 뒤에 입력한 엔터도 name2에 저장한다.

	printf("%d, %s===\n\n", age, name2, name3);

	/*** fread와 fwrite 함수 ***/
	int m = 10; // 4byte 공간에 10이 2진수로 변환되어 비트열로 저장된다.

	FILE* tmp = fopen("아스키코드10.txt", "w");
	fprintf(tmp, "%d", m); // m에 저장된 비트열을 10진수의 수치값 10으로 해석하여 문자 1과 0이 출력되며, 파일의 크기는 2byte이다.
	fclose(tmp);

	FILE* fp4 = fopen("비트열10.txt", "wb"); // fwrite로 출력하려면 바이너리 모드로 파일을 열어야 한다.
	fwrite(&m, sizeof(m), 1, fp4); // 비트열10.txt 파일에 m에 저장된 비트열이 변환없이 그대로 출력된다.
	fclose(fp4);

	FILE* ofp4 = fopen("비트열10.txt", "rb");
	int n;
	fread(&n, sizeof(n), 1, ofp4);
	fclose(ofp4);
	printf("%d", n);
	
	return 0;
}