// uva 101
// this question description ganrantee that no invalid operation like when a block want to move back to its original position there is another block out there.
#include<cstdio>
#include<cstring>

using namespace std;
typedef struct Stack* SP;

struct Stack {
	int block[26];
	int top;
	Stack():top(0) {}
	int peek() {return block[top];}
	int pop() {return block[top--];}
	int push(int b) {block[++top]=b;}
	bool empty() {return top==0;}
};

SP *s;
int b2p[26];

void moveonto(int b1, int b2) {
	int b1pos = b2p[b1];
	int b2pos = b2p[b2];
	int popped,peeked;
	// returning all the blocks stacked on top of b2 to their original positions
	while((peeked=s[b2pos]->peek())!=b2) {
		s[b2pos]->pop();
		s[peeked]->push(peeked);
		b2p[peeked]=peeked;
	}
	// return all the blocks stacked on top of b1 to their original positions
	while((popped=s[b1pos]->pop())!=b1) {
		s[popped]->push(popped);
		b2p[popped]=popped;
	}
	// move
	s[b2pos]->push(popped);
	b2p[popped]=b2pos;
}

void moveover(int b1, int b2) {
	int b1pos = b2p[b1];
	int b2pos = b2p[b2];
	int popped,peeked;
	// return all the blocks stacked on top of b1 to their original positions
	while((popped=s[b1pos]->pop())!=b1) {
		s[popped]->push(popped);
		b2p[popped]=popped;
	}
	s[b2pos]->push(popped);
	b2p[popped]=b2pos;
}

void pileonto(int b1, int b2) {
	int b1pos = b2p[b1];
	int b2pos = b2p[b2];
	int popped,peeked;
	Stack temp;
	// returning all the blocks stacked on top of b2 to their original positions
	while((peeked=s[b2pos]->peek())!=b2) {
		s[b2pos]->pop();
		s[peeked]->push(peeked);
		b2p[peeked]=peeked;
	}

	while((popped=s[b1pos]->pop())!=b1) {
		temp.push(popped);
		b2p[popped]=b2pos;
	}
	temp.push(popped); //popped is b1
	b2p[popped]=b2pos;
	while(!temp.empty()) {
		s[b2pos]->push(temp.pop());
	}
}


void pileover(int b1, int b2) {
	int b1pos = b2p[b1];
	int b2pos = b2p[b2];
	int popped,peeked;
	Stack temp;
	while((popped=s[b1pos]->pop())!=b1) {
		temp.push(popped);
		b2p[popped]=b2pos;
	}
	temp.push(popped); //popped is b1
	b2p[popped]=b2pos;
	while(!temp.empty()) {
		s[b2pos]->push(temp.pop());
	}
}

int main() {
	char cmd[5],mode[5];
	int num,b1,b2;
	scanf("%d\n",&num);
	s = new SP[num];
	for(int i=0;i<num;i++) {
		s[i] = new Stack;
		s[i]->top=0;
		s[i]->push(i);
		b2p[i]=i;
	}
	while(true) {
		scanf("%s ",cmd);
		if(!strcmp(cmd,"quit")) break;
		scanf(" %d %s %d\n",&b1,mode,&b2);
		if(b1 == b2 || b2p[b1]==b2p[b2]) continue;
		if(!strcmp(cmd,"move")) {
			if(!strcmp(mode,"onto"))
				moveonto(b1,b2);
			else
				moveover(b1,b2);
		} 
		else if(!strcmp(mode,"onto")) 
			pileonto(b1,b2);
		else
			pileover(b1,b2);

	}
	for(int i=0;i<num;i++) {
		printf("%d:",i);
		for(int j=1;j<=s[i]->top;j++)
			printf(" %d",s[i]->block[j]);
		printf("\n");
		delete s[i];
	}
	delete [] s;
	return 0;
}