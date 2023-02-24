import socket               
s = socket.socket()   

print("Socket successfully created")
port = 12345               
s.bind(('', port))    

print("socket binded to",port)
s.listen(5)     
print("socket is listening")

while True:

   c, addr = s.accept()     
   print('Got connection from', addr)

   data=c.recv(1024).decode()
   data = data.upper()
   if not data:
      break
   c.send(bytes(data,'utf-8'))

   data=c.recv(1024).decode()
   data = data.lower()
   if not data:
      break
   c.send(bytes(data,'utf-8'))

   data=c.recv(1024).decode()
   data = data.capitalize()
   if not data:
      break
   c.send(bytes(data,'utf-8'))

   data=c.recv(1024).decode()
   data = data[::-1]
   if not data:
      break
   c.send(bytes(data,'utf-8'))

   data=c.recv(1024).decode()
   data = data.swapcase()
   if not data:
      break
   c.send(bytes(data,'utf-8'))

   data=c.recv(1024).decode()
   data = data.title()
   if not data:
      break
   c.send(bytes(data,'utf-8'))

   data=c.recv(1024).decode()
   data = data.casefold()
   if not data:
      break
   c.send(bytes(data,'utf-8'))

   data=c.recv(1024).decode()
   data = data.lstrip()
   if not data:
      break
   c.send(bytes(data,'utf-8'))

   data=c.recv(1024).decode()
   data = data.rstrip()
   if not data:
      break
   c.send(bytes(data,'utf-8'))

   c.close()