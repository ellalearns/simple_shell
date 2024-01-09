#ifndef shell_header_file
#define shell_header_file

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>

    /**
     * struct my_strtok_list_node - singly linked list
     * @str: a string
     * @str_len: length of the string
     * @next: pointer to the next node
     *
     * Description: singly linked list structure containing words that make up a multi-worded string
    */
    typedef struct my_strtok_list_node
    {
        char *str;
        int str_len;
        struct my_strtok_list_node *next;
    } str_list;

    /**
     * struct my_strtok_request_list_node - singly linked list
     * @lineRequest: a string
     * @next: pointer to the next node
     *
     * Description: singly linked list structure containing words that make up a multi-worded string
    */
    typedef struct my_strtok_request_list_node
    {
        char *line;
        struct my_strtok_request_list_node *next;
    } str_reqList;

    void _shellprint();

    char *mystrcopy(const char *str);

    str_list *add_string_to_list(str_list **head, const char *str);
    size_t print_str_list(str_list *head);
    void free_str_list(str_list *head);

    str_list *mystrtok(const char *str);
    char *my_getline();
    str_reqList *myntstrtok(str_reqList **head, char *str);

    size_t list_to_argv(str_list *head, char *argv[]);

    char *removeStartSpaces(char *str);
    char *removeEndSpaces(char *str);

#endif
