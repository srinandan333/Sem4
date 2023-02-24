# importing libraries
import numpy as np

# taking stochastic matrix as input 
print("Enter elements of the 2x2 stochastic migration probability matrix:")
i = 0
j = 0
stoch = []
for i in range(2):          
    temp =[]
    for j in range(2):      
         temp.append(float(input()))
    stoch.append(temp)
print("Stochastic matrix: \n", stoch)

# taking probability vector as input 
print("Enter the population distribution of karnataka and tamil nadu in 2000:")
i = 0
j = 0
pop = []
for i in range(2):          
    temp =[]
    for j in range(1):      
         temp.append(float(input()))
    pop.append(temp)
print("The population distribution of karnataka and tamil nadu in 2000 is: \n", pop)

# taking year as input
beg = 2000
end = int(input("Enter the year for which you want to calculate population distribution: \n"))

# calculating the probability vector for that year
i = beg
for i in range(beg, end):
	pop = np.matmul(stoch, pop)
print("The population distribution of karnataka and tamil nade in that year is: \n", pop)