SERVER = server
CLIENT = client
SERVER_BONUS = $(SERVER)
CLIENT_BONUS = $(CLIENT)

UTILS = utils/atoi.c utils/itoa.c utils/utils.c
UTILS_BONUS = bonus/utils/atoi_bonus.c bonus/utils/itoa_bonus.c bonus/utils/utils_bonus.c
HEADER = minitalk.h
HEADER_BONUS = bonus/minitalk_bonus.h

FLAGS = -Wall -Wextra -Werror

SRCS_S = 	server.c $(UTILS)
SRCS_C = 	client.c $(UTILS)

SRCS_S_BONUS = 	bonus/server_bonus.c $(UTILS)
SRCS_C_BONUS = 	bonus/client_bonus.c $(UTILS)

OBJ_S = $(@SRCS_S:.c=.o)
OBJ_C = $(@SRCS_B:.c=.o)

OBJ_S_BONUS = $(@SRCS_S_BONUS:.c=.o)
OBJ_C_BONUS = $(@SRCS_C_BONUS:.c=.o)

CC	=	gcc

all : $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_C)
	@echo "[client compilation...]"
	@$(CC) $(SRCS_C) -I $(HEADER) $(FLAGS) -o $(CLIENT)
	@echo "[Done!]"

$(SERVER): $(OBJ_S)
	@echo "[server compilation...]"
	@$(CC) $(SRCS_S) -I $(HEADER) $(FLAGS) -o $(SERVER)
	@echo "[Done!]"

bonus: fclean
	@echo "[client (bonus) compilation...]"
	@$(CC) $(SRCS_C_BONUS) -I $(HEADER) $(FLAGS) -o $(CLIENT)
	@echo "[Done!]"
	@echo "[server (bonus) compilation...]"
	@$(CC) $(SRCS_S_BONUS) -I $(HEADER) $(FLAGS) -o $(SERVER)
	@echo "[Done!]"

clean:
	@rm -rf $(OBJ_S) $(OBJ_C) $(OBJ_S_BONUS) $(OBJ_C_BONUS)

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)

re : fclean all
