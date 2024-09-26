#!/bin/bash

# Esperar a que MariaDB esté disponible
until mysql -h "mariadb" -u "${MYSQL_USER}" -p"${MYSQL_PASSWORD}" -e "SHOW DATABASES;" > /dev/null 2>&1; do
  echo "Esperando a que MariaDB esté disponible..."
  sleep 2
done

# Ejecutar el comando original
exec "$@"