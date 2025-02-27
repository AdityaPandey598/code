def add(num1,num2):
    return num1+num2

num1=40
num2=input(print("Enter a number: "))
try:
 result=add(num1,num2)

except:
   print("Added not correctly")
else:
   print(result)