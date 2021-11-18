SRCFILES = ft_printf.c ft_types.c

OBJFILES = $(SRCFILES:.c=.o)

NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Werror -Wextra

LIBPATH = ./libft

AR = ar
ARFLAGS = rsc

RM = rm -f

.c.o: 
	$(CC) $(CFLAGS) -c $^

$(NAME): $(OBJFILES)
	make -C libft/
	cp $(LIBPATH)/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)


all: $(NAME)

out: $(SRCFILES) main.c
	make -C libft/
	$(CC) $(CFLAGS) $^ -L $(LIBPATH) -l ft

re: fclean all

clean:
	$(RM) $(OBJFILES)
	$(RM) $(OBJFILES_BONUS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all re clean fclean out
