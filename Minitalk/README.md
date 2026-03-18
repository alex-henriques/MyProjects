# minitalk

Minitalk is a small C client-server communication program that transmits strings between processes using only UNIX signals (`SIGUSR1` and `SIGUSR2`).

## Build

```bash
make
```

this produces two binaries: `server` and `client`.

## Usage

Start the server first (it'll print its PID):

```bash
./server
# This is the PID: 12345
```

Then send a message from the client using that PID:

```bash
./client 12345 "hello world"
```
The server will print the received message to stdout.

## How it works

Each character is encoded bit by bit and transmitted as a sequence of signals:
-`SIGUSR1` -> bit `1`
-`SIGUSR2` -> bit `0`

The client sends 8 signals per character (MSB first), followed by 8 `SIGUSR2` signals for the null terminator. The server reconstructs each character in its signal handler and prints it once all 8 bits are received.

## Project structure

```
minitalk/
├── client.c      # Encodes and sends the message bit by bit
├── server.c      # Decodes incoming signals and prints the message
├── libft/        # Custom C library
└── Makefile
```
