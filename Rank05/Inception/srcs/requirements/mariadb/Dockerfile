FROM debian:buster

RUN apt-get update -y && \
    apt-get install mariadb-server -y mariadb-server tini && \
    apt-get clean

RUN mkdir -p /var/lib/mysql /run/mysqld && \
    chown -R mysql:mysql /var/lib/mysql /run/mysqld

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
RUN chmod 644 /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/init.sql /usr/local/bin/init.sql
RUN chmod 644 /usr/local/bin/init.sql
COPY tools/init_db.sh /etc/mysql/init_db.sh
RUN chmod +x /etc/mysql/init_db.sh

EXPOSE 3306

USER mysql

ENTRYPOINT ["/usr/bin/tini", "--"]
CMD ["bash", "-c", "/etc/mysql/init_db.sh && mysqld_safe"]

