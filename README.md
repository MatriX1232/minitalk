# MINITALK

<div align="center">
  <img src="MINITALK_LOGO.png">
</div>

## Info
This project is a simple demonstration of data transmission using UNIX signals. It consists of a server and a client program.
The server waits for signals from the client and the client sends signals to the server. 
The communication between the client and the server is done using the UNIX signals ```SIGUSR1``` and ```SIGUSR2```.

## Compilation
The project uses Makefiles for compilation. To compile the project, run the following command in the root directory:
```sh
make
```
This will compile the server and client programs, as well as the ```ft_printf``` library.

## Usage
To start the server, run:
```sh
./server
```
The server will print its PID (Process ID). You will need this PID to send signals to the server.

To send a message to the server, run the client with the server's PID and the message:
```sh
./client <PID> <MESSAGE>
```
