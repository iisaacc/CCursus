FROM debian:bullseye
# We define the following ARGs in the .env file
ARG CRED_PATH CRED_CERT CRED_KEY COUNTRY STATE LOCALITY ORGANIZATION ORG_UNIT COMMON_NAME
RUN apt update && apt upgrade -y && apt install -y nginx openssl gettext-base
RUN mkdir -p ${CRED_PATH}
# Creating a self-signed certificate for the server
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
-keyout ${CRED_PATH}/${CRED_KEY} \
-out ${CRED_PATH}/${CRED_CERT} \
-subj "/C=${COUNTRY}/ST=${STATE}/L=${LOCALITY}/O=${ORGANIZATION}/OU=${ORG_UNIT}/CN=${COMMON_NAME}"
COPY conf/nginx.conf ./tmp/nginx.conf
# Replace the variables in the nginx.conf file with the values from the .env file
RUN envsubst '$CRED_PATH $CRED_KEY $CRED_CERT $COMMON_NAME' < /tmp/nginx.conf > /etc/nginx/sites-available/default
# Run the nginx server in the foreground
ENTRYPOINT ["nginx", "-g", "daemon off;"]