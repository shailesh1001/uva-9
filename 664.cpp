#include<cstdio>

// this code assumes that the input is in order from shortest string to longest string

bool match(char* a, char* b) {
	while(*a && *b) {
		if(*a++!=*b++) {
			return 0;
		}
	}
	return 1;
}

int main() {
	char a[1000][1000];
	int setnum = 0;
	while(EOF!=(scanf("%s",a[0]))) {
		int k=1;
		bool found_matched=0;
		while((scanf("%s",a[k]))!=EOF && a[k][0]!='9') {
			for(int i=0;i<k && !found_matched;i++) {
				if(found_matched=match(a[i],a[k]))
					break;
			}
			k++;
		}
		printf("Set %d is ",++setnum);
		if(found_matched)
			printf("not ");
		printf("immediately decodable\n");
	}
	return 0;
}