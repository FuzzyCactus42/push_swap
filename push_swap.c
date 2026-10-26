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
	int *int_arr;
	t_stack	a;
	t_stack	b;
	t_flags flags;

	int_arr = NULL;// if str2int fail -> free(uninitalize) = ERORR
	if (argc <= 1)
		return(0);
	if (read_flags(argv, argc, &flags) == -1)
		{
			print_erorr();
			return (-1);
		}
	i = flags.num_bench + flags.num_flags + 1;
	int_elements = str2int(argv, argc, &int_arr, i);
	if (int_elements == -1 || check_dup_erorr(int_arr, int_elements) == -1)
		{
			print_erorr();
			free(int_arr);
			return (-1);
		}
	init_stack(&a);
	init_stack(&b);
	if (fill_stack(&a, int_arr, int_elements) == -1)
	{
		print_erorr();
		free_stack(&a);
		return (-1);
	}
	free_stack(&a);
	free_stack(&b);
	radix_sort(&a, &b);
}