FROM debian:latest

# Instalar dependencias necesarias
RUN apt-get update && apt-get install -y \
    lsb-release \
    apt-transport-https \
    ca-certificates \
    wget \
    gnupg

# Añadir el repositorio de PHP de sury.org
RUN echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" | tee /etc/apt/sources.list.d/php.list && \
    wget -qO - https://packages.sury.org/php/apt.gpg | apt-key add -

# Actualizar la lista de paquetes y actualizar el sistema
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    php8.2-fpm \
    php8.2-mysql \
    curl \
    netcat-openbsd

# Limpiar el caché de apt para reducir el tamaño de la imagen
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/.
COPY tools/wp-script.sh .

RUN chmod +x wp-script.sh

# Exponer el puerto que usará php-fpm
EXPOSE 9000

# Comando para iniciar PHP-FPM en primer plano (Se asegura de que mariadb se haya iniciado)
CMD ["sh", "-c", "until nc -z mariadb 3306; do echo 'Waiting for MariaDB...'; sleep 5; done; ./wp-script.sh"]