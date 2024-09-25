# Dockerfile para MariaDB basado en Debian Buster
FROM debian:buster

# Actualizar el gestor de paquetes y asegurar que tenemos los paquetes necesarios
RUN apt-get update -y && \
    apt-get install mariadb-server -y && \
    apt-get clean

# Cambiar la configuración de MariaDB para permitir conexiones externas
RUN sed -i 's/bind-address\s*=\s*127.0.0.1/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

# Exponer el puerto de MariaDB
EXPOSE 3306

# Copiar un script de inicialización para crear la base de datos y el usuario
COPY ./tools/init-db.sh /docker-entrypoint-initdb.d/init-db.sh

# Asegurarse de que el script tenga permisos de ejecución
RUN chmod +x /docker-entrypoint-initdb.d/init-db.sh

# Comando para iniciar el servicio de MariaDB de forma segura
CMD ["/usr/bin/mysqld_safe"]

