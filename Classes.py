

class slope():

    def __init__(self,corr1,corr2):

        self.x1=corr1[0]
        self.x2=corr2[0]
        self.y1=corr1[1]
        self.y2=corr2[1]

    def find_slope(self):
        self.Slope=(self.y2-self.y1)/(self.x2-self.x1)
        print("The slope is "+str(self.Slope))

obj=slope((3,2),(8,10))
obj.find_slope()