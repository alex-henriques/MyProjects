FROM	alpine:3.19

#PHP packages:
	# php81: PHP 8.1 runtine (Alpine 3.19 ships 8.1)
	# php81-fpm:  the fast CGI process manager
	# php81-mysqli: WP uses mysqli to talk to MariaDB
	# php81-json: required by wordpress core
	# php81-curl: fot HTTP requests
	# php81-dom: XML/HTML parsing used by Wordpress
	# php81-exif: image metadatahandling
	# php81-fileinfo: MIME type detection
	# php91-mbstring: multibyte string support (needed for non ASCII content)
	# php81-openssl: HTTPS requests from within WP
	# php81-xml: XML parsing
	# php81-zip: plugin/theme installation
	# php81-iconv: character encoding conversion
	# mariadb-client: gives us mysqladmin for the "wait for MARIADB" check
RUN apk update && apk add --no-cache php81 php81-fpm php81-mysqli php81-json php81-curl php81-dom php81-exif php81-fileinfo php81-mbstring php81-openssl php81-xml php81-zip php81-iconv php81-phar mariadb-client wget curl bash

# create a group and user explicitly so php-fpm workers have a non root identity to run as because Alpine doesn't always create www-data automatically
RUN	addgroup -g 82 -S www-data || true
RUN	adduser -u 82 -D -S -G www-data www-data || true
RUN	ln -s /usr/bin/php81 /usr/bin/php
RUN	echo "memory_limit=256M" >> /etc/php81/php.ini

#wp-cli: command line tool; for managing WP
RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -O /usr/local/bin/wp && chmod +x /usr/local/bin/wp

# php-fpm pool config.: replace the default config with mine because mine listens to TCP 9000 and the default one doesn't
COPY	conf/www.conf /etc/php81/php-fpm.d/www.conf

# WP file location
RUN	mkdir -p /var/www/html && chown -R www-data:www-data /var/www/html

COPY	tools/setup_wordpress.sh /usr/local/bin/setup_wordpress.sh
RUN	chmod +x /usr/local/bin/setup_wordpress.sh

# php-fpm listens on port 9000, NGINX connects to it on the same port
EXPOSE	9000

ENTRYPOINT	["/usr/local/bin/setup_wordpress.sh"]
