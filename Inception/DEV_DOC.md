# Developer Documentation

## Prerequisites

Install these on the VM before anything else:

```bash
sudo apt update
sudo apt instal -y docker.io docer-compose-plugin make git
sudo usermod -aG docker $USER
newgrp docker
```

## Environment setup from scratch

### 1. Clone the Repository

```bash
git clone git@github.com:alex-henriques/Inception.git
cd Inception
```

### 2. Create secrets (manually, not in git)

```bash
mkdir -p secrets
echo "<db_password>" > secrets/db_pass.txt
echo "<root_db_password>" > secrets/db_root_pass.txt
echo "<admin_password>" > secrets/credentials.txt
```

### 3. Create srcs/.env (manually, not in git)

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

### 4. Configure /etc/hosts

```bash
echo "127.0.0.1 alehenri.42.fr" | sudo tee -a /etc/hosts
```

## Building & Launching

```bash
make
```
This will:
-> Create '/home/alehenri/data/mysql' and '/home/alehenri/data/wordpress' on the host;
-> Build all three Docker images from their Dockerfiles;
-> Start all containers in detached mode.

First build can take 2 to 3 minutes; following builds are faster due to layer caching.

## Managing Containers

```bash
# See running containers and their status
docker compose -f srcs/docker-compose.yml ps
# Stream all logs
make logs
# Restart a single service without rebuilding
docker compose -f srcs/docker-compose.yml restart wordpress
# Rebuild and restart a single service
docker compose -f srcs/docker-compose.yml up -d --build wordpress
# Open a shell inside a running container
docker exec -it wordpress sh
docker exec -it mariadb sh
docker exec -it nginx sh
# Connect to MariaDB directly
docker exec -it mriadb mysql -u root -p
```

## Managing Volumes

```bash
#List all Docker volumes
docker volume ls
# Inspect a volume (shows host mount path)
docker volume inspect srcs_db_data
docker volume inspect srcs_wp_data
```

### Where data is stored

-> MariaDB databases:
	-> Container path:		/var/lib/mysql
	-> Host path:			/home/alehenri/data/mysql
-> WordPress files:
	-> Container path:		/var/www/html
	-> Host path:			/home/alehenri/data/wordpress

Data persists across 'make down' and 'make' cycles. To Wipe all data and start fresh:

```bash
make clean
make
```

## Project Structure

Inception/
├── Makefile
├── .gitignore
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
└── srcs/
├── .env (not in git)
├── docker-compose.yml
└── requirements/
├── mariadb/
│ ├── Dockerfile
│ ├── conf/my.cnf
│ └── tools/setup_db.sh
├── wordpress/
│ ├── Dockerfile
│ ├── conf/www.conf
│ └── tools/setup_wordpress.sh
└── nginx/
├── Dockerfile
├── conf/nginx.conf
└── tools/generate_cert.sh

EOF