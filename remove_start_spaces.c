#include "myshell.h"
/**
 * removeStartSpaces - remove spaces at the beginning of a string
 * @str: the string to remove start spaces from
 * Return: a string without start spaces
*/
char *removeStartSpaces(char *str)
{
int strLen = 0;
int newStrLen = 0;
int strLen2 = 0;
int strLen3, strLen4, strLen5, strLen6;
char *newStr = NULL;
char *newStr2 = NULL;
while (str[strLen])
strLen++;
newStr = malloc(sizeof(char) * 1000);
newStr2 = malloc(sizeof(char) * 1024);
strLen = 0;
while (str[strLen] == ' ')
strLen++;
while (str[strLen])
{
newStr[newStrLen] = str[strLen];
newStrLen++;
strLen++;
}
strLen5 = 0;
while (newStr[strLen5] != '\n' && newStr[strLen5] != '\0' && newStr[strLen5] != EOF)
{
strLen5++;
}
strLen6 = strLen5;
while (newStr[strLen5 - 1] == ' ')
{
strLen5--;
strLen2++;
}
strLen3 = strLen6 - strLen2;
strLen4 = 0;
while (strLen4 < strLen3)
{
newStr2[strLen4] = newStr[strLen4];
strLen4++;
}
newStr2[strLen4] = '\n';
return (newStr2);
}
