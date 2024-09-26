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
RUN apt-get update && apt-get upgrade -y

# Instalar PHP-FPM
RUN apt-get install -y php8.2-fpm

# Limpiar el caché de apt para reducir el tamaño de la imagen
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/.

# Exponer el puerto que usará php-fpm
EXPOSE 9000

# Comando para iniciar PHP-FPM en primer plano
CMD ["php-fpm8.2", "-F"]