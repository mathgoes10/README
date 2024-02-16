//Matheus Lima
//UCF ID:5590443
//Lab Assignment 4

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char letter;
  struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
  int count = 0;
  node* t = head;
  while (t != NULL) {
    count++;
    t = t->next;
  }
  return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head) {
  if (head == NULL) return NULL;
  int stringLength = length(head);
  node* t = head;
  int i = 0;

  char* string = (char*)malloc(sizeof(char) * (stringLength + 1));

  while (t != NULL) {
    string[i] = t->letter;
    t = t->next;
    i++; // Increment i to move to the next index in the string array
  }

  string[stringLength] = '\0'; // Set the null terminator at the end of the string
  return string;
}

// inserts character to the linkedlist
// If the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) {
  if (pHead == NULL) return;
  node* t = *pHead;
  if (t == NULL) {
    *pHead = (node*)malloc(sizeof(node));
    (*pHead)->letter = c;
    (*pHead)->next = NULL;
  } else {
    while (t->next != NULL) {
      t = t->next;
    }
    node* newnode = (node*)malloc(sizeof(node));
    newnode->letter = c;
    newnode->next = NULL;

    t->next = newnode;
  }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead) {
   if (*pHead == NULL) return;
    node* t = *pHead;
    node* delete = NULL;
    while (t != NULL) {
      delete = t;
      t = t->next;
      free(delete);
    }
    *pHead = NULL; // Set head to NULL after deleting all nodes
  }

int main(void) {
  int i, strLen, numInputs;
  node* head = NULL;
  char* str;
  char c;
  FILE* inFile = fopen("input.txt", "r");

  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0) {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++) {
      fscanf(inFile, " %c", &c);
      insertChar(&head, c);
    }

    str = toCString(head);
    printf("String is : %s\n", str);

    free(str);
    deleteList(&head);

    if (head != NULL) {
      printf("deleteList is not correct!");
      break;
    }
  }

  fclose(inFile);
}