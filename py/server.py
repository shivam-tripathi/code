import socket 
import sys 

s = socket.socket()
port = 80

s.bind(('0.0.0.0', 2552))
s.listen(5)

while True:
    c, addr = s.accept()
    st = "Thanks for all the fish and so long\0"
    c.send(st)
    c.close()

