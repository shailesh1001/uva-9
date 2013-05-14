// uva 10152  自己编码 但是思路借鉴
/*http://www.myexception.cn/program/520086.html*/
/*解题思路：  要使步骤最少，那么要保证相对顺序是符合目标序列的不要进行移动（即最大公共子序列不要进行移动）。 
 可以设置两个坐标指向两个数组的最后一个，然后往前枚举，碰到相同的，则两个坐标都减1， 如果不相同的，则初始数组的坐标减一。
 最后指向初始数组的坐标移动到了尽头，会发现目标数组的坐标还没到尽头，那么在这个坐标之前的都是不符合顺序的，就要移动这些乌龟。 
  然后剩下的这些乌龟， 按目标数组的逆序输出即可。*/

#include<cstdio>
#include<cstring>
char origin[250][85], desire[250][85];

int main() {
	int num,k;
	scanf("%d",&num);
	getchar();
	while(num--) {
		scanf("%d",&k);
		getchar();
		for(int i=0;i<k;i++) 
			gets(origin[i]);
		for(int i=0;i<k;i++) 
			gets(desire[i]);
		int i=k-1,j=k-1;
		for(;i>=0&&j>=0;) {
			if(!strcmp(desire[j],origin[i])){
				i--; j--;
			} else {
				i--;
			}
		}
		while(j>=0)
			puts(desire[j--]);
		printf("\n");  // there is an empty line in each output set
	}
	return 0;
}