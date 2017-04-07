/******************************************************/
/*	Program to find all the lexicographically unique  */
/*	permutations of a string and print their rank	  */
/*	Input:											  */
/*		int - length of string (max 500)			  */
/*		string - input string						  */
/******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 500

int comparator(const void* a, const void* b){
	char p = *(char*)a;
	char q = *(char*)b;
	return p-q;
}

void findLexOrder(char *str){
	char* temp = malloc(sizeof(char)*501);
	int rank = 0;
	int len = strlen(str);
	strcpy(temp, str);
	qsort(temp, strlen(str), sizeof(char), comparator);
	printf("%s : %d\n",temp, rank);
	while(1){
		int i = 0;
		int swapped = 0;
		for(i = len-1; i > 0; i--){
			if(temp[i] > temp[i-1]){
				char t = temp[i];
				temp[i] = temp[i-1];
				temp[i-1] = t;
				rank++;
				swapped = 1;
				break;
			}
		}
		if(swapped == 0)
			break;
		printf("%s : %d\n",temp, rank);
	}
	free(temp);
}

int main(int argc, char const *argv[])
{
	char* str = malloc(sizeof(char)*501);
	int n;
	scanf("%d", &n);
	if(n > MAXLEN) {
		printf("Max length exceeded. Max should be 500\n");
		return 1;
	}
	scanf("%s", str);
	findLexOrder(str);
	free(str);
	return 0;
}