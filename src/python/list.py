list1=["physics","chemistry",1997,2000]
list2=[1,2,3,4,5,6,7]

print(f"list1[0]: {list1[0]}")
print(f"list2[1:5]: {list2[1:5]}")

print(f"value available at index 2: {list1[2]}")
list1[2]=2001
print(f"value available at index 2: {list1[2]}")

list1.append("math")
list1.extend("biology")
print(list1)

del list1[2]
print(f"after delete value at index 2: {list1}")

print(f"list operation [1,2,3]+[4,5,6]: {[1,2,3]+[4,5,6]}")
print(f"list operation ['Hi!']*4: {['Hi!']*4}")
