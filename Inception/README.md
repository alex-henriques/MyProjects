# Inception

## Description

Inception is a system administration. The goal is to set up a small infraestructure composed of three services orchestrated with Docker Compose, running inside of a  virtual machine.

The infraestructure consists of:
-> NGINX: the only entry point, listening on port 443 with TLSv1.2/TLSv1.3;
-> Wordpress & php-fpm: the web application running without NGINX;
-> MariaDB: the database, also running without NGINX.

Each service runs in its own dedicated container built from Alpine 3.19. All images are built from scratch. 

### Virtual Machine vs Docker

A VM emulates an entire computer including its own Kernel, hardware drivers, and Operating System. It's fully isolated but heavy, slow to boot, high memory usage and large disk footprint. While Docker Containers share the host Kernel, they're isolated processes, Linux namespaces give each container its own filesystem, network, and PID space, while cgroups limit resource usage. Containers start in milliseconds and use a fraction of the resources a VM needs.

### Secrets vs Environment Variables

Docker secrets are mounted as files at 'run/secrets<name>' inside containers at runtime. They never appear in image layers or 'docker inspect' output. Passwords and other sensitive information belong in secrets.

Environment Variables, stored in '.env', are suitable for non sensitive configuration like database names, domain names, and usernames. They're visible in 'docker inspect' output and image layers.

### Docker Network vs Host Network

Docker bridge networking gives each container its own network namespace. Containers communicate by service name via Docker's built in DNS. Only explicitly published ports are accessible from outside.

Host networking makes the container share the host machine's network stack directly. There's no network isolation. Forbidden in this project's subject.

### Docker Volumes vs Bind Mounts

Docker Volumes are managed by Docker. In this project I use named volumes configured with 'driver_opts' to point to '/home/alehenri/data/' on the host.

Bind Mounts map a specific host directory path into a container; simple but less portable.

## Instructions

### Prerequisites

-> Linux VM with Docker and Docker Compose V2 installed;
-> 'make' installed;
-> The user added to the 'docker' group.

### Setup

1. Clone the rep into the VM:
```bash
git clone git@github.com:alex-henriques/Inception.git
cd Inception
```

2. Create the secrets directory and files:
```bash
mkdir -p secrets
echo "<db_password>" > secrets/db_pass.txt
echo "<root_db_password>" > secrets/db_root_pass.txt
echo "<admin_password>" > secrets/credentials.txt
```

3. Create 'srcs/.env':
```bash
cat > srcs/.env << 'ENVEOF'
DOMAIN_NAME=alehenri42
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
WP_TITLE=Inception
WP_ADMIN_USER=alehenri
WP_ADMIN_EMAIL=alehenri@student.42luxembourg.lu
WP_USER=visitor
WP_USER_EMAIL=visitor@alehenri.42.fr
ENVEOF
```

4. Add the domain to '/etc/hosts':
```bash
echo "127.0.0.1 alehenri.42.fr" | sudo tee -a /etc/hosts
```

5. Build and start:
```bash
make
```

6. Visit 'https://alehenri.42.fr' in a browser and accept the certificate warning.

### Makefile commands

-> 'make':		  create data directories, build images, and start containers;
-> 'make down':   stop and remove containers but keep volumes;
-> 'make clean':  stop containers, remove volumes, and host data;
-> 'make fclean': all of the above plus remove all Docker images;
-> 'make re': 	  full rebuild from scratch;
-> 'make logs':   stream logs from all containers.

## Resources

-> Docker documentation: https://docs.docker.com;
-> Docker Compose: https://docs.docker.com/compose/compose-file/;
-> NGINX documentation: https://nginx.org/en/docs/;
-> PHP-FPM configuration: https://www.php.net/manual/en/install.fpm.configuration.php;
-> MariaDB documentation: https://mariadb.com/kb/en/documentation/;
-> WP-CLI documentation: https://wp-cli.org/.

### AI usage

Claude Anthropic was used during this project for explaining some Docker concepts like volumes, networking, and PID1 behaviour; explaining php-fpm process management configuration and a bit of Docker Compose.
