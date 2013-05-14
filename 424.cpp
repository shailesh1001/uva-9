#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn=1000;

class bign{
private:
	int len, s[maxn];
public:
	bign() {memset(s,0,sizeof(s)); len = 1;}
	const bign operator = (const char* num){
		len = strlen(num);
		for(int i=0;i<len;i++)
			s[i] = num[len-i-1] - '0';
		memset(s+len,0,sizeof(s)-len*sizeof(int));
		return *this;
	}

	const bign operator = (int num) {
		char temp[maxn];
		sprintf(temp,"%d",num);
		*this = temp; //*this is already existed, so will call assignment operator instead of copy constructor
		return *this;
	}

	const bign operator ++(int) {
		int result = (s[len-1] + 1)%10;
		int c = (s[len-1] + 1) / 10;
		s[len-1] = result;
		if(c>0) {
			for(int i=len-2;c && i>=0;i--) {
				s[i] = (s[i]+c)%10;
				c = (s[i]+c)/10;
			}
		}
		return *this;
	}

	bign(int num) {*this = num;}
	bign(const char* num) {*this = num;}

	string str() const {
		string res ="";
		for(int i=0;i<len;i++) 
			res = (char)(s[i]+'0') + res;
		if(res=="") res="0";
		return res;
	}                                                                                                                                                             friend istream& operator >>(istream&, bign&);          


	// pre condition we have already set all the unused cell to be 0
	const bign operator + (const bign& x) const {
		bign n;
		n.len=0;   // A class has access to all its objects <Absolute C++> 2nd Edition, pp. 333
		for(int i=0,c=0;i<max(len,x.len)+1; i++) // A class has access to all its objects <Absolute C++> 2nd Edition, pp. 333
		{
			int temp = s[i] + x.s[i] + c;
			n.s[n.len++] = temp%10;
			c = temp/10;
		}
		if(n.s[n.len-1]==0) // the last set positions
			n.len--;
		return n;
	}
	
};
istream& operator >>(istream& in, bign& x) {
	string s;
	in>>s;
	x = s.c_str();
	return in;
}             
ostream& operator <<(ostream& out, bign& x){
	out<<x.str();
	return out;
}  





int main() {
	char s[200];
	bign x(0);
	while(EOF!=(scanf("%s",s)) && strcmp(s,"0")) {
		x = x + s; //automatic type conversion
	}
	cout<<x<<endl;
}