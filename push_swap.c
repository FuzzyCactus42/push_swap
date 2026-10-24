#include "push_swap.h"
#include <stdio.h>
void print_erorr()
{
	write(1, "Erorr\n", 6);
}
int main(int argc, char *argv[])
{
	int	i;
	int *integrs;
	int flags;
	int	bench;

	if (argc <= 1)
		return(0);
	if (check_flags_error(argv, argc, &flags, &bench) == -1)
		{
			print_erorr();
			printf("nah\n");
			return (0);
		}
	i = flags + bench + 1;
	if (str2int(argv, argc, &integrs, i) == -1)
		{
			print_erorr();
			return (0);
		}
	printf("%i", integrs[1]);
}