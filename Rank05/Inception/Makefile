.PHONY: all build up down

all: build up

#Execute docker compose build, that is building the images Docker for the services defined in docker-compose.yml
build:
	docker-compose build

#It runs the containers in the background (-d)
up:
	docker-compose up -d

#It stops and deletes all the containers, nets, and volumes created by docker-compose up
down:
	docker-compose down