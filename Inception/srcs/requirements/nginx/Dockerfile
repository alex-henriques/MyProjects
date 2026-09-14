FROM	alpine:3.19

RUN	apk update && apk add --no-cache nginx openssl

RUN	mkdir -p /etc/ssl/certs /etc/ssl/private

COPY	tools/generate_cert.sh /tmp/generate_cert.sh

RUN	chmod +x /tmp/generate_cert.sh && /tmp/generate_cert.sh

COPY	conf/nginx.conf /etc/nginx/nginx.conf

RUN	mkdir -p /var/www/html

EXPOSE	443

# running nginx in foreground: nginx -g "daemon off"; needed otherwise it would exit PID 1 and container would stop
CMD	["nginx", "-g", "daemon off;"]