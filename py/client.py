import socket 
import sys 

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print "Socket succesfully created"
except socket.error as err:
    print "Could not create socket %s" % err
    sys.exit()

port = 2552
host_ip = '0.0.0.0'

# try:
#     host_ip = socket.gethostbyname("google.com")
# except socket.gaierror:
#     print "Error resolving host"
#     sys.exit()


s.connect((host_ip, port))
chunk = s.recv(100)
print chunk
print "Successfully connected"

