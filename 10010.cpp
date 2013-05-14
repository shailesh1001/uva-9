#include<cstdio>
#include<cstring>
#include<cctype>


struct point {
	int x,y;
};

typedef struct point Point;

//find whehter string p is in matrix **a (m*n)
Point find(char (*a)[52], int m,int n, char *p) {
	Point point;
	int plen = strlen(p);
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			//left
			int k=0;

			for(int z=j;z>=1 && k<plen;z--,k++) {
				if(a[i][z]!=p[k]) {
					break;
				}
			}
			if(k==plen) {
				point.x = j;
				point.y = i;
				return point;
			}
			//right
			k = 0 ;
			for(int z=j;z<=n && k<plen;z++,k++) {
				if(a[i][z]!=p[k]) {
					break;
				}
			}
			if(k==plen) {
				point.x = j;
				point.y = i;
				return point;
			}
			//up
			k = 0;
			for(int z=i;z>=1 && k<plen;z--,k++) {
				if(a[z][j]!=p[k]) {
					break;
				}
			}
			if(k==plen) {
				point.x = j;
				point.y = i;
				return point;
			}
			//down
			k =0 ;
			for(int z=i;z<=m && k<plen;z++,k++) {
				if(a[z][j]!=p[k]) {
					break;
				}
			}
			if(k==plen) {
				point.x = j;
				point.y = i;
				return point;
			}
			//left up
			k = 0;
			for(int z=i,w=j; z>=1 && w>=1 && k<plen; z--,w--,k++) {
				if(a[z][w]!=p[k]) {
					break;
				}
			}
			if(k==plen) {
				point.x = j;
				point.y = i;
				return point;
			}
			//right down
			k =0 ;
			for(int z=i,w=j; z<=m && w<=n && k<plen; z++,w++,k++) {
				if(a[z][w]!=p[k]) {
					break;
				}
			}
			if(k==plen) {
				point.x = j;
				point.y = i;
				return point;
			}
			//left down
			k =0 ;
			for(int z=i,w=j; z<=m && w>=1 && k<plen; z++,w--,k++) {
				if(a[z][w]!=p[k]) {
					break;
				}
			}
			if(k==plen) {
				point.x = j;
				point.y = i;
				return point;
			}
			//right up
			k =0;
			for(int z=i,w=j; z>=1 && w<=n && k<plen; z--,w++,k++) {
				if(a[z][w]!=p[k]) {
					break;
				}
			}
			if(k==plen) {
				point.x = j;
				point.y = i;
				return point;
			}

		}
	}
	point.x = 0;
	point.y = 0;
	return point; // not found
}

int main()
{
	char a[52][52];
	char b[51];
	int num,m,n,k;

	scanf("%d",&num);
	getchar();
	for(int i=0;i<num;i++) {
		scanf("%d %d\n",&m,&n);


		for(int i=1;i<=m;i++) {
			scanf("%s",a[i]+1);
			a[i][0] = 'a'; //preventing it from been '\0' which will break the strlen(a[i]) later on in next line
			for(int j=1;j<strlen(a[i]);j++) {
				if(isupper(a[i][j]))
					a[i][j] += 32; //convert all to lowercase
			}
		}

		// test cases
		scanf("%d",&k);
		for(int i=0;i<k;i++) {
			scanf("%s",b);

			for(int j=0;j<strlen(b);j++) {
				if(isupper(b[j]))
					b[j] += 32; //convert all to lowercase
			}

			Point x = find(a,m,n,b);
			// since all words appeard at least once in the grid so we don't need to check nonexistence case
			printf("%d %d\n",x.y,x.x);
		}
		if (i!=num-1)
			printf("\n");
	}



	return 0;
}