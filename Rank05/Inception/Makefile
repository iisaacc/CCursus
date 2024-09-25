.PHONY: all build up down

all: build up

#Execute docker compose build, that is building the images Docker for the services defined in docker-compose.yml
build:
	docker-compose build --no-cache
	docker save -o ./images/inception-nginx.tar inception-nginx

#It runs the containers in the background (-d)
up:
	docker-compose up -d

#It stops and deletes all the containers, nets, and volumes created by docker-compose up
down:
	docker-compose down

clean: down
	docker ps -a -q --filter ancestor=inception-nginx | xargs -r docker rm -f
	docker rmi -f inception-nginx
	rm -f ./images/inception-nginx.tar
