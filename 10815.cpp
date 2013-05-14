#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<cstdio>
using namespace std;


void insert(string words[], string word, int* size) {
    //insert in order in to words[], but only insert unique word that is not existed in words[]
    if (*size==0) {
        words[(*size)++] = word;
        return ;
    }
    bool is_moved=false;
    for(int i=*size-1;i>=0;i--) {
        if(word<words[i]) {
            words[i+1] = words[i];
            is_moved = true;
            if(i==0) {
                words[0] = word;
                (*size)++;
                break;
            }

        } else if(word==words[i]) {
                    //if found existed before, reverted the previous shift.
            if(is_moved) 
                for(int j=i+1;j<*size;j++)
                    words[j] = words[j+1];
            break;
        } else {
            words[i+1] = word;
            (*size)++;
            break;
        }
    }

}

int split_and_insert(string words[], string row, int* size) {
    int start =0;
    string word="";
    for(int i=0;i<row.size();) {
        if(isalnum(row[i])) {
            while(isalnum(row[i]) && i<row.size())
                i++;
            word = row.substr(start,i-start);
            transform(word.begin(),word.end(),word.begin(),::tolower);
            insert(words,word,size);
            start = i;
        } else {
            while(!isalnum(row[i]) && i<row.size()) 
                i++;
            start = i;
        }
    }
}


int main() {

    string row;
    string words[1000001];
    int words_size = 0;
    while(getline(cin,row)) {
        if(row!="") {
            split_and_insert(words,row,&words_size);
        }
    }
    for(int i=0;i<words_size;i++) {
        printf("%s\n",words[i].c_str());
    }

    return 0;
}