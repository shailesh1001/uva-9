// uva 340
/*
这道题目英文原题觉得有点问题 特别是independent那里没有看懂 找到一个中文解释：

Master-Mind是一种2个人的游戏。 其实就是学生常玩的几A几B的游戏（规则或许有些许不同）。 
其中一个人担任出题者，他选一串1到9数字 当作密码（可以重复）。 另一个人为解题者，他要去猜密码为何。 
解题者每次猜测后，出题者以某种格式回答他这次猜的结果。 在游戏开始之前，双方先协议密码的长度，假设是n。 
在出题者设定密码（s1,s2,...sn） 后，由解题者来猜（g1,g2,...gn）。 如 果同样位置gi=si， 那解题者得到一个A。 如果gi=sj，但i不等于j，那解题者得到一个B。 
请注意：不管是得A或得B，每个 gi最多只能对应到一个sj，而且得A比得B优先。 
举例说明：密码为1 2 3 4，若猜题者猜1 1 5 6，那出题者应该回答1A0B，而不是0A1B。 如果某个猜测得到 nA0B，那就代表猜题者完全猜中密码了。

下面是代码写的可能复杂些，我没优化，今天做得太多了，累的要命，就不再优化了
*/


/*My solution has to be very careful for temp variable set/reset and pay attention to erasing while looping*/
/* my solution thought is:  do iteration twice, first run will calculate how many strongs and remove them;
second run will iterate through the rest and find the weaks  */


#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

vector<int> s;
vector<int> g;
int allzero(vector<int> p, int size) {
	for(int i=0;i<size;i++) {
		if(p[i]!=0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n, *p, num=1;
	cin>>n;
	while(n) {
		s.clear();
		for(int i=0;i<n;i++) {
			int temp;
			cin>>temp;
			s.push_back(temp);
		}
		g.clear();
		for(int i=0;i<n;i++) {
			int temp;
			cin>>temp;
			g.push_back(temp);
		}
		cout<<"Game "<<num<<":"<<endl;
		while(!allzero(g,n)) {
			int left=n;
			int strong=0,weak=0;
			vector<int> s_tmp = s;
			int n_tmp=n;

			// calculating how many strong
			for(int i=0;i<n_tmp;i++) {
				if(s_tmp[i]==g[i]) {
					strong++;
					left--;
					s_tmp.erase(s_tmp.begin()+i); // 边遍历边erase  有问题
					g.erase(g.begin()+i);
					n_tmp--;	// because we erase one, so have to decrease the n_tmp by one
					i--;        // erased current one so next loop start from same position
				}
			}

			// calculate how many weak, the judgement is a littble bit different than when calculating strong
			// this time we are looping through s_tmp_size(), not through an n_tmp
			for(int i=0;i<left;i++) {
				for(int j=0;j<s_tmp.size();j++) {
					if(s_tmp[j]==g[i]) {
						weak++;
						s_tmp.erase(s_tmp.begin() + j);
						break;
					}
				}
			}

			
			cout<<"    ("<<strong<<","<<weak<<")"<<endl;
			g.clear();
			for(int i=0;i<n;i++) {
				int temp;
				cin>>temp;
				g.push_back(temp);
			}
		}
		num++;
		cin>>n;
	}
	return 0;
}