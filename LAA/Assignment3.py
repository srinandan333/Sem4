# importing libraries
import numpy as np

# taking stochastic matrix as input 
print("Enter elements of the 3x3 stochastic voting probability matrix:")
i = 0
j = 0
stoch = []
for i in range(3):          
    temp =[]
    for j in range(3):      
         temp.append(float(input()))
    stoch.append(temp)
print("Stochastic matrix: \n", stoch)

# taking probability vector as input 
print("Enter the voting distribution for bjp, aap and con in 2000:")
i = 0
j = 0
vote = []
for i in range(3):          
    temp =[]
    for j in range(1):      
         temp.append(float(input()))
    vote.append(temp)
print("The voting distribution for bjp, aap and con in 2000 is: \n", vote)

# taking year as input
beg = 2000
end = int(input("Enter the year for which you want to calculate voting distribution: \n"))

# calculating the probability vector for that year
i = beg
for i in range(beg, end):
	vote = np.matmul(stoch, vote)
print("Voting distribution for bjp, aap and con in that year: \n", vote)