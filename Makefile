CC=gcc
CFLAGS= -Wall -Wextra -Werror
OBJS=quick_main.o deque.o ft_atoi.o node.o parsing.o push.o pushswap.o reverseRotate.o rotate.o swap.o hardSort.o ft_split.o ft_substr.o ft_strdup.o ft_strlcpy.o ft_strlen.o ft_calloc.o ft_bzero.o ft_memset.o ft_memcpy.o freeStruct.o quick.o shift.o pssort.o
OBJS_B=checker_bonus.o deque_bonus.o ft_atoi_bonus.o node_bonus.o parsing_bonus.o push_bonus.o pushswap_bonus.o reverseRotate_bonus.o rotate_bonus.o swap_bonus.o ft_split_bonus.o ft_substr_bonus.o ft_strdup_bonus.o ft_strlcpy_bonus.o ft_strlen_bonus.o ft_calloc_bonus.o ft_bzero_bonus.o ft_memset_bonus.o ft_memcpy_bonus.o freeStruct_bonus.o ft_strjoin_bonus.o get_next_line_bonus.o ft_strncmp_bonus.o cmd_bonus.o check_bonus.o hardSort_bonus.o
TARGET=push_swap
TARGET_B=checker

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

bonus: $(TARGET_B)

$(TARGET_B): $(OBJS_B)
	$(CC) $(CFLAGS) -o $(TARGET_B) $(OBJS_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(TARGET) $(TARGET_B)

all: $(TARGET) bonus

re: fclean all
