# Dockerfile para MariaDB basado en Debian Buster
FROM debian:buster

# Actualizar el gestor de paquetes y asegurar que tenemos los paquetes necesarios
RUN apt-get update -y && \
    apt-get install mariadb-server -y mariadb-server tini && \
    apt-get clean

# Configurar permisos de los directorios necesarios
RUN mkdir -p /var/lib/mysql /run/mysqld && \
    chown -R mysql:mysql /var/lib/mysql /run/mysqld


# Copiar archivo de configuración personalizado
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
RUN chmod 644 /etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/init_db.sh /etc/mysql/init_db.sh
# Asegurarse de que el script tenga permisos de ejecución
RUN chmod +x /etc/mysql/init_db.sh


# Exponer el puerto de MariaDB
EXPOSE 3306

# Tini es un gestor de procesos que se encarga de iniciar y supervisar el proceso principal del contenedor
ENTRYPOINT ["/usr/bin/tini", "--"]
# Comando para iniciar el servicio de MariaDB de forma segura
CMD ["/bin/bash", "-c", "/etc/mysql/init_db.sh && exec mysqld_safe"]

