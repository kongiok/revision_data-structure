#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char currentString[] = "my day is sunny day", *bookString = "this is a book",
       copiedString1[30], copiedString2[40];
  strcpy(copiedString1, currentString);
  strcpy(copiedString2, bookString);
  printf("%s|%s|%s|%s\n", currentString, bookString, copiedString1,
         copiedString2);
  printf("%lu %lu\n", strlen(currentString), strlen(bookString));

  char greetingArray[] = {'h', 'e', 'l', 'l', 'o', '\0'},
       greetingString[] = "hello";
  printf("%s| %s| %lu| %lu\n", greetingArray, greetingString,
         strlen(greetingArray), strlen(greetingString));

  int startNum, size, startAddress, locationNum, address;
  while (1) {
    printf("請輸入起始編號-->");
    scanf("%d", &startNum);
    if (startNum == 0)
      break;

    printf("請輸入每個項目的大小-->");
    scanf("%d", &size);

    printf("請輸入起始記憶體地址（十六進位）-->");
    scanf("%x", &startAddress);

    printf("請輸入目標項目的編號-->");
    scanf("%d", &locationNum);

    address = startAddress + (locationNum - startNum) * size;
    printf("編號 %d 的項目地址為：0x%X\n", locationNum, address);
  }
  return 0;
}
