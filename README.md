# Rock-Paper-Scissors Server and Client Game

This project is a rock-paper-scissors game developed using the C programming language. The application operates with a server-client architecture and communicates over the TCP/IP protocol. The project consists of two main components:

1. **Server**: Manages incoming client connections, responds to moves received from clients, and keeps track of game scores.
2. **Client**: Receives moves from the user and sends them to the server, then displays the responses received from the server.

## Technologies Used and Language Features

- **Programming Language**: C  
- **Libraries**:
  - `winsock2.h`: Supports TCP/IP socket programming for the Windows operating system.
  - `time.h`: Used for random number generation and time-related operations.
  - `utils.h`: Contains common functions such as valid move checking, converting to lowercase, and determining the winner.
- **Protocol**: TCP/IP  
- **Client-Server Communication**: The server uses threads (`CreateThread`) to handle multiple clients concurrently.

## Server

The server program performs the following functions:

1. **Initialization and Listening**:
   - Binds to a specific IP and port using `bind`.
   - Waits for client connections using the `listen` command.

2. **Connection Management**:
   - A separate thread is created for each incoming client connection.
   - Messages received from the client are read and processed during the connection.

3. **Game Logic**:
   - Checks the validity of incoming moves.
   - Generates a random move for the server.
   - Compares moves to determine the winner.
   - Tracks scores and sends the results to the client.

4. **Commands**:
   - `yardim`: Lists available commands.
   - `skor`: Displays the current player and server scores.
   - `exit`: Terminates the client connection.

### Key Features

- Multithreaded management to support multiple clients.
- Use of a `Score` structure for score tracking.
- Detection of invalid moves and sending appropriate messages.

## Client

The client program performs the following functions:

1. **Establishing a Connection**:
   - Connects to the server and sends user moves to the server.

2. **User Interaction**:
   - Receives moves from the user: `tas`, `kagit`, `makas`, `yardim`, `skor`, `exit`.
   - Reads messages from the server and displays them on the screen.

3. **Game Flow**:
   - Each time the user makes a move, the client communicates with the server and displays the result.
