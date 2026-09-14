# !/bin/sh
set	-e

openssl	req	-x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt \
	-subj "/C=LU/ST=Luxembourg/L=Luxembourg/0=42/OU=42/CN=alehenri.42.fr"

# openssl req -x509: generate a self signed certificate (not a CSR-> certificate signing request)
# -nodes: no passphrase on the private key -> needed for automated startup, ie nobody to type a password
# -days 365: certificate valid for a year
# -newkey rsa:2048: generate a new 2048-bit RSA key pair
# -keyout: where to write the private key
# -out: where to right the certificate
# -subj: certificate subject fields, all in one line. CN = common name = the domain this cert is for