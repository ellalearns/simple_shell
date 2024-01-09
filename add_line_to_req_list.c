#include "myshell.h"

/**
 * add_string_to_list - function to add a string to a list of strings
 * @head: the linked list to use
 * @str: the string to add
 * Return: returns list with added node
*/
str_reqList *myntstrtok(str_reqList **head, char *str)
{
str_reqList *newLineNode;
str_reqList *tempList = *head;

newLineNode = malloc(sizeof(str_reqList));
if (newLineNode == NULL)
{
return (NULL);
}

newLineNode->line = mystrcopy(str);
newLineNode->next = NULL;

if (*head == NULL)
{
*head = newLineNode;
return (newLineNode);
}

while (tempList->next)
{
tempList = tempList->next;
}

tempList->next = newLineNode;

return (*head);
}
