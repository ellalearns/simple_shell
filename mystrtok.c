#include "myshell.h"
/**
 * mystrtok - my strtok function
 * @str: a string argument
 * Return: returns a list of strings split from the original string
*/
str_list *mystrtok(const char *str)
{
str_list **newStringList;
char *tempString;
int firstCounter = 0;
int secondCounter = 0;
int perStrCounter = 0;

newStringList = malloc(sizeof(str_list) * 1024);
if (newStringList == NULL)
{
perror("Error");
}

while (str[firstCounter])
{
if (str[firstCounter] == ' ' || str[firstCounter] == '\0' || str[firstCounter] == '\n')
{
tempString = malloc(sizeof(char) * firstCounter + 1);
while (secondCounter > 0)
{
tempString[perStrCounter] = str[firstCounter - secondCounter];
perStrCounter++;
secondCounter--;
}
tempString[perStrCounter] = '\0';
perStrCounter = 0;
secondCounter = 0;

add_string_to_list(newStringList, tempString);
free(tempString);

firstCounter++;
}
else
{
firstCounter++;
secondCounter++;
}
}
return (*newStringList);
}
