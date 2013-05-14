/* uva 579   clock angle */
#include<cstdio>
#include<cstring>
#include<cstdlib>
int main() {
	int hh,mm;
	double actual_h_angle;
	double actual_m_angle,diff;
	double temp;
	while(scanf("%d:%d",&hh,&mm),hh+mm) {
		actual_m_angle = mm * 6;
		actual_h_angle = (hh+mm/60.0)/12 * 360;
		diff = actual_m_angle - actual_h_angle;
		if(diff<0) {
			diff = -diff;
		}
		temp = (int(diff))%360;
		temp = temp + diff - (int(diff));
		if(temp>180)
			temp = 360 - temp;
		printf("%.3f\n",temp);
	}
	return 0;
}