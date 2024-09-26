
.PHONY: all build up down clean save_images

all: build

#Execute docker compose build, that is building the images Docker for the services defined in docker-compose.yml
build:
	@docker compose -f srcs/docker-compose.yml up --build
	docker save -o ./images/inception-nginx.tar inception-nginx
	docker save -o ./images/inception-mariadb.tar inception-mariadb

#It runs the containers in the background (-d)
up:
	docker compose -f srcs/docker-compose.yml up -d

#It stops and deletes all the containers, nets, and volumes created by docker-compose up
down:
	docker-compose down

clean: down
	docker ps -a -q --filter ancestor=inception-nginx | xargs -r docker rm -f
	docker rmi -f inception-nginx
	rm -f ./images/inception-nginx.tar
	docker ps -a -q --filter ancestor=inception-mariadb | xargs -r docker rm -f
	docker rmi -f inception-mariadb
	rm -f ./images/inception-mariadb.tar

save_images:
	docker save -o ./images/inception-nginx.tar inception-nginx
	docker save -o ./images/inception-mariadb.tar inception-mariadb