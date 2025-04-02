from telnetlib import Telnet

website_name = 'www.aurak.ac.ae'
port = 25 # This is the port number of the SMTP mail server protocol

tn = Telnet(website_name, port, timeout=10) # Connect to the mail server
tn.interact() # Interact with the server
