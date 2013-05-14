// uva 327
// thought from http://www.ackratos.com/blog/?p=387
// self-coded

#include<cstdio>
#include<cstring>
int result;

void process(char line[],int operand_pos,int value[]) {
	int pre_i,i = operand_pos-1, temp=0;
	while(i>=0 && line[i]==' ')
		i--;
	//found the operator
	// if it is the prefix increment/decrement
	if(i>=0&&i-1>=0&&line[i-1]!=' '&&line[i-1]==line[i]) {
		if(line[i]=='+') {
			value[line[operand_pos]-'a']++;
		} else {
			value[line[operand_pos]-'a']--;
		}
		// if prefix, try to find if there is any operator before the prefix
		int j=i-2;
		while(j>=0&&line[j]==' ')
			j--;
		if(j<0 || line[j]=='+') // j<0 means this operand is the first operand
			result += value[line[operand_pos]-'a'];
		else
			result -= value[line[operand_pos]-'a'];
	} else{
		// else find if it contains suffix increment/decrement
		pre_i = i;
		i = operand_pos + 1;
		while(i<strlen(line) && line[i]==' ')
			i++;
		if(i<=strlen(line)-1 && i+1<=strlen(line)-1 && line[i]==line[i+1]) {
			if(line[i]=='+') 
				temp = 1;
			else
				temp = -1;
		}
		if(line[pre_i]=='+' || pre_i<0) // pre_i<0 means this operand is the first operand
			result += value[line[operand_pos]-'a'];
		else
			result -= value[line[operand_pos]-'a'];
		value[line[operand_pos]-'a'] += temp;
	}
}


int main() {
	char line[1000];
	int value[26]; // this will store the value of a, b, c,...z
	int appeared[26]; // this will record which letter appeared
	while(gets(line)) {
		for(int i=0;i<26;i++) {
			value[i] = i+1;
			appeared[i] = 0;
		}
		result = 0;
		for(int i=0;i<strlen(line);i++)
			if(line[i]>='a' && line[i]<='z') {
				appeared[line[i]-'a'] = 1;
				process(line,i,value);
			}
		printf("Expression: %s\n",line);
		printf("    value = %d\n",result);
		for(int i=0;i<26;i++)
			if(appeared[i])
				printf("    %c = %d\n",i+'a',value[i]);
	}
	return 0;
}