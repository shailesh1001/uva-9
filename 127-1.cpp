#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#define IN getc(stdin)

int goodpile = 52;

struct Card {
	char value,suit;
};

bool match(Card a, Card b) {
	return a.value==b.value || a.suit == b.suit;
}

typedef struct pile* ptr;
struct pile {
	Card card[52];
	ptr left,right;
	int size,deleted;
	pile():left(NULL),right(NULL),size(NULL) {
		memset(card,0,sizeof(card));
	}
	Card top() {
		return card[size-1];
	}
};

void move(ptr pp) {
	int left3set = 0, left1set=0;//whether left 3 exist and
	if(!pp) return ;
	if(pp->left && pp->left->left && pp->left->left->left )
	{
		ptr pleft3 = pp->left->left->left;
		if(match(pp->top(),pleft3->top())) {
			left3set = 1;
			Card movecard = pp->top();
			pp->size--;
			pleft3->size++;
			pleft3->card[pleft3->size-1] = movecard;
			if(pp->size==0) {
				goodpile--;
				pp->left->right = pp->right;
				if(pp->right)
					pp->right->left = pp->left;
				
				pp->deleted = 1;
			}
			move(pleft3);
		} 
	} 
	if(!left3set) {
		if(pp->left) {
			ptr pleft1 = pp->left;
			if(match(pp->top(),pleft1->top())) {
				left1set=1;
				Card movecard = pp->top();
				pp->size--;
				pleft1->size++;
				pleft1->card[pleft1->size-1] = movecard;
				if(pp->size==0) {
					goodpile--;
					pp->left->right = pp->right;
					if(pp->right)
						pp->right->left = pp->left;
					
					pp->deleted = 1;
				}
				move(pleft1);
			}
		}
	}
	return ;
}

int main() {
	char h;
	int i;
	ptr head,pre,p;
	while((h=IN)!='#') {
		goodpile = 52;
		for(i=0;i<52;i++) {
			if(i==0) {
				head = new pile;
				pre = head;
				while(isspace(h))
					h = IN;
				head->card[0].value = h; 
				h = IN;
				head->card[0].suit = h;
				head->left = NULL;
				head->right = NULL;
				head->deleted = 0;
				head->size = 1;
				h = IN;
			} else {
				p = new pile;
				while(isspace(h))
					h = IN;
				p->card[0].value = h; 
				h = IN;
				p->card[0].suit = h;
				p->left = pre;
				pre->right = p;
				p->right=NULL;
				p->size = 1;
				p->deleted=0;
				move(p);
				if(!p->deleted)
					pre = p;
				else {
					pre->right=NULL;
				}
				h = IN;
				for(ptr pp=head;pp;pp=pp->right)
					printf(" %d %c%c",pp->size,pp->top().value,pp->top().suit);
				printf("\n");
			}
		}

		/*for(ptr pp=head;pp;pp=pp->right)
			printf(" %d %c%c",pp->size,pp->top().value,pp->top().suit);
		printf("\n");*/
	
		/*for(int k=0;k<22;k++){
		for(ptr ppp=head;ppp;ppp=ppp->right) {
			move(ppp);
			for(ptr pp=head;pp;pp=pp->right)
				printf(" %d %c%c",pp->size,pp->top().value,pp->top().suit);
			printf("\n");
		}
		}*/

		
		if(goodpile>1)
			printf("%d piles remaining:",goodpile);
		else if(goodpile==1)
			printf("1 pile remaining:");
		/*for(int i=0;i!=52;i=Pile[i].right)
			printf(" [%d]   %d-%c%c(%d)-%d",Pile[i].size,Pile[i].left,Pile[i].top().value,Pile[i].top().suit,i,Pile[i].right);
		printf("\n");*/
		
	}
	return 0;
}

