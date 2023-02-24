import socket               
s = socket.socket()  

port = 12345            
s.connect(('192.168.225.166', port))

str = input("Enter string:")

s.send(bytes(str,'utf-8'))
data = s.recv(1024).decode()
print("Upper Case:",data)

s.send(bytes(str,'utf-8'))
data = s.recv(1024).decode()
print("Lower Case:",data)

s.send(bytes(str,'utf-8'))
data = s.recv(1024).decode()
print("Capitalized:",data)

s.send(bytes(str,'utf-8'))
data = s.recv(1024).decode()
print("Reversed:",data)

s.send(bytes(str,'utf-8'))
data = s.recv(1024).decode()
print("Swap case:",data)

s.send(bytes(str,'utf-8'))
data = s.recv(1024).decode()
print("Title:",data)

s.send(bytes(str,'utf-8'))
data = s.recv(1024).decode()
print("Casefold:",data)

s.send(bytes(str,'utf-8'))
data = s.recv(1024).decode()
print("Left strip:",data)

s.send(bytes(str,'utf-8'))
data = s.recv(1024).decode()
print("Right strip:",data)

s.close()