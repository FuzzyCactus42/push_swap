NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I.

SRCS = push_swap.c \
       read_flags.c \
       str2int.c \
       ft_split.c \
       ft_atoi.c \
       ft_strncmp.c \
       check_dup_error.c \
       stack_utils.c \
       index.c \
       Operations/move.c \
       Operations/push.c \
       Operations/Rotate.c \
       Operations/R_rotate.c \
       Algorithms/simple.c \
       Algorithms/medium.c \
       Algorithms/complex.c \
       get_disorder.c \
       bench.c \
       printf.c \
	   main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
