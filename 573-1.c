#include <stdio.h>
#include <stdlib.h>

int p[ 20 ];
int a[ 20 ][ 15 ];

int main()
{
	int H,U,D,F; 
	while ( scanf("%d%d%d%d",&H,&U,&D,&F) && H+U+D+F ) {
		double  u = U;
		double _u = U*F/100.0;
		double  d = D;
		double  h = 0.0;
		int     days = 0;
		while( 1 ) {
			++ days;
			h += u;
			if ( h > H ) {
				printf("success on day %d\n",days);
				break;
			}
			h -= d;
			if ( h < 0 ) {
				printf("failure on day %d\n",days);
				break;
			}
			u -= _u;
			if ( u < 0 ) u = 0;/*注意*/
		}
	}
	return 0;
}
