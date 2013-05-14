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
		memset(s+len,0,sizeof(s)-len*sizeof(int)); // this line is very important, it will set all the prefix to 0, which is the ground of the following algorithms
		return *this;
	}

	const bign operator = (int num) {
		char temp[maxn];
		sprintf(temp,"%d",num);
		*this = temp; //*this is already existed, so will call assignment operator instead of copy constructor
		return *this;
	}

	bool operator <(const bign& x) const {
		if(len!=x.len) return len<x.len;
		for(int i=len-1;i>=0;i--)
			if(s[i]!=x.s[i])
				return s[i]<x.s[i];
		return false;
	}


	bool operator >(const bign& x) const {
		return x<*this;
	}

	bool operator >=(const bign& x) const {
		return !(x<*this);
	}

	bool operator <=(const bign& x) const {
		return !(*this<x);
	}

	bool operator !=(const bign& x) const {
		return x<*this || *this<x;
	}

	bool operator ==(const bign& x) const {
		return !(x<*this) && !(*this<x);
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

	bign operator ++() {
		int result = (s[0] + 1)%10;
		int c = (s[0] + 1) / 10;
		s[0] = result;
		if(c>0) {
			for(int i=1;c && i<len;i++) {
				int temp = (s[i]+c);
				s[i] = temp%10;
				c = temp/10;
			}
		}
		if(c)
			s[len++] = c;

		return *this;
	}

	// pre condition we have already set all the unused cell to be 0
	/*
	const bign operator * (const bign& x) const {
		bign result;
		result.len = 0;
			
		for(int i=0;i<x.len;i++) {
			bign temp;
			temp.len=0;
			int c=0;
			for(int j=0;j<len+1;j++) {
				int product = s[j] * x.s[i] + c;
				temp.s[temp.len++] = product%10;
				c = product/10;
			}
			if(temp.s[temp.len-1]==0)
				temp.len--;
			for(int k=0;k<i;k++) // every iteration will make the temp times 10
				temp.len++;
			result = result+temp;
		}
		return result;
	}
	*/
	// this version is too slow
	/*const bign operator * (const bign& x) const {
		bign i(0);
		bign result(0);
		for(i;i<x;++i) {
			result = result + *this;
		}
		return result;
	}
	*/

	const bign operator * (const bign& x) const {
		bign temp_nine[10];//temp_nine[i] will store i*(*this) i倍的*this
		temp_nine[0]=0;
		
		//special case for operand 0
		if(this->s[0]==0 && this->len==1 || x.s[0]==0 && x.len==1)
			return bign();//bign(0)

		for(int i=1;i<=9;i++) {
			temp_nine[i] = *this + temp_nine[i-1];
		}

		// this part is where this algorithm is fast, the number of iteration is only x.len not the value of x
		bign result;
		for(int i=0;i<x.len;i++) {
			bign temp;
			int temp_nine_len = temp_nine[x.s[i]].len;
			for (int j=i,k=0;k<temp_nine_len;k++,j++) {
				temp.s[j]=temp_nine[x.s[i]].s[k];
			}
			temp.len = i + temp_nine_len;
			result = result+temp;
		}

		return result;

	}

	int get_len() {return len;}
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
	bign x,y;
	while(cin>>x>>y) {
		bign temp=x*y;
		cout << temp << endl;
	}

	return 0;
}