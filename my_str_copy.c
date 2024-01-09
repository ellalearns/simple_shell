#include "myshell.h"

/**
 * mystrcopy - function to copy a string into another one
 * @str: the original string
 * Return: copied string
*/
char *mystrcopy(const char *str)
{
char *newStr;
int len = 0;

while (str[len])
{
len++;
}

newStr = malloc(sizeof(char) * (len));

len = 0;

while (str[len])
{
newStr[len] = str[len];
len++;
}

return (newStr);
}
