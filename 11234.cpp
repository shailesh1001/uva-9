// uva 11234 本题参考 思路 http://blog.csdn.net/shuangde800/article/details/7707123
// 补充几点  表达式树 是从最底层网上进行计算的  有根据题目用queue的特性 所以 层序遍历表达式树之后逆序输出即可

#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

struct Node{
	char data;
	Node* left;
	Node* right;	
};

stack<Node*> st;
queue<Node*> qu;
stack<Node*> out;
char str[10005];

// level order traversal
void bfs() {
	Node *head = st.top(), *p;
	st.pop();
	qu.push(head);
	while(!qu.empty()) {
		p = qu.front();
		qu.pop();
		out.push(p);
		if(p->left)
			qu.push(p->left);
		if(p->right)
			qu.push(p->right);
	}
}

void buildtree() {
	// build the tree;
	for(int i=0;i<strlen(str);i++) {
		Node *node = new Node;
		node->data = str[i];
		if(node->data>='a' && node->data<='z') {
			node->left = node->right = NULL;
			st.push(node);
		} else {
			Node *pright, *pleft;
			pright = st.top(); // first must be right, since the problem says 
							   // To make the solution unique, you are not allowed to assume that the operators are associative or commutative.
			st.pop();
			pleft = st.top();
			st.pop();
			node->left = pleft;
			node->right = pright;
			st.push(node);
		}
	}
}


int main() {
	int n;
	scanf("%d",&n);
	getchar();
	while(n--) {
		gets(str);
		buildtree();
		bfs();
		while(!out.empty()) {
			printf("%c",out.top()->data);
			delete out.top();
			out.pop();
		}
		putchar('\n');
	}
	return 0;
}