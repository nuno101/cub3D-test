#include <unistd.h>
#include <stdio.h>  // used for printf
#include <stdlib.h> // used for malloc
#include <stdbool.h> // bool type support also included by MLX
#include "libft.h"

bool valid_colour(char *s);

int	main(void)
{
	int b;
	char *colour = "blue";

	printf("Testing valid_colour()\n");
	b = valid_colour(colour);
	printf("Colour %s is %s\n", colour, b == 1 ? "valid" : "not valid");
	colour = "1";
	b = valid_colour(colour);
	printf("Colour %s is %s\n", colour, b == 1 ? "valid" : "not valid");
	colour = "1,2,3";
	b = valid_colour(colour);
	printf("Colour %s is %s\n", colour, b == 1 ? "valid" : "not valid");
	colour = "120,100,50";
	b = valid_colour(colour);
	printf("Colour %s is %s\n", colour, b == 1 ? "valid" : "not valid");
	return (0);
}
