#with open("practice.txt","r") as f:
   # print(f.read())
f=open("practice.txt","r")
while True:
   line=f.readline()
   if not line:
    break
   else:
     print(line)

f.close()