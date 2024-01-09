#include "myshell.h"

/**
 * free_str_list - free str_list type
 * @head: the str_list list to be freed
*/
void free_str_list(str_list *head)
{
str_list *tempListNode;

while (head)
{
tempListNode = head->next;
free(head->str);
free(head);
head = tempListNode;
}
}
