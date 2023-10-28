#include "main.h"

/**
 * main - simple shell implementation.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 0 is successful.
*/

int main(int argc, char **argv)
{
	 if (argc == 2) {
        run_non_interactive_mode(argv[1]);
    } else {
        run_interactive_mode();
    }
    return 0;
}
