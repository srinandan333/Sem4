#importing libraries
import nmap
import time

#taking ip address as input
target = input("Enter ip address to scan: ")

#initiating port scanner
scanner = nmap.PortScanner()

#taking choice as input
print("1) Scan single port 2) Scan range of ports 3) Scan multiple ports")
choice = int(input("Enter choice: "))

#code to scan single port number
if(choice == 1):
	#taking port number as input
	port = int(input("Enter port number to scan: "))
	#starting timer
	start = time.time()
	#scanning port number
	res = scanner.scan(target, str(port))
	res = res['scan'][target]['tcp'][port]['state']
	print(f'port {port} is {res}.')
	#ending timer
	end = time.time()
	print(f"Time taken {end-start:.2f} seconds")

#code to scan a range of port numbers
elif(choice == 2):
	#taking range of port numbers as input
	begin = int(input("Enter start of range of port numbers: "))
	end = int(input("Enter end of range of port numbers: "))
	#starting timer
	start = time.time()
	#scanning port numbers
	for i in range(begin, end+1):
		res = scanner.scan(target,str(i))
		res = res['scan'][target]['tcp'][i]['state']
		print(f'port {i} is {res}.')
	#ending timer
	end = time.time()
	print(f"Time taken {end-start:.2f} seconds")

#code to scan multiple port numbers
elif(choice == 3):
	#taking array of port numbers as input
	arr = []
	n = int(input("Enter number of port numbers: "))
	for i in range(0, n):
		ele = int(input("Enter port number: "))
		arr.append(ele)
		#starting timer
	start = time.time()
	#scanning port numbers
	for j in arr:
		res = scanner.scan(target, str(j))
		res = res['scan'][target]['tcp'][j]['state']
		print(f'port {j} is {res}.')
	#ending timer
	end = time.time()
	print(f"Time taken {end-start:.2f} seconds")
	
