#!/bin/bash

# Reemplaza los marcadores de posición en el archivo SQL con las variables de entorno
envsubst < /usr/local/bin/init.sql > /usr/local/bin/init.sql

# Inicia el servidor MySQL en segundo plano
mysqld_safe &

# Espera a que el servidor MySQL esté listo
until mysqladmin ping --silent; do
  echo -n "."; sleep 1
done

# Ejecuta el archivo SQL con las variables de entorno reemplazadas
mysql -u root -p"${MYSQL_ROOT_PASSWORD}" < /usr/local/bin/init.sql

# Detén el servidor MySQL
mysqladmin shutdown -p"${MYSQL_ROOT_PASSWORD}"