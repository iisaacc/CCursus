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

COPY tools/init_db.sh /init_db.sh

# Asegurarse de que el script tenga permisos de ejecución
RUN chmod +x /init_db.sh

# Exponer el puerto de MariaDB
EXPOSE 3306

# Comando para iniciar el servicio de MariaDB de forma segura
ENTRYPOINT ["/usr/bin/tini", "--"]
CMD ["mysqld_safe"]

