def Validateinput(turn,i,j,my_list):
     Player=player(turn)
     valid=False
     while valid==False:
         
         ans=input("Please enter input for "+Player+":")
         if my_list[i][j]=="":
                if ans in ['X','O','x','o']:
                 valid=True
         
         else:
             print("Please enter valid input")
     return ans   
          
def print_arr(my_list):
     for i in range(0,3):
         for j in range(0,3):
             print(my_list[i][j],end=" ")
         print()
             

def player(turn):
     if turn%2==0:
      return "A"
     else:
          return "B"

def check_win(my_list):
    for i in range(0,3):
          if my_list[i][0]==my_list[i][1]==my_list[i][2] and my_list[i][0]!=" ":
            return 1
          if  my_list[0][i]==my_list[1][i]==my_list[2][i] and my_list[0][i]!=" ":
            return 1
          if my_list[0][0]==my_list[1][1]==my_list[2][2] and my_list[0][0]!=" ":
            return 1
          if my_list[0][2]==my_list[1][1]==my_list[2][0] and my_list[0][2]!=" ":
            return 1
          else:
            return 0
    
    
        

def GetInput(my_list,turn):
     
     while turn<=9:
               if turn+1>=6:
                if check_win(my_list):
                    temp2=player(turn+1)
                    print(temp2+" has won")
                    break

               i=int(input("Enter x axis for input:"))
               j=int(input("Enter y axis for input:"))
               temp=Validateinput(turn,i-1,j-1,my_list)
               my_list[i-1][j-1]=temp
               print_arr(my_list)
               turn+=1

                       
               

my_list=[["" for x in range(3)] for y in range(3)]
GetInput(my_list,0)
print_arr(my_list)



