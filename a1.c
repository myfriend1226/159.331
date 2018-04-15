
/* Family Name: Le
Given Name: An
Student ID :163494523
Assignment 1, 159.331 */
/* explain what the program is doing . . . */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {  //declaration
	char identifier[20];
	char expression[80];
	struct Node *next;
};
typedef struct Node Node;
Node *list;

void AddNode(Node ** listpointer, char idetifi[], char expressionn[]);
bool Search(Node *listpointer, char identifi[]);



char punctuation[8] = { '.',',',':',';','?','!','\0' };
char digit[11] = { '0','1','2','3','4','5','6','7','8','9','\0' };
char letter[60] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V',
'X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
'w','x','y','z','\0' };

int main(int argc, char*argv[]) {
	char line[200];
	printf("----------------------------------------\n");
	printf(" 159.331 Assignment 1 Semester 1 2018 \n");
	printf(" Submitted by: An Le, 16349453 \n");
	printf("----------------------------------------\n");
	printf("\n");
	int i = 0;

	while (true) {
		list = NULL;
		char *word;
		const char s[2] = " ";
		gets(line);

		word = strtok(line, s);


		//printf("%s %d", word, strlen(word));
		if (strcmp(word, "exit") == 0) {
			word = strtok(NULL, s);
			if (strcmp(word, ";") == 0) {
				break;
			}
		}

		if (strcmp(word, "set") == 0) {
			word = strtok(NULL, s);
			char iden[20];
			strcpy(iden, word);
			word = strtok(NULL, s);
			char express[200];
			express[0] = '\0';
			while (strcmp(word, ";") != 0) {
				if (Search(list, word)) {
					strcat(express, list->expression);
					word = strtok(NULL, s);
					if (strcmp(word, "+") == 0) {
						if (strcmp(word, "SPACE") == 0) {
							strcat(express, " ");
						}
						if (strcmp(word, "TAB") == 0) {
							strcat(express, "\t");
						}
						if (strcmp(word, "NEWLINE") == 0) {
							strcat(express, "\n");
						}
						if (Search(list, word)) {
							strcat(express, list->expression);
							word = strtok(NULL, " ");
						}

					}
					printf("add two identifier");
				}
				else {
					printf("%s\n", word);

					strcat(express, word);
					word = strtok(NULL, " ");
				}

			}
			AddNode(&list, iden, express);
			printf("add the new identidier\n%s\n%s\n", list->expression, list->identifier);

		}
		if (strcmp(word, "append") == 0) {
			word = strtok(NULL, s);
			while (strcmp(word, ";") != 0) {
				Search(list, word);
				strcat(list->expression, word);

			}
		}
		if (strcmp(word, "print") == 0) {
			word = strtok(NULL, s);
			printf("print commend %s %s", list->identifier, word);
			if (Search(list, word)) {
				printf("print commend %s %s", list->identifier, word);
				word = strtok(NULL, s);

				if (strcmp(word, ";") == 0) {
					printf("%s \n", list->expression);
					printf("found");
				}
			}
		}
		printf("print node %s %s", list->identifier, list->expression);
	}

}


void AddNode(Node ** listpointer, char idetifi[], char expressionn[]) {
	// add a new node to the FRONT of the list
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	strcpy(temp->identifier, idetifi);
	strcpy(temp->expression, expressionn);
	temp->next = *listpointer;
	*listpointer = temp;
}

bool Search(Node *listpointer, char identifi[]) {
	// search for the node with account number equal to x
	Node *current;
	current = listpointer;
	while (true) {
		if (current == NULL) { return false; }
		if (strcmp(current->identifier, identifi) == 0) {

			return true;
		}
		current = current->next;
	}
}