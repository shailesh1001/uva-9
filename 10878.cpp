#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main() {
	string row;
	while(getline(cin,row)) {
		char value=0;
		if(string::npos!=row.find(".")) {
			if(row[1]=='o')
				value += 2*2*2*2*2*2*2;
			if(row[2]=='o')
				value += 2*2*2*2*2*2;
			if(row[3]=='o')
				value += 2*2*2*2*2;
			if(row[4]=='o')
				value += 2*2*2*2;
			if(row[5]=='o')
				value += 2*2*2;
			if(row[7]=='o')
				value += 2*2;
			if(row[8]=='o')
				value += 2;
			if(row[9]=='o')
				value += 1;
			putchar(value);
		}
	}
	return 0;
}