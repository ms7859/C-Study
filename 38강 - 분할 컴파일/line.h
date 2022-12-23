#include "point.h"  // 구조체형 Point를 사용하기 위해 point.h를 inckude 하였다.

typedef struct
{
	Point first;    // point.h를 include했기 때문에 구조체형 Point를 사용할 수 있다.
	Point second;
} Line;