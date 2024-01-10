#include "myshell.h"

/**
 * free_req_list - free str_list type
 * @head: the str_list list to be freed
*/
void free_req_list(str_reqList *head)
{
str_reqList *tempListNode;

while (head)
{
tempListNode = head->next;
free(head->line);
free(head);
head = tempListNode;
}
}
