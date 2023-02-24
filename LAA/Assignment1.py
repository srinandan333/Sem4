# importing libraries
import numpy as np
from numpy.linalg import inv

# initializations
array = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
encodedmatrix = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
tempmatrix1 = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
tempmatrix2 =[[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
alphabets = [" ","a", "b", "c", "d", "e", "f", "g", "h",
			"i", "j", "k", "l", "m", "n", "o", "p", "q",
			"r", "s", "t", "u", "v", "w", "x", "y", "z"]
numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
			13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
			23, 24, 25, 26, 27]

# taking encoding matrix as input
print("Enter elements of the 2x2 encoding matrix:")
i = 0
j = 0
encodingmatrix = []
for i in range(2):          
    temp =[]
    for j in range(2):      
         temp.append(int(input()))
    encodingmatrix.append(temp)
print("Encoding matrix:", encodingmatrix)

# taking string as input
string = str(input("Enter the string: "))
listb = list(string)
length = len(listb)

# converting the string into numbers
for i in range(length):
	for j in range(27):
		if(listb[i] == alphabets[j]):
			array[i] = numbers[j]
			break							
if(length%2 == 1):
	length = length+1
array = array[0:length]

# converting array to matrix
i = 0
j = 0
k = 0
n = int(length/2)
for i in range(0,length):
	if(j<n):
		tempmatrix1[k][j] = array[i]
		j = j+1
	else:
		k = k+1
		j = 0
		tempmatrix1[k][j] = array[i]
		j = j+1	

# encoding the matrix
encodedmatrix = np.matmul(encodingmatrix, tempmatrix1)

# converting matrix to array
i = 0
j = 0
k = 0
for i in range(2):
	for j in range(int(length/2)):
		array[k] = encodedmatrix[i][j]
		k = k+1
array = array[0:length]
print("Encoded string:", array)
sobj = slice(length)
array = array[sobj]

# converting array to matrix
i = 0
j = 0
k = 0
n = int(length / 2)
for i in range(0, length):
	if(j<n):
		tempmatrix2[k][j]= array[i]
		j = j + 1
	else:
		k = k + 1
		j = 0
		tempmatrix2[k][j]= array[i]
		j = j + 1

# decoding the matrix
invertedmatrix = inv(encodingmatrix)
decodedmatrix = np.matmul(invertedmatrix, tempmatrix2)

# converting matrix to array
i = 0
j = 0
k = 0
for i in range(2):
	for j in range(int(length / 2)):
		array[k]= decodedmatrix[i][j]
		k = k + 1	

# converting numbers back to string
text = ""
for i in range(0, length):
	for j in range(0, 27):
		if(array[i]== numbers[j]):
			text =''.join([text, alphabets[j]])
print("Decoded string: "+text)