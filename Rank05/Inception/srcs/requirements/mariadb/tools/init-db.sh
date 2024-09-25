#!/bin/bash
set -e

# Variables de entorno para la base de datos
db_name="database42"  # Cambia esto por el nombre de tu base de datos
db_user="isporras"       # Cambia esto por el nombre de tu usuario
db_pwd="1353"    # Cambia esto por la contraseña de tu usuario

# Esperar a que MariaDB esté disponible
until mysql -h "localhost" -u "root" -p"${MYSQL_ROOT_PASSWORD}" -e ""; do
    echo "Esperando a que MariaDB esté disponible..."
    sleep 2
done

# Crear el archivo SQL para inicializar la base de datos y el usuario
echo "CREATE DATABASE IF NOT EXISTS $db_name;" > /docker-entrypoint-initdb.d/db1.sql
echo "CREATE USER IF NOT EXISTS '$db_user'@'%' IDENTIFIED BY '$db_pwd';" >> /docker-entrypoint-initdb.d/db1.sql
echo "GRANT ALL PRIVILEGES ON $db_name.* TO '$db_user'@'%';" >> /docker-entrypoint-initdb.d/db1.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '12345';" >> /docker-entrypoint-initdb.d/db1.sql
echo "FLUSH PRIVILEGES;" >> /docker-entrypoint-initdb.d/db1.sql

# Ejecutar el script SQL
mysql -h "localhost" -u "root" -p"${MYSQL_ROOT_PASSWORD}" < /docker-entrypoint-initdb.d/db1.sql

echo "Base de datos y usuario creados con éxito."