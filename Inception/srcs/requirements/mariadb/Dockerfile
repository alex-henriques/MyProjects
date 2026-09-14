FROM	alpine:3.19

RUN	apk update && apk add --no-cache mariadb mariadb-client

RUN	mkdir -p /run/mysqld /var/lib/mysql && chown -R mysql:mysql /run/mysqld && chown -R mysql:mysql /var/lib/mysql

COPY	conf/my.cnf /etc/my.cnf

COPY	tools/setup_db.sh /usr/local/bin/setup_db.sh

RUN	chmod +x /usr/local/bin/setup_db.sh

EXPOSE	3306

ENTRYPOINT	["/usr/local/bin/setup_db.sh"]