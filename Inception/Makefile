COMPOSE_FILE	= srcs/docker-compose.yml
DATA_DIR		= /home/alehenri/data

.PHONY: all clean fclean re down logs

all:
	@mkdir -p $(DATA_DIR)/mysql
	@mkdir -p $(DATA_DIR)/wordpress
	@docker compose -f $(COMPOSE_FILE) up -d --build

down:
	@docker compose -f $(COMPOSE_FILE) down

clean: down
	@docker compose -f $(COMPOSE_FILE) down -v
	@sudo rm -rf $(DATA_DIR)/mysql
	@sudo rm -rf $(DATA_DIR)/wordpress

fclean: clean
	@docker system prune -af

re: fclean all

logs:
	@docker compose -f $(COMPOSE_FILE) logs -f
