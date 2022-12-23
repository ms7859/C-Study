/*
main.c에 선언된 전역변수 cnt와 input_data.c에 선언된 전역변수 tot를 사용하기 위해 extern으로 변수를 선언하였다.
*/

extern int cnt;  // main.c의 전역변수 cnt 공유
extern int tot;  // input_data.c의 전역변수 tot 공유

double average2(void)
{
	return tot / (double)cnt;
}