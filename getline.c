#include "myshell.h"

/**
 * my_getline - my getline function
 * no arguments
 * Return: input string
*/
char *my_getline()
{
char *tempString = NULL;
ssize_t inputString;
size_t inputSize = 1024;

tempString = malloc(sizeof(char) * inputSize);

inputString = getline(&tempString, &inputSize, stdin);

if (inputString)
{
return (tempString);
}
else
{
return ("error");
}
}
