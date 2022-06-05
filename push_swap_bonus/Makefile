CC=gcc
CFLAGS= -Wall -Wextra -Werror
OBJS=main.o deque.o ft_atoi.o node.o parsing.o push.o pushswap.o redix.o reverseRotate.o rotate.o swap.o hardSort.o ft_split.o ft_substr.o ft_strdup.o ft_strlcpy.o ft_strlen.o ft_calloc.o ft_bzero.o ft_memset.o ft_memcpy.o freeStruct.o quick.o send_watch.o ft_strjoin.o get_next_line.o ft_strncmp.o cmd.o check.o
TARGET=checker

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f *.o

fclean:
	rm -f *.o checker

all:
	make checker

re:
	make fclean
	make checker