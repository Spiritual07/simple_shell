#include "shell.h"

void c_print(const char *str)
{
	write(STDOUT_FILEOUT, &str, strlen(str));
}
