from socket import *

# Server configuration
SERVER_PORT = 4938  # Last 4 digits of my student ID
server_socket = socket(AF_INET, SOCK_DGRAM) # Creating the UDP socket
server_socket.bind(('', SERVER_PORT)) # Binding the socket to the local port number 4938
print("UDP server is listening and ready to receive")

while True: # Loop forever
    data, client_address = server_socket.recvfrom(2048) # Receiving data from the UDP socket - 2048 is the buffer size ]
    # This way, when amyone sends a packet to port 4938, the packet will be directed to this UDP socket and enters a while loop in which the server will receive it and store it in the data variable
    message = data.decode('utf-8') # Decoding the received data

# UTF-8 (Unicode Transformation Format - 8-bit) is generally considered better than ASCII, it supports a much wider range of characters, can represent characters from virtually all writing systems in the world, including emojis. It is also backward compatible with ASCII

    print(f"Received message from {client_address}: {message}")
    
    response = f"Server received: {message}" # Sending a response back to the client
    server_socket.sendto(response.encode('utf-8'), client_address)

# Notes to self: 
# Whether it is TCP or UDP, the server code must run first because it has to be listening first before the client can send anything - You can't speak to someone who isn't listening
# Open 2 terminals side by side and cd to the directory where the code files are located then run the commmands python server.py then python client.py