CC=gcc
CFLAGS= -Wall -Wextra -Werror
OBJS=main.o deque.o ft_atoi.o node.o parsing.o push.o pushswap.o reverseRotate.o rotate.o swap.o hardSort.o ft_split.o ft_substr.o ft_strdup.o ft_strlcpy.o ft_strlen.o ft_calloc.o ft_bzero.o ft_memset.o ft_memcpy.o freeStruct.o send_watch.o outlier.o
OBJS_B=checker.o deque.o ft_atoi.o node.o parsing.o push.o pushswap.o reverseRotate.o rotate.o swap.o ft_split.o ft_substr.o ft_strdup.o ft_strlcpy.o ft_strlen.o ft_calloc.o ft_bzero.o ft_memset.o ft_memcpy.o freeStruct.o ft_strjoin.o get_next_line.o ft_strncmp.o cmd.o check.o hardSort.o
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
