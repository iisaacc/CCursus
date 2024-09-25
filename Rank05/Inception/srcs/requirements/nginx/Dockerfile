# Dockerfile para el servicio NGINX basado en Alpine (Version de linux muy ligera, muy optimizada para docker, ya que las imagenes son muy ligeras)
FROM alpine:3.18

# Instalar NGINX y OpenSSL para el soporte de TLS (TLS se usa utiliza para asegurar la comunicacion entre clientes y servidores en Internet mediante cifrado)
RUN apk add --no-cache nginx openssl

# Copiar archivos de configuración y certificados
COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/ssl/cert.pem /etc/nginx/ssl/cert.pem
COPY ./conf/ssl/key.pem /etc/nginx/ssl/key.pem

# Crear directorio para el contenido HTML (puedes agregar archivos personalizados)
RUN mkdir -p /usr/share/nginx/html && \
    echo '<h1>Servidor NGINX con TLS</h1>' > /usr/share/nginx/html/index.html

# Exponer el puerto 443 para TLS
EXPOSE 443

# Comando por defecto para iniciar NGINX (daemon off hace que se ejecute en primer plano, haciendo que docker pueda gestionar bien el ciclo de vida del contenedor)
CMD ["nginx", "-g", "daemon off;"]
