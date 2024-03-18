CC = cc
RM = rm -rf

srcs = utils/ft_split.c utils/stack_a_ins.c utils/stack_b_ins.c utils/stack_op.c \
	utils/stack_op2.c utils/stack_op3.c utils/string_ops.c utils/big_sort.c \
	utils/little_sort.c push_swap.c
bonus_srcs = checker_utils/ft_split.c checker_utils/get_next_line_utils.c \
	checker_utils/stack_b_ins.c checker_utils/stack_op2.c checker_utils/string_ops.c \
	checker_utils/get_next_line.c checker_utils/stack_a_ins.c checker_utils/stack_op.c \
	checker_utils/stack_op3.c checker.c

objs = ${srcs:.c=.o}
bonus_objs = ${bonus_srcs:.c=.o}
header = push_swap.h
header_bns = push_swap_bonus.h

CFLAGS = -Wall -Wextra -Werror -g
name = push_swap
checker = checker

all: $(name)
bonus: $(checker)

utils/%.o: utils/%.c ${header}
	${CC} ${CFLAGS} -c $< -o $@

checker_utils/%.o: checker_utils/%.c ${header}
	${CC} ${CFLAGS} -c $< -o $@

$(checker): $(bonus_objs) $(header_bns)
	$(CC) $(CFLAGS) $(bonus_objs) -o $(checker)

$(name): $(objs) $(header)
	$(CC) $(CFLAGS) $(objs) -o $(name)

clean:
	$(RM) $(objs) $(bonus_objs)

fclean: clean
	$(RM) $(name) $(checker)

re: clean $(name)