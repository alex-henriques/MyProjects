# User Documentation

## What this stack provides

This infraestructure runs a Wordpress website accessible at 'https://alehenri.42.fr' and consists of three services:
-> NGINX:     handles all incoming HTTPS traffic on port 442;
-> WordPress: runs the website and admin panel;
-> MariaDB:   stores all website data.

## Starting the project

```bash
make
```
After doing 'make' we wait about 30 seconds for all containers to initialise, then we visit: https://alehenri.42.fr.
The browser will give off a warning about an untrusted certificate and that's expected because a self-signed certificate was used, ie, it's not signed by CA (Certificate Authority).

## Stopping the project

-> Stop containers but keep all data:
```bash
make down
```

-> Full reset (deletes all data and images):
```bash
make fclean
```

## Accessing the website

-> 'https://alehenri.42.fr': public WP site;
-> 'https://alehenri.42.fr/wp-admin': WP administration panel.

## Credentials

Passwords are stored in the 'secrets/' directory at the project root; this directory is not committed to git and must be created manually on each machine.
-> 'secrets/db_pass.txt': WP database user password;
-> 'secrets/root_db_pass.txt': MariaDB root password;
-> 'secrets/credentials.txt': WP admin password.
The WordPress admin username is defined in 'srcs/.env' as 'WP_ADMIN_USER'.

## Checking that services are running

```bash
docker compose -f srcs/docker-compose.yml ps
```

All three services should show status 'running'. If any of them shows 'exited' then we check the logs:

```bash
make logs
```

To check a spcific service:
```bash
docker compose -f srcs/docker-compose.yml logs mariadb
docker compose -f srcs/docker-compose.yml logs wordpress
docker compose -f srcs/docker-compose.yml logs nginx
```

EOF