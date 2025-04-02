from socket import *

# Server configuration (same as in server.py)
SERVER_NAME = '127.0.0.1'  # localhost
SERVER_PORT = 4938  # Last 4 digits of your student ID

# Create a TCP socket
client_socket = socket(AF_INET, SOCK_STREAM)
client_socket.connect((SERVER_NAME, SERVER_PORT))

print(f"Connected to server: {SERVER_NAME}:{SERVER_PORT}")

while True:
    message = input("Enter a message to send (or 'quit' to exit): ")
    if message.lower() == 'quit':
        break

    client_socket.send(message.encode('utf-8')) # Notice how we don't need to attach the server name and the port number 
    data = client_socket.recv(2048)
    response = data.decode('utf-8')
    print(f"Server response: {response}")

client_socket.close()
print("Connection closed")
