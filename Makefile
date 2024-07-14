CC = cc
FLAGS =

SERVER = server
CLINET = client

PRINTF_DIR = ft_printf/

all:
	@make -C $(PRINTF_DIR)
	$(CC) server.c $(FLAGS) $(PRINTF_DIR)/libftprintf.a -o $(SERVER)
	$(CC) client.c $(FLAGS) $(PRINTF_DIR)/libftprintf.a -o $(CLINET)
	@echo "Client and Server compiled successfully!"

clean:
	@make -C $(PRINTF_DIR) clean

fclean:
	@make -C $(PRINTF_DIR) fclean
	rm -f $(SERVER) $(CLINET)
	@echo "Client and Server deleted!"

re:	clean fclean

