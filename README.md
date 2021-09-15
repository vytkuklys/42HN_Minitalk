# 42HN_Minitalk
Minitalk is a data exchange program enabled with UNIX signals. This program displays strings send by client(s) to the server. <br/> This is achieved by intercepting signals and sending information bit by bit.

## Run Project Locally
* Clone or fork this repository
* Type ```make``` command in the terminal
* Run server executable (e.g. ```./server```)
* Open a new terminal window
* Run client executable followed by PID (that is displayed after running ./server) and a string (e.g. ```./client PID "Hello Server"```)
