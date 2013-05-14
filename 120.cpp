// uva 120
// thought: from right to left each iteration find the max and the position.
// if the max is on the rightmost, we are done for this iteration;
// if max is in the middle we need to revolve it to the front then reverse it to the rightmost;
// if the max is at the front, revolve it to the rightmost;


#include<cstdio>
#include<cstring>
#include<cstdlib>

struct maxval {
	int val,pos;
};

typedef struct maxval MaxVal;


MaxVal findmax(int stack[], int size) {
	int maxval=stack[0],maxpos=0;
	// start from left to right guarantees that leftmost maxvalue prevails others
	for(int i=1;i<size;i++) {
		if(stack[i]>maxval) {
			maxval = stack[i];
			maxpos = i;
		} 
	}
	MaxVal mv;
	mv.val = maxval;
	// this check guarantees that rightmost maxvalue prevails others
	if(stack[size-1]==maxval) {
		mv.pos = size-1;
	} else {
		mv.pos = maxpos;
	}
	return mv;
}


void revolve(int stack[],int pos) {
	int temp;
	for(int i=0;i<=pos/2;i++) {
		temp = stack[i];
		stack[i] = stack[pos-i];
		stack[pos-i] = temp;
	}
}


int main() {
	char s[1000],*p;
	int stack[50];
	while((fgets(s,sizeof(s),stdin))!=NULL) {
		p = strtok(s," ");
		int k=0;
		while(p!=NULL) {
			stack[k++] = atoi(p);
			p = strtok(NULL," ");
		}


		// print original one
		for(int i=0;i<k-1;i++) {
			printf("%d ",stack[i]);
		}
		printf("%d\n",stack[k-1]);

		int first_move = 1;
		for(int i=k;i>=1;i--) {
			MaxVal mv = findmax(stack,i);
			if(mv.pos!=i-1) {
				if(mv.pos!=0) {
					// biggest is in the middle
					// revolve to make the biggest to the leftmost position
					if(first_move) {
						printf("%d",k-mv.pos);  //because we stored pancakes from left to right but it counts from right to left stating from 1
						first_move = 0;
					} else {
						printf(" %d",k-mv.pos);  //because we stored pancakes from left to right but it counts from right to left stating from 1
					}
					
					revolve(stack,mv.pos);

					// revolve to make the biggest to current right position
					printf(" %d",k-i+1);
					revolve(stack,i-1);
				} else {
					// biggest is at the leftmost position, just need to revolve once to make it to the right position
					if(first_move) {
						printf("%d",k-i+1);
						first_move = 0;
					} else {
						printf(" %d",k-i+1);
					}
					revolve(stack,i-1);
				}
			}
		}

		if(first_move)
			printf("0\n"); // already sorted.
		else
			printf(" 0\n");


	} 
	return 0;
}


