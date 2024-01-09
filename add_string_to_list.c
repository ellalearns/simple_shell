#include "myshell.h"

/**
 * add_string_to_list - function to add a string to a list of strings
 * @head: the linked list to use
 * @str: the string to add
 * Return: list with added string
*/
str_list *add_string_to_list(str_list **head, const char *str)
{
str_list *newStrNode;
unsigned int len;
str_list *tempList = *head;

newStrNode = malloc(sizeof(str_list));
if (newStrNode == NULL)
{
return (NULL);
}

len = 0;
while (str[len])
{
len++;
}

newStrNode->str_len = len;
newStrNode->str = mystrcopy(str);
newStrNode->next = NULL;

if (*head == NULL)
{
*head = newStrNode;
return (newStrNode);
}

while (tempList->next)
{
tempList = tempList->next;
}

tempList->next = newStrNode;

return (*head);
}
