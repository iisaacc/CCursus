#!/bin/bash

# Limpia el directorio de WordPress
rm -rf /var/www/html/*

# Cambia el directorio actual a /var/www/html
cd /var/www/html

# Descarga el archivo wp-cli.phar desde el repositorio oficial de WP-CLI en GitHub
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

# Otorga permisos de ejecución al archivo wp-cli.phar
chmod +x wp-cli.phar

# Descarga el núcleo de WordPress utilizando WP-CLI
./wp-cli.phar core download --allow-root

# Crea el archivo de configuración wp-config.php con las credenciales de la base de datos
./wp-cli.phar config create --dbname=${WP_DB_NAME} --dbuser=${WP_DB_USER} --dbpass=${WP_DB_PASSWORD} --dbhost=${WP_DB_HOST} --allow-root

# Instala WordPress con los detalles proporcionados (URL, título del sitio, usuario administrador, contraseña y correo electrónico)
./wp-cli.phar core install --url=${WP_URL} --title=${WP_TITLE} --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASSWORD} --admin_email=${WP_ADMIN_EMAIL} --allow-root

# Inicia el servidor PHP-FPM en primer plano
php-fpm8.2 -F