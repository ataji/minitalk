NAME = server client
LIB = minitalk.h
LIBS = minitalk_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CFILES = minitalk_utils.c
OBJ = $(CFILES:.c=.o)

all: $(NAME)
	@echo "\033[0m""███╗░░░███╗██╗███╗░░██╗██╗░░░████████╗░█████╗░██╗░░░░░██╗░░██╗"
	@echo "\033[0m""████╗░████║██║████╗░██║██║░░░╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝"
	@echo "\033[0m""██╔████╔██║██║██╔██╗██║██║░░░░░░██║░░░███████║██║░░░░░█████═╝░"
	@echo "\033[0m""██║╚██╔╝██║██║██║╚████║██║░░░░░░██║░░░██╔══██║██║░░░░░██╔═██╗░"
	@echo "\033[0m""██║░╚═╝░██║██║██║░╚███║██║░░░░░░██║░░░██║░░██║███████╗██║░╚██╗"
	@echo "\033[0m""╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝"

$(NAME) : $(OBJ)

bonus:  $(OBJ) server_bonus client_bonus
	@echo "\033[0m""███╗░░░███╗██╗███╗░░██╗██╗░░░████████╗░█████╗░██╗░░░░░██╗░░██╗░░░████████╗"
	@echo "\033[0m""████╗░████║██║████╗░██║██║░░░╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝░░░██╔═══██║"
	@echo "\033[0m""██╔████╔██║██║██╔██╗██║██║░░░░░░██║░░░███████║██║░░░░░█████═╝░░░░██████══╝"
	@echo "\033[0m""██║╚██╔╝██║██║██║╚████║██║░░░░░░██║░░░██╔══██║██║░░░░░██╔═██╗░░░░██╔═══██╗"
	@echo "\033[0m""██║░╚═╝░██║██║██║░╚███║██║░░░░░░██║░░░██║░░██║███████╗██║░╚██╗░░░████████║"
	@echo "\033[0m""╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝░░░╚═══════╝"

server_bonus: $(LIBS) server_bonus.o
	@$(CC) $(CFLAGS) server_bonus.o $(OBJ) -o $@

client_bonus: $(LIBS) client_bonus.o
	@$(CC) $(CFLAGS) client_bonus.o $(OBJ)  -o $@

server: server.o
	@$(CC) $(CFLAGS) server.o $(OBJ) -o $@

client: client.o 
	@$(CC) $(CFLAGS) client.o $(OBJ)  -o $@

%.o:%.c $(LIB) $(LIBS)
	@$(CC) $(CFLAGS) -c $<

clean:
	@$(RM)  server_bonus.o server.o client_bonus.o client.o minitalk_utils.o

fclean: clean
	@$(RM) client client_bonus server server_bonus

re: fclean all
