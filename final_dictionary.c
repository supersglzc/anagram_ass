#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

void print_list(VNode *head){
	VNode *cur = head;
	while(cur){
		printf("%s ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

int compare_function(const void *a, const void *b) {
	return *(char*)a - *(char*)b;
}

int main (int argc, char ** argv) {
	
	DNode* result;
//	char * a = "from";
//	char * b = "form";
//	char * c = copystr(a);
//	char * d = copystr(b);
//	qsort(c, strlen(c), sizeof(char), compare_function);
//	qsort(d, strlen(d), sizeof(char), compare_function);
//	printf("%s, %s\n", c, d);	
	//either static or use calloc - to set all bytes initially to 0
	static DNode* dictionary [DEFAULT_HASH_SIZE]; 
	for(int i = 0;i < DEFAULT_HASH_SIZE; i++){
    		dictionary[i] = NULL;
	}	

	FILE * file = fopen("words.txt", "r");
	char buffer[25];
	//int ct = 1;
	while(fscanf(file, "%s", buffer) != EOF){
	//	printf("count: %d\n", ct);
		char * key = copystr(buffer);
		qsort(key, strlen(key), sizeof(char), compare_function);
		set(dictionary, DEFAULT_HASH_SIZE, key, buffer);
		free(key);
	//	ct ++;
	}
	int count = 0;
	for (int i = 0; i < DEFAULT_HASH_SIZE; i++){
		if (dictionary[i]!=NULL){
//			count ++;
			result = get(dictionary, DEFAULT_HASH_SIZE, dictionary[i]->key);
			VNode * head = (result->values)->next;
			if(head){
				printf("Anagram for '%s':\n",(result->values)->value);
		                while(head){
                		        printf("%s\n", head->value);
                        		head = head->next;
              			}
				count ++;
			}
//			printf("index: %d, Anagrams of %s are : ", count, dictionary[i]->key);
//			print_list(result->values);
		}
	}
	printf("There are total %d anagrams lists.\n", count);
	free_dictionary(dictionary, DEFAULT_HASH_SIZE);

	
	return 0;
}
