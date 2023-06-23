#include "monty.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>


char **op_toks = NULL;

/**
 * main - the Monty Interp entry point
 * @argc: the number of arguments the programme received
 * @argv: pointer to an array of parameters' char pointers
 * Return: Return (EXIT_SUCCESS) if success,
 * Otherwise (EXIT_FAILURE)
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
