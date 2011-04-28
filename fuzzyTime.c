#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char* argv[]) {
  if (argc != 2) { 
    printf("Invalid usage\n", argc);
    return -1;
  }

  int hour = atoi(strtok(argv[1], ":"));
  int minute = atoi(strtok(NULL, ":"));

  if (hour < 1 || hour > 12 || minute < 0 || minute > 59) {
    printf("Invalid time.\n");
    return -1;
  }


  const char ones[10][6] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
  const char teens[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
  const char tens[6][7] = {"", "", "twenty", "thirty", "forty", "fifty"}; 

  char* fuztime = malloc(40);
 
  sprintf(fuztime, "%s ", (hour < 10 ? ones[hour] : teens[hour%10])); 

  if (minute == 0) {
    strcat(fuztime, "o-clock");
  }
  else if (minute < 10) {
    strcat(fuztime, "oh-");
    strcat(fuztime, ones[minute]);
  }
  else if (minute < 20) {
    strcat(fuztime, teens[minute%10]);
  }
  else {
    strcat(fuztime, tens[minute/10]);
    if (minute % 10 != 0) {
      strcat(fuztime, "-");
      strcat(fuztime, ones[minute%10]); 
    }
  }
	

  printf("%s\n", fuztime);

  return 0;
}


