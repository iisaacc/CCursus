
.PHONY: all build up down clean save_images

all: build

#Execute docker compose build, that is building the images Docker for the services defined in docker-compose.yml
build:
	@echo "Building Docker images..."
	@docker compose -f srcs/docker-compose.yml up --build --remove-orphans || (echo "Build failed with exit code $$?"; exit 1)

#It runs the containers in the background (-d)
up:
	docker compose -f srcs/docker-compose.yml up -d

#It stops and deletes all the containers, nets, and volumes created by docker-compose up
down:
	docker compose -f srcs/docker-compose.yml down

clean: down
	docker ps -a -q --filter ancestor=inception-nginx | xargs -r docker rm -f
	docker rmi -f inception-nginx
	docker ps -a -q --filter ancestor=inception-mariadb | xargs -r docker rm -f
	docker rmi -f inception-mariadb