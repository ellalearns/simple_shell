#include "myshell.h"

/**
 * list_to_argv - function to print str_list type list
 * @head: the list to be printed
 * @argv: argv list to add strings to
 * Return: a size_t object
*/
size_t list_to_argv(str_list *head, char *argv[])
{
size_t lencounter = 0;
int position = 0;

while (head)
{
if (head->str)
{
argv[position] = head->str;
head = head->next;
lencounter++;
position++;
}
else
{
perror("error");
}
}

return (lencounter);
}

