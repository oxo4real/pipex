CC := cc
SRCS := find_path.c ft_putchar_fd.c ft_putstr_fd.c ft_strcmp.c ft_strjoin.c \
		ft_strnstr.c ft_strncmp.c get_command_path.c list_manipulation.c ft_split.c \
		make_list.c other_utils_bonus.c gnl_utils_bonus.c parser.c parser_tools.c normal_pipe.c
SRCSB := here_doc_bonus.c main_bonus.c fill_file_bonus.c gnl_bonus.c execute__bonus.c
BUILD_DIR := build/
OBJS := ${addprefix $(BUILD_DIR),$(SRCS:.c=.o)}
OBJSB := ${addprefix $(BUILD_DIR),$(SRCSB:.c=.o)}
CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address
.BONUS := $(BUILD_DIR).bonus
NAME := pipex

all: $(BUILD_DIR) $(NAME)

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)
 
$(NAME): $(OBJS) $(BUILD_DIR)main.o
	$(if $(wildcard $(.BONUS)),@rm -f $(.BONUS) $(OBJSB))
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)%.o: %.c pipex_bonus.h
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: $(BUILD_DIR) $(.BONUS)

$(.BONUS): $(OBJS) $(OBJSB) 
	$(if $(wildcard $(.BONUS)),,@rm -f $(BUILD_DIR)main.o)
	$(CC) $(CFLAGS) -o $(NAME) $^
	@touch $(.BONUS)

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY : all clean fclean re bonus re_bonus
