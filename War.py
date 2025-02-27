values={'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8, 'Nine':9, 'Ten':10, 'Jack':11, 'Queen':12, 'King':13, 'Ace':14}
suits=("Hearts","Diamonds","Spades","Clubs")
rank=("Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace")
class Card:

    def __init__(self,suit,rank):
        self.suit=suit
        self.rank=rank
        self.value=values[rank]

    def __str__(self):  
         return "Suit is "+self.suit+"\n"+"Rank is "+self.rank+"\n"+"value is "+str(self.value)
            

class Deck:

    def __init__(self):
        self.allCards=[]

        for Suits in suits:
            for Rank in rank:
               self.allCards.append(Card(Suits,Rank))  
      
    def shuffel(self):
        from random import shuffle
        shuffle(self.allCards)

    def DealCard(self):
        return self.allCards.pop()


class Player:

    def __init__(self,name):
        self.CardList=[]
        self.name=name
        

    def HoldNew(self,new_deck):
        check=False
        try:
         ans=input(print("Do you want new card: "))
         while check==False:

                if ans.lower()=="yes":
                    CardNo=int(input(print("How many cards do you want to add: ")))
                    for i in range (CardNo):
                     self.CardList.append(new_deck.DealCard())
                    check=True 

                elif ans.lower()=="no":
                    check=True

                else:
                    print("Enter valid input")

        except:
            print("Enter valid input")

    def Discard(self):
        check=False

        while check==False:
            try:
    
             ans=int(input("How many cards do you want to remove: "))
             if ans>len(self.CardList):
                print("Not enough cards")
             else:
                 for i in range (ans):
                    self.CardList.pop(0)
                 print(str(ans)+" cards removed from hand")
                 check=True       
            except:
                print("Enter valid input")

    def DrawCards(self,IsWar):
        if IsWar==False:
            return self.CardList.pop(0)
        else:
            list=[]
            for i in range (3):
                list.append(self.CardList.pop(0))
                return list


    def ShowCards(self):
        for i in self.CardList:
            print(i)

def GameOn(P1,P2):
    if len(P1.Cardlist)==0:
        print(P2.name+" Has won")
        return False
    if len(P2.CardList)==0:
        print(P1.name+" has won") 
        return False
    else:
        return True


new_deck=Deck()
new_deck.shuffel()
Player1=Player("Aditya")
Player2=Player("Ayush")

for i in range (26):
    Player1.CardList.append(new_deck.DealCard())
for i in range (26):
    Player1.CardList.append(new_deck.DealCard())

while GameOn(Player1,Player2):
    IsWar=False
    c1=Player1.DrawCards(IsWar)
    c2=Player2.DrawCards(IsWar)
    if c1.value==c2.value:
        IsWar=True
        L1=c1.DrawCards(IsWar)
        L2=c2.DrawCards(IsWar)

        for i in range (3):
            if L1[i].value==L2[i].value:
                pass
            elif L1[i].value>L2[i].value:
                print("Player1 wins this round")
                Player1.CardList.extend(L1)
                Player1.CardList.extend(L2)
            else:
                print("Player2 wins this round")
                Player2.CardList.extend(L1)
                Player2.CardList.extend(L2)
        

             


    if c1.value>c2.value:
        print("Player 1 wins this round")
        Player1.CardList.append(c2)
        Player1.CardList.append(c1)

    
