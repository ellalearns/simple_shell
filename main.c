#include "myshell.h"

/**
 * main - the main shell function
 * @ac: first argument, built in
 * @av: second argument, also built in
 * Return: a default return
*/
int main(void)
{
    extern char **environ;

    pid_t childPid;

    int status;

    char *argv[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    if (isatty(0))
    {

        int counter;
        counter = 0;

        while (counter < 1)
        {
            int empty = 0;

            char *string = NULL;

            str_list **newRequestList = NULL;

            newRequestList = malloc(sizeof(str_list) * 1024);

            string = malloc(sizeof(char) * 1024);

            _shellprint();

            string = my_getline();
            string = removeStartSpaces(string);

            if (string)
            {
                if (string[0] == '\n')
                {
                    empty = 1;
                }
                else
                {
                    *newRequestList = mystrtok(string);
                    list_to_argv(*newRequestList, argv);
                }
            }

            childPid = fork();

            if (childPid == -1)
            {
                perror("Error");
            }

            if (childPid == 0)
            {
                if (empty == 0)
                {
                    if (execve(argv[0], argv, environ) == -1)
                    {
                        perror("Error");
                    }
                }
            }
            else
            {
                wait(&status);
            }
        }

    }

    else

    {
        ssize_t input;
        size_t inputSize = 1024;
        char *line = NULL;
        str_reqList **newList = NULL;
        int lineCount = 0;
        int emptyline = 0;

        newList = malloc(sizeof(str_reqList) * 1024);
        line = malloc(sizeof(char) * 1024);

        while ((input = getline(&line, &inputSize, stdin)) != EOF)
        {
            if ((removeStartSpaces(line))[0] == '\n')
            {
                emptyline = 1;
            }
            else
            {
            myntstrtok(newList, line);
            lineCount++;
            }
        }

        if (emptyline == 0)
        {
            while ((*newList)->line != NULL)
            {
                int empty = 0;
                char *string = NULL;

                str_list **newRequestList = NULL;

                newRequestList = malloc(sizeof(str_list) * 1024);

                string = malloc(sizeof(char) * 1024);

                string = (*newList)->line;
                string = removeStartSpaces(string);


                if (string)
                {
                    if (string[0] == '\n' || string[0] == '\0' || string[0] == EOF)
                    {
                        empty = 1;
                    }
                    else
                    {
                    *newRequestList = mystrtok(string);
                    list_to_argv(*newRequestList, argv);
                    }
                }

                childPid = fork();

                if (childPid == -1)
                {
                    perror("Error");
                }

                if (childPid == 0)
                {
                    if (empty == 0)
                    {

                    if (execve(argv[0], argv, environ) == -1)
                    {
                        perror("Error");
                    }

                    }
                }
                else
                {
                    wait(&status);

                    if ((*newList)->next != NULL)
                    {
                        (*newList) = (*newList)->next;
                    }

                    else

                    {
                        (*newList)->line = NULL;
                    }
                }
            }
        }
    }

    return (0);

}
