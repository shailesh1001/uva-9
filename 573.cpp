// uva 573
// This problem is not perfect because every day the up distance is decreased by fatigue*first_day_up not fatigue*previous_day_up as described in the problem

#include<cstdio>

int main() {
	int H,U,D,F;
	while(scanf("%d %d %d %d",&H,&U,&D,&F), H!=0) {
		double up = 0.0;
		double u = U;
		double _u = U*F*1.0/100.0;
		for(int i=1;;i++) {
			up += u;
			if(up>H) {
				printf("success on day %d\n",i);
				break;
			}
			up -= D;
			if(up<0) {
				printf("failure on day %d\n",i);
				break;
			}
			u = u-_u;
			if(u<0)
				u=0;
		}
	}
	return 0;
}