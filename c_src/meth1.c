#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* myptr1;
char* myptr2;
char* yesno;

//allocating necessary memories
char* mymalloc(char* str1) {
  char* str = malloc(sizeof(char) * 512);
  if(str != NULL) {
    return str;
  } else
  printf("Failed to allocate memories.\n");
}

//questions and an answer
int question() {

  myptr1 = mymalloc(myptr1);
  myptr2 = mymalloc(myptr2);
  yesno = mymalloc(yesno);

  printf("Enter any word you like: ");
  gets(myptr1);
  printf("You've entered: %s, and then enter the same word: ", myptr1);
  gets(myptr2);
  printf("You've entered %s and %s.\n", myptr1, myptr2);
  printf("Are you sure? No correction? (y/n): ");
  gets(yesno);

  yesno = strcmp(yesno, "y");
  return yesno;
  //if yes, it's supposed to be 0.
}

//comparing the two entered strings
int comparison(char* string1, char* string2) {
  int comp;
  comp = strcmp(string1, string2);
  if(comp == 0) {
    printf("You've entered EXACTLY the same. You're a good typist.\n");
    return 0;
  } else
  printf("Dang, you've entered somehow different! You screwed it up.\n");
  return 0;
}

int main() {
  int result1;

  result1 = question();
  while(result1 != 0) {
    printf("Got it. Try again.\n");
    result1 = question();
    if(result1 == 0) {
      break;
    }
  }
  comparison(myptr1, myptr2);

  //clearing the used memories
  free(myptr1);
  free(myptr2);
  free(yesno);

  return 0;
}
