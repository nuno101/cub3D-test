#include <unistd.h>
#include <stdio.h>  // used for printf
#include <stdlib.h> // used for malloc
#include <stdbool.h> // bool type support also included by MLX
#include "libft.h"

int	valid_colours(char *s);

int	main(void)
{
	int b;
	char *colour = "blue";

	printf("Testing valid_colours()\n");
	b = valid_colours(colour);
	printf("Colour %s is %s\n", colour, b == 3 ? "valid" : "not valid");
	colour = "F 1";
	b = valid_colours(colour);
	printf("Colour %s is %s\n", colour, b == 3 ? "valid" : "not valid");
	colour = "F 1,2,3";
	b = valid_colours(colour);
	printf("Colour %s is %s\n", colour, b == 3 ? "valid" : "not valid");
	colour = "F 01,2,3";
	b = valid_colours(colour);
	printf("Colour %s is %s\n", colour, b == 3 ? "valid" : "not valid");
	colour = "C 120,100,50";
	b = valid_colours(colour);
	printf("Colour %s is %s\n", colour, b == 3 ? "valid" : "not valid");
	colour = "C 0,0,0";
	b = valid_colours(colour);
	printf("Colour %s is %s\n", colour, b == 3 ? "valid" : "not valid");
	colour = "C 0,-1,0";
	b = valid_colours(colour);
	printf("Colour %s is %s\n", colour, b == 3 ? "valid" : "not valid");
	colour = "C 255,255,255";
	b = valid_colours(colour);
	printf("Colour %s is %s\n", colour, b == 3 ? "valid" : "not valid");
	colour = "C 256,255,255";
	b = valid_colours(colour);
	printf("Colour %s is %s\n", colour, b == 3 ? "valid" : "not valid");
	return (0);
}
