NAME = libft.a

LIST =  ft_itoa.c       ft_putstr_fd.c  ft_strmapi.c \
		ft_atoi.c       ft_memchr.c     ft_split.c      ft_strncmp.c\
		ft_bzero.c      ft_memcmp.c     ft_strchr.c     ft_strnstr.c\
		ft_calloc.c     ft_memcpy.c     ft_strdup.c     ft_strrchr.c\
		ft_isalnum.c    ft_memmove.c    ft_striteri.c   ft_strtrim.c\
		ft_isalpha.c    ft_memset.c     ft_strjoin.c    ft_substr.c\
		ft_isascii.c    ft_putchar_fd.c ft_strlcat.c    ft_tolower.c\
		ft_isdigit.c    ft_putendl_fd.c ft_strlcpy.c    ft_toupper.c\
		ft_isprint.c    ft_putnbr_fd.c  ft_strlen.c

BONUS = ft_lstnew.c  ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

INC = libft.h

OBJCS = $(patsubst %.c,%.o , $(LIST))
BONUS_OBJCS = $(patsubst %.c,%.o , $(BONUS))

FLAGS = -Wall -Wextra -Werror



all: $(NAME)

$(NAME): $(OBJCS)
	ar rcs $(NAME) $?

#DEPENDENCIES
# $<  - puts first .c file
# $@  - puts file with the same name but .o extension
 
%.o : %.c $(INC)
	gcc $(FLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJCS)
	@rm -f $(BONUS_OBJCS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJCS)
	ar rcs $(NAME) $?

.PHONY : all clean fclean re bonus
