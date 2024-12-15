CC := cc
SRCS := find_path.c ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_strcmp.c ft_strjoin.c ft_strncmp.c \
		ft_strnstr.c get_command_path.c list_manipulation.c make_list.c other_utils_bonus.c gnl_utils_bonus.c
SRCSB := here_doc_bonus.c main_bonus.c fill_file_bonus.c gnl_bonus.c
BUILD_DIR := build
OBJS := ${addprefix $(BUILD_DIR)/,$(SRCS:.c=.o)}
OBJSB := ${addprefix $(BUILD_DIR)/,$(SRCSB:.c=.o)}
CFLAGS := -Wall -Wextra -Werror
.BONUS := $(BUILD_DIR)/.bonus
NAME := pipex

all: $(BUILD_DIR)/ $(NAME)

$(BUILD_DIR)/:
	@mkdir $(BUILD_DIR)/
 
$(NAME): maybe_clean_name $(OBJS) $(BUILD_DIR)/main.o
	$(if $(strip $(filter-out maybe_clean_name, $?)), \
		$(CC) $(CFLAGS) -o $@ $(filter-out maybe_clean_name, $^), \
		@echo "make: Nothing to be done for \`all'.")

$(BUILD_DIR)/%.o: %.c pipex_bonus.h
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: $(BUILD_DIR)/ $(.BONUS)

$(.BONUS): maybe_clean_bonus $(OBJS) $(OBJSB) 
	$(if $(strip $(filter-out maybe_clean_bonus, $?)), \
		$(CC) $(CFLAGS) -o $(NAME) $(filter-out maybe_clean_bonus, $^); touch $(.BONUS), \
		@echo "make: Nothing to be done for \`bonus'.")

maybe_clean_name:
	$(if $(wildcard $(.BONUS)),@rm -f $(.BONUS) $(OBJSB))

maybe_clean_bonus:
	$(if $(wildcard $(.BONUS)),,@rm -f $(BUILD_DIR)/main.o)

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

.PHONY : all clean fclean re bonus maybe_clean_bonus maybe_clean_name
