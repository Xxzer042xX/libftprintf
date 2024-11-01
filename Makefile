NAME = libftprintf.a
CC = cc
INCLUDE = include
LIBFTDIR = libft
SRCDIR = src
BONUSDIR = srcb
CFLAGS = -Wall -Werror -Wextra -g
AR = ar
ARFLAGS = rcs
RM = rm -f


CFILES = $(SRCDIR)/ft_dispatch_format.c \
		 $(SRCDIR)/ft_parsing.c \
	     $(SRCDIR)/ft_print_char.c \
	     $(SRCDIR)/ft_print_hex.c \
	     $(SRCDIR)/ft_print_int.c \
	     $(SRCDIR)/ft_print_pointer.c \
	     $(SRCDIR)/ft_print_string.c \
	     $(SRCDIR)/ft_print_uint.c \
	     $(SRCDIR)/ft_printf.c \
		 $(SRCDIR)/ft_print_padding.c \
		 $(SRCDIR)/ft_proces_width_and_precision.c \
		 $(SRCDIR)/ft_aplly_zero_padding.c \
		 $(SRCDIR)/ft_set_flags.c \
	 	 $(SRCDIR)/ft_parse_number.c \
		 $(SRCDIR)/ft_print_with_precision.c \
		 $(SRCDIR)/ft_call_padding.c \

BONUSFILES = $(BONUSDIR)/ft_dispatch_format_bonus.c \
			 $(BONUSDIR)/ft_parsing_bonus.c \
	     	 $(BONUSDIR)/ft_print_char_bonus.c \
	     	 $(BONUSDIR)/ft_print_hex_bonus.c \
	     	 $(BONUSDIR)/ft_print_int_bonus.c \
	    	 $(BONUSDIR)/ft_print_pointer_bonus.c \
	    	 $(BONUSDIR)/ft_print_string_bonus.c \
	    	 $(BONUSDIR)/ft_print_uint_bonus.c \
	    	 $(BONUSDIR)/ft_printf_bonus.c \
			 $(BONUSDIR)/ft_print_padding_bonus.c \
			 $(BONUSDIR)/ft_proces_width_and_precision_bonus.c \
			 $(BONUSDIR)/ft_aplly_zero_padding_bonus.c \
			 $(BONUSDIR)/ft_set_flags_bonus.c \
			 $(BONUSDIR)/ft_parse_number_bonus.c \
			 $(BONUSDIR)/ft_print_with_precision_bonus.c \
			 $(BONUSDIR)/ft_call_padding_bonus.c \

OFILES = $(CFILES:.c=.o)
BONUS_OFILES = $(BONUSFILES:.c=.o)

# Progress bars for compilation, cleaning, and full cleaning
define compile_progress
    @echo -n "Compiling: ["
    @i=0; while [ $$i -le 10 ]; do \
        sleep 0.1; \
        echo -n "="; \
        i=`expr $$i + 1`; \
    done; \
    echo "] Done!"
endef

define clean_progress
    @echo -n "Cleaning: ["
    @i=0; while [ $$i -le 10 ]; do \
        sleep 0.1; \
        echo -n "="; \
        i=`expr $$i + 1`; \
    done; \
    echo "] Done!"
endef

define fclean_progress
    @echo -n "Full cleaning: ["
    @i=0; while [ $$i -le 10 ]; do \
        sleep 0.1; \
        echo -n "="; \
        i=`expr $$i + 1`; \
    done; \
    echo "] Done!"
endef

all: $(NAME)

$(NAME): $(OFILES)
	@$(MAKE) --no-print-directory -C $(LIBFTDIR) bonus
	@cp $(LIBFTDIR)/libft.a $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OFILES)
	$(call compile_progress)

bonus: $(BONUS_OFILES)
	@$(MAKE) --no-print-directory -C $(LIBFTDIR) bonus
	@cp $(LIBFTDIR)/libft.a $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(BONUS_OFILES)
	$(call compile_progress)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFTDIR) -c $< -o $@
	$(call compile_progress)

clean:
	@$(RM) $(OFILES) $(BONUS_OFILES)
	@$(MAKE) --no-print-directory -C $(LIBFTDIR) clean
	$(call clean_progress)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFTDIR) fclean
	$(call fclean_progress)

re: fclean all

.PHONY: all clean fclean re bonus
