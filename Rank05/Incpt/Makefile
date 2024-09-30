all: build run

data:
	@if [ ! -d "home/isporras/data/mariadb" ] && [ ! -d "home/isporras/data/wordpress;" ]; then \
	mkdir -p home/isporras/data/mariadb && mkdir -p home/isporras/data/wordpress; fi

build: data
	docker compose -f srcs/docker-compose.yml build

run:
	docker compose -f srcs/docker-compose.yml up -d

# It starts nginx from the docker compose file (make exec nginx)
exec:
	$(eval service=$(filter-out $@,$(MAKECMDGOALS)))
	docker compose -f srcs/docker-compose.yml exec $(service) bash

status:
	$(eval service=$(filter-out $@,$(MAKECMDGOALS)))
	docker compose -f srcs/docker-compose.yml logs $(service)

stop:
	docker compose -f srcs/docker-compose.yml down

vclean:
	docker compose -f srcs/docker-compose.yml down --rmi all -v
	@rm -rf home

fclean: vclean
	docker system prune -af

dls:
	docker ps -a

vls:
	docker volume ls

ils:
	docker image ls

nls:
	docker networks ls

.SILENT:
