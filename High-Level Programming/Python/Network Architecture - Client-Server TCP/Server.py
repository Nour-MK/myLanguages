from socket import *

# Server configuration
SERVER_PORT = 4938  # Last 4 digits of your student ID

# Create a TCP socket
server_socket = socket(AF_INET, SOCK_STREAM) # SOCK_STREAM indicates a TCP socket
server_socket.bind(('', SERVER_PORT)) # an empty string '' means bind this socket to all available network interfaces on this machine, and listen on the port specified by SERVER_PORT.
# ('127.0.0.1', SERVER_PORT) would only accept connections from the localhost.
# ('192.168.1.100', SERVER_PORT) would only accept connections directed to the specific IP 192.168.1.100.
server_socket.listen(1) # server begins listening for incoming TCP requests

print(f"TCP server is listening on {SERVER_PORT}")

while True: # Loop forever - This loop allows the server to continuously accept new client connections.
    client_socket, client_address = server_socket.accept() # The server waits on accept() for incoming requests, and a new socket is created on return
    print(f"Connected to client: {client_address}") # Just a message to indicate the current state of the program

    while True: # Loop forever - This loop handles the communication with a single connected client. It allows the server to receive multiple messages from the same client without closing the connection. The loop continues until the client closes the connection or sends an empty message. When the client disconnects, the inner loop ends, and the server goes back to the outer loop.
        # While the server is in this inner loop, it's blocked from accepting new connections or communicating with other clients. Only after the current client disconnects (when client_socket.recv(2048) returns an empty string), does the server go back to the outer loop and become ready to accept a new client. So, this server is essentially handling clients one at a time. If a second client tries to connect while the server is communicating with the first client, the second client will be queued and won't be served until the first client disconnects.
        data = client_socket.recv(2048) # This reads the bytes from the socket but not the address as in UDP
        if not data:
            break
        message = data.decode('utf-8')
        print(f"Received message from {client_address}: {message}")
        response = f"Server received: {message}"
        client_socket.send(response.encode('utf-8'))

    client_socket.close()
    print(f"Connection closed with {client_address}")
server_socket.close()
