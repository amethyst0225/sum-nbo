CC = cc
SRCS = sum-nbo.c \
	utils.c

OBJS = $(SRCS:.c=.o)
TARGET = sum-nbo

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
