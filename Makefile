SRCFILES = ft_printf.c ft_types.c
SRCFILES_BONUS = ft_printf_bonus.c ft_types_bonus.c ft_flags_bonus.c

OBJFILES = $(SRCFILES:.c=.o)
OBJFILES_BONUS = $(SRCFILES_BONUS:bonus.c=bonus.o)

NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Werror -Wextra

LIBPATH = ./libft

AR = ar
ARFLAGS = rsc

RM = rm -f

.c.o: 
	$(CC) $(CFLAGS) -c $^

bonus.cbonus.o:
	$(CC) $(CFLAGS) -c *bonus.c

$(NAME): $(OBJFILES)
	make -C libft/
	cp $(LIBPATH)/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)


all: $(NAME)

bonus: $(OBJFILES_BONUS)
	make -C libft/
	cp $(LIBPATH)/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES_BONUS)

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
