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


struct pile {
	Card card[52];
	int left,right,size;
	pile():left(-1),right(-1),size(-1) {
		memset(card,0,sizeof(card));
	}
	Card top() {
		return card[size-1];
	}
} Pile[52];

void move(int i) {
	int left3set = 0, left1set=0;//whether left 3 exist and
	if(i<=0);
	if(Pile[i].left>=0 && Pile[Pile[i].left].left>=0 && Pile[Pile[Pile[i].left].left].left >=0 )
	{
		int left3 = Pile[Pile[Pile[i].left].left].left;
		if(match(Pile[i].top(),Pile[left3].top())) {
			left3set = 1;
			Card movecard = Pile[i].top();
			Pile[i].size--;
			Pile[left3].size++;
			Pile[left3].card[Pile[left3].size-1] = movecard;
			if(Pile[i].size==0) {
				goodpile--;
				Pile[Pile[i].left].right = Pile[i].right;
				if(Pile[i].right<52)
					Pile[Pile[i].right].left = Pile[i].left;
			}
			move(left3);
		} 
	} 
	if(!left3set) {
		if(Pile[i].left>=0) {
			int left1 = Pile[i].left;
			if(match(Pile[i].top(),Pile[left1].top())) {
				left1set=1;
				Card movecard = Pile[i].top();
				Pile[i].size--;
				Pile[left1].size++;
				Pile[left1].card[Pile[left1].size-1] = movecard;
				if(Pile[i].size==0) {
					goodpile--;
					Pile[Pile[i].left].right = Pile[i].right;
					if(Pile[i].right<52)
						Pile[Pile[i].right].left = Pile[i].left;
				}
				move(left1);
			}
		}
	}
	return ;
}

int main() {
	char h;
	int i;
	while((h=IN)!='#') {
		goodpile = 52;
		for(i=0;i<52;i++) {
			while(isspace(h))
				h = IN;
			Pile[i].card[0].value = h; 
			h = IN;
			Pile[i].card[0].suit = h;
			Pile[i].left = i-1;
			Pile[i].right = i+1;
			Pile[i].size = 1;
			h = IN;
		}

		/*for(int i=0;i!=52;i=Pile[i].right)
			printf(" %d %c%c",Pile[i].size,Pile[i].top().value,Pile[i].top().suit);*/
		
	

			for(int i=0;i!=52;i=Pile[i].right) {
				move(i);
				for(int i=0;i!=52;i=Pile[i].right)
					printf("%c%c ",Pile[i].top().value,Pile[i].top().suit);
				printf("\n");
			}
			
		
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

