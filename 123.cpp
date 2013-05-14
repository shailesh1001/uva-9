// uva 123
// thought,  append each keyword sentence order number and word order position in that sentence, combmined them together as whole new keyword,
// and sort them. when output use the appended information to decode which sentence to print, which position of this word in that sentence.


#include<iostream>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<cstdlib>

using namespace std;
int main() {
	char ignore[1000];
	char row[250][10001];
	set<string> ignore_set;
	vector<string> words;
	scanf("%s",ignore);
	getchar();
	while(strcmp(ignore,"::")) {
		for(int i=0;i<strlen(ignore);i++)
			ignore[i] = tolower(ignore[i]);
		ignore_set.insert(ignore);
		scanf("%s",ignore);
		getchar();
	}



	int k=0;
	while((fgets(row[k],sizeof(row[0]),stdin))!=NULL) {
		if(row[k][strlen(row[k])-1] == '\n')
			row[k][strlen(row[k])-1] = '\0';
		
		char reserve[10001];
		strcpy(reserve, row[k]);//strtok will break row[k] so save a copy

		char *pch = strtok(row[k]," ");
		int word_pos =0;

		while(pch) {
			for(int i=0;i<strlen(pch);i++) 
				pch[i] = tolower(pch[i]);
			if(ignore_set.count(pch)==0) {
				for(int i=0;i<strlen(pch);i++)
					pch[i] = toupper(pch[i]);
				string s(pch);

				char pos[10];
				sprintf(pos,"%d",word_pos);
				string posstr(pos);

				char kk[10];
				sprintf(kk,"%d",k);
				string sen_num(kk);

				s = s+"-"+sen_num+"-"+posstr;
				words.push_back(s);
			}
			word_pos++;
			pch = strtok(NULL," ");
		}
		strcpy(row[k],reserve);
		k++;
	}

	sort(words.begin(),words.end());
	for(int i=0;i<words.size();i++) {
		int first_dash_pos = words[i].find_first_of("-",0);
		int second_dash_pos = words[i].find_first_of("-",first_dash_pos+1);

		string sen_num = words[i].substr(first_dash_pos+1,second_dash_pos-first_dash_pos-1);
		string pos = words[i].substr(second_dash_pos+1,words[i].length()-second_dash_pos-1); //position in that sentence e.g. in the following sentence "ni hao ma", hao's position in sentence is 2  (second word)
		string word = words[i].substr(0,first_dash_pos);

		int temp = atoi(sen_num.c_str());
		char reserve[10001];
		strcpy(reserve,row[temp]);
		char *pch = strtok(row[temp]," ");
		
		vector<string> output;
		int pos_tmp =0;
		while(pch) {
			for(int i=0;i<strlen(pch);i++)
				pch[i] = toupper(pch[i]);

			if(!strcmp(pch,word.c_str()) && pos_tmp==atoi(pos.c_str()))
				output.push_back(pch);
			else {
				for(int i=0;i<strlen(pch);i++)
					pch[i] = tolower(pch[i]);
				output.push_back(pch);
			}
			pos_tmp++;
			pch = strtok(NULL," ");
		}
		strcpy(row[temp],reserve);
		// start to output this sentence
		for(int i=0;i<output.size();i++) {
			if(i==output.size()-1)
				cout<<output[i]<<endl;
			else
				cout<<output[i]<<" ";
		}
	}
	return 0;
}






// method pasted from the internet, this method has similar thought with me, it maintains a global idxnum as additional sort information.

/////////////////////////////////
// 00123 - Searching Quickly
/////////////////////////////////
/*
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
using namespace std;
set < string > s;
char ignore[100];
char title[1000];
char temp[1000];
char * part;
int i, idxnum;
struct KWIK {
	int n;
	char key[1000];
	char phrase[1000];
	bool operator()(KWIK a, KWIK b){
		int cmp = strcmp(a.key,b.key);
		return (cmp<0 || (cmp==0 && a.n < b.n));
	}
} idx[1000];
int main(void){
	idxnum = 0;
	gets(ignore);
	while(strcmp(ignore,"::")){
		for(i = 0; ignore[i]; i++) if(isupper(title[i])) ignore[i] += 32;
		s.insert(string(ignore));
		gets(ignore);
	}
	while(gets(title)){
		int t_len = 0, len_now;
		for(i = 0; title[i]; i++) if(isupper(title[i])) title[i] += 32;
		strcpy(temp,title);
		part = strtok(temp," ");		
		while(part!=NULL){
			len_now = strlen(part);			
			if(s.find(part) == s.end()){
				strcpy(idx[idxnum].key,part);
				strcpy(idx[idxnum].phrase,title);
				idx[idxnum].n =idxnum;
				for(i = t_len; i < t_len+len_now; i++) idx[idxnum].phrase[i] -= 32;
				idxnum++;
			}
			t_len += len_now+1;
			part = strtok(NULL," ");
		}
	}
	sort(idx,idx+idxnum,KWIK());
	for(i = 0; i < idxnum; i++)
		puts(idx[i].phrase);
	return 0;
}
*/



