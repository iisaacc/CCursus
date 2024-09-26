# Dockerfile para MariaDB basado en Debian Buster
FROM debian:buster

# Actualizar el gestor de paquetes y asegurar que tenemos los paquetes necesarios
RUN apt-get update -y && \
    apt-get install mariadb-server -y && \
    apt-get clean

# Exponer el puerto de MariaDB

# Copiar un script de inicialización para crear la base de datos y el usuario
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/init_db.sh /usr/local/bin/init_db.sh
COPY ../../.env /usr/local/bin/.env

# Asegurarse de que el script tenga permisos de ejecución
RUN chmod +x /usr/local/bin/init_db.sh
RUN /usr/local/bin/init_db.sh

EXPOSE 3306

# Comando para iniciar el servicio de MariaDB de forma segura
CMD ["mysqld_safe"]

