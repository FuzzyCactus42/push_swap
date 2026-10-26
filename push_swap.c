#include "push_swap.h"
#include <stdio.h>

void print_erorr()
{
	write(2, "Error\n", 6);
}

int main(int argc, char *argv[])
{
	int	i;
	int	int_elements;
	int *integrs;
	t_flags flags;

	if (argc <= 1)
		return(0);
	if (read_flags(argv, argc, &flags) == -1)
		{
			print_erorr();
			return (0);
		}
	i = flags.num_bench + flags.num_flags + 1;
	int_elements = str2int(argv, argc, &integrs, i);
	if (int_elements == -1 || check_dup_erorr(integrs, int_elements) == -1)
		{
			print_erorr();
			free(integrs);
			return (0);
		}
	printf("%i\n", integrs[0]);
	printf("%s", flags.flag);
	free(integrs);
}