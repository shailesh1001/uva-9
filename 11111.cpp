// uva 11111
// thought from http://blog.csdn.net/cgl1079743846/article/details/7757457
// self-code
#include<stack>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std;
const int MAXN = 1000010;
char line[MAXN];
struct Toy {
	int val,rest;	
};

int main() {
	int ans;
	char *p;
	
	Toy toy;
	while(gets(line)) {
		stack<Toy> stk;
		queue<Toy> que;
		p = strtok(line," ");
		bool ans = false;
		while(p) {
			toy.val = atoi(p);
			toy.rest = abs(toy.val);
			que.push(toy);
			p=strtok(NULL," ");
		}
		if(que.size() %2 == 0) {
			bool flag = true;
			while(!que.empty()) {
				Toy temp = que.front();
				que.pop();
				if(temp.val<0) {
					if(!stk.empty() && -temp.val > stk.top().rest) {
						ans = false;
						break;
					}
					stk.push(temp);
				} else if(temp.val>0) {
					if(!stk.empty() && temp.val + stk.top().val==0 && stk.top().rest > 0) {
						stk.pop();
						if(!stk.empty())
							stk.top().rest -= temp.val;
					} else {
						ans = false;
						break;
					}
				}
			}
			if(stk.empty())
				ans = true;
			else
				ans = false;
		} 
		if (ans)
            printf(":-) Matrioshka!\n");
        if (!ans)
            printf(":-( Try again.\n");
	}
	return 0;
}