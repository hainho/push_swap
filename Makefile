CC=gcc
CFLAGS= -Wall -Wextra -Werror
OBJS=main.o deque.o ft_atoi.o node.o parsing.o push.o pushswap.o redix.o reverseRotate.o rotate.o swap.o
TARGET=push_swap

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f *.o

fclean:
	rm -f *.o push_swap

all:
	make push_swap

re:
	make fclean
	make push_swap