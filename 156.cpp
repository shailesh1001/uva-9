#include<cstdio>
#include<cstring> //strtok
#include<cctype>
#include<string>
#include<vector>
#include<cstdlib> //qsort
#include<map>
#include<iostream>

using namespace std;

int compare_ch(const void* _a, const void* _b) 
{
	char *a = (char*)_a;
	char *b = (char*)_b;
	return *a-*b;
}

int main(){
	vector<string> output;
	char row[100];
	map<string,string> sorted_unsorted;
	map<string,int> count;
	map<string,string> lowered_unlowered;

	while(fgets(row,sizeof(row),stdin),row[0]!='#') {
		row[strlen(row)-1] = '\0';
		char *pch = strtok(row," ");
		while(pch!=NULL) {
			
			char original[100];
			strcpy(original,pch);
			transform(pch,pch+strlen(pch),pch,::tolower);
			qsort(pch, strlen(pch), sizeof(char), compare_ch);
			lowered_unlowered[pch] = original;

			if(count.find(pch)==count.end())  // automatic conversion to string
				count[pch] = 1;
			else
				count[pch]++;

			pch = strtok(NULL," ");
		}
	}
	


	for(map<string,int>::iterator it=count.begin();it!=count.end();it++) {
		if(it->second==1)
			output.push_back(lowered_unlowered[it->first]);
	}

	sort(output.begin(),output.end());
	for(vector<string>::iterator it=output.begin();it!=output.end();it++)
		cout<<*it<<endl;

	return 0;
}