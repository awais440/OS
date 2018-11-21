process = []
dictionary = {}
parameters = []
haultProcess = []
processhault = False
file = open("temp","r")
line = file.readline()
for word in line.split():
    parameters.append(word)
data = file.readlines()
index = 0
for line in data:
    for word in line.split():
        dictionary[parameters[index]] = word
        index = index+1
    process.append(dictionary.copy())
    index = 0 
import time
process = sorted(process,key = lambda k: (int(k["AT"]),int(k["Priority"])))
a = 0
index = 0
print("Priority Scheduling PreEmptive")
for dictionary in process:
    if processhault == True:
        process.append(haultedprocess.copy())  
        process[index+1:] = sorted(process[index+1:],key = lambda k: (int(k["AT"]),int(k["Priority"])))
    processhault = False
    if a < int(dictionary["AT"]):
        print(a,end='')
        while a < int(dictionary["AT"]):
            print('.',end='')
            a = a+1  
        print(a,end = '')
    for i in range(1,int(dictionary["Duration"])+1):
        for d in process:
            if a == int(d["AT"]) and dictionary["Processes"]!= d["Processes"] and int(d["Priority"]) < int(dictionary["Priority"]):
                dictionary["Duration"] = str(int(dictionary["Duration"])-a)    
                haultedprocess = dictionary
                processhault = True
                break
        if processhault == True:  
            index = index+1
            break;
        print("_",end = '')
        a = a+1
    print(dictionary["Processes"],end = '')
    print("(",end = '')
    print(a,end = '')
    print(")",end = '')
    index = index+1
    

    		

        
