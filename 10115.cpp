#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

void do_replace(string* replace, string& sentence, int size) {
	for(int i=0;i<size-1;i+=2) {
		int pos;
		while((pos=sentence.find(replace[i]))!=string::npos) {
			string temp = sentence.substr(0,pos) + replace[i+1] + sentence.substr(pos+replace[i].length(),sentence.length()-pos-replace[i].length());
			sentence = temp;
		}
	}
}

int main(){
	int n;
	string *replace;
	string sent;
	while((scanf("%d",&n))!= EOF && n!=0) {
		getchar();
		replace = new string[n*2];
		for(int i=0;i<n*2;i++) {
			getline(cin,replace[i]);
		} 
		getline(cin,sent);
		do_replace(replace, sent, n*2);
		delete [] replace;
		cout<<sent<<endl;
	}	
	return 0;
}
