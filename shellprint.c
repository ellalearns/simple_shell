#include "myshell.h"

/**
 * _shellprint - function to print shell $ to the terminal
*/
void _shellprint()
{
write(STDOUT_FILENO, "shell $ ", 8);
}
