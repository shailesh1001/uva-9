// uva 10420


#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<cctype>

using namespace std;


bool compare (string a, string b) {return a<b;}

int main() {
	int n;
	char sen[100];
	cin>>n;
	getchar();
	map<string,set<string> > themap;

	vector<string> countries;

	for(int i=0;i<n;i++) {
		gets(sen);

		string first_word = "";
		int start =0;

		// start to separate words and store them into set
		for(int i=0;i<strlen(sen)&&first_word=="";) {

			//escape leading spaces

			for(;i<strlen(sen);i++) {
				if(isalnum(sen[i])) {
					start = i;
					break;
					
				}
			}
			//find the tail for a word
			
			for(;i<strlen(sen);i++) {
				if(isspace(sen[i])) {
					char words[100];
					char temp = sen[i];
					sen[i]='\0';
					strcpy(words,sen+start);
					sen[i]=temp;
					first_word = words; // automatic type conversion
					start = i;
					break;
				}
			}
		}
		char name[100];
		strcpy(name,sen+start+1);
		string name_str = name;
		themap[first_word].insert(name_str);
	}
	// sort the countries in the universe
	for(map<string,set<string> >::iterator it = themap.begin(); it!=themap.end();it++) {
		countries.push_back(it->first);
	}

	sort(countries.begin(),countries.end(),compare);

	for(vector<string>::iterator it=countries.begin();it!=countries.end();it++) {
		cout<<*it<<" "<<themap[*it].size()<<endl;
	}
	return 0;// sort the countries in the universe

}

















/////////////////////////////////
// Solution 2
// 10420 - List of Conquests    pasted from    http://ajmarin.alwaysdata.net/codes/problems/302/
/////////////////////////////////
/*
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
unsigned int cnum,i,j,n;
char *cname, *wn, line[400];
struct country{
	char name[100];
	unsigned int count;
	bool operator()(country a, country b){
		return (strcmp(a.name,b.name)<0);
	}
}c[2000];
int main(void){
	scanf("%u\n",&n);
	cnum = 0;
	while(n--){
		gets(line);
		cname = strtok(line," ");		
		for(i = 0; i != cnum; i++) 
			if(strcmp(cname,c[i].name)==0) break;
		if(i != cnum){
			c[i].count++;
		} else {
			strcpy(c[i].name,cname);
			c[cnum++].count = 1;
		}
	}
	sort(c,c+cnum,country());
	for(i = 0; i != cnum; i++)
		printf("%s %u\n",c[i].name,c[i].count);
	return 0;
}
*/




