from socket import *

# Server configuration (same as in server.py)
SERVER_NAME = '127.0.0.1'  # localhost
SERVER_PORT = 4938  # Last 4 digits of my student ID

client_socket = socket(AF_INET, SOCK_DGRAM) # Creating the UDP socket
# the address family AF_INET indicates that the underlying network is using IPv4
# the socket is of type SOCK_DGRAM which means UDP socket

while True:
    message = input("Enter a message to send (or 'quit' to exit): ") # Getting the user keyboard input
    if message.lower() == 'quit':
        break
    
    client_socket.sendto(message.encode('utf-8'), (SERVER_NAME, SERVER_PORT)) # Sending the message to the server
    data, _ = client_socket.recvfrom(2048) # Receiving the response from the server
    response = data.decode('utf-8')
    print(f"Server response: {response}")

client_socket.close() # Closing the client socket
