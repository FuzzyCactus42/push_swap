#include "push_sawp.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	int	i;
	int num;

	i = 1;
	if (argc <= 1)
		return(0);
	printf("%i", ft_atoi(argv[i], &num));
}