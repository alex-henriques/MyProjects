#!/bin/sh
set	-e

DB_PASS=$(cat /run/secrets/db_pass)
DB_ROOT_PASS=$(cat /run/secrets/db_root_pass)

if [ ! -d "/var/lib/mysql/mysql" ]; then

	#inlitialise the data directory
	mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null

	#start a temp MariaDB locally in order to run setup SQL
	mysqld --user=mysql --skip-networking & TEMP_PID=$!

	#wait until the socket is ready
	until mysqladmin ping --socket=/run/mysqld/mysqld.sock --silent; do sleep 1
	done

	#SQL setup, SETUP commands are to create WORDPRESS DB, user with pass; grant user all rights on the DB only; set root pass; remove anonymous users and test
	#database
	mysql --socket=/run/mysqld/mysqld.sock << EOF

CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASS}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASS}';
DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
FLUSH PRIVILEGES;
EOF

	#stop the temp instance
	kill $TEMP_PID
	wait $TEMP_PID
fi

#exec and PID1; exec replaces shell process with mysql, ie, mysql becomes PID1 
exec mysqld --user=mysql
