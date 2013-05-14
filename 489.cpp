#include<cstdio>
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
	int n;
	string c,g;
	while((scanf("%d",&n),n) != -1) {
		cin >> c >> g;
		set<char> correct;
		set<char> guessed;

		for(int i=0;i<c.size();i++) {
			correct.insert(c.at(i));
		}
		int correct_num = correct.size();
		int stroke = 7;
		printf("Round %d\n",n);

		for(int i=0;i<g.size();i++) {
			if (!stroke || !correct_num) {
				break;
			}
			if (!correct.count(g.at(i))) {
				if(!guessed.count(g.at(i))) {
					stroke--;
				}	
				guessed.insert(g.at(i));	
			} else {
				if(!guessed.count(g.at(i))) {
					correct_num--;
				}		
				guessed.insert(g.at(i));
			}
		}
		if(!correct_num) {
			printf("You win.\n");
		} else if (!stroke) {
			printf("You lose.\n");
		} else {
			printf("You chickened out.\n");
		}
	}
	return 0;
}