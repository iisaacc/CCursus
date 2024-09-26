#!/bin/bash
source /usr/local/bin/.env

# Variables de entorno desde el archivo .env
DB_NAME=${MYSQL_DATABASE}
DB_USER=${MYSQL_USER}
DB_PASS=${MYSQL_PASSWORD}
ROOT_PASS=${MYSQL_ROOT_PASSWORD}

# Esperar a que MariaDB esté disponible
until mysql -u "root" -p"${MYSQL_ROOT_PASSWORD}" -e ""; do
    echo "Esperando a que MariaDB esté disponible..."
    sleep 2
done

# Ejecuta comandos para configurar la base de datos
mysql -u root -p"${ROOT_PASS} << EOF
CREATE DATABASE IF NOT EXISTS ${DB_NAME};
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASS}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${ROOT_PASS}';
FLUSH PRIVILEGES;
EOF
