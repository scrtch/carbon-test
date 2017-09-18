#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "func.h"

int main(int argc, char *argv[])
{
	int x, y;
	if (argc < 3)
		goto usage;

	x = strtol(argv[1], NULL, 10);
	y = strtol(argv[2], NULL, 10);

	if(x == 0 || y == 0 || errno != 0)
		goto usage;

	printf("%i\n", func(x, y));
	return 0;

usage:
	printf("usage: "APP" x y\n"
			"where x != 0, y != 0\n"
			"--help - show this message\n"
		);
	return EINVAL;
}
