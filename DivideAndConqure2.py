import math
def dist(p1,p2):
    return math.sqrt(((p2[0]-p1[0])**2)+(p2[1]-p1[1])**2)


def closestpair(x_sorted,y_sorted):

    mid=x_sorted[len(x_sorted)//2]
    x_left=x_sorted[:mid]    
    x_right=x_sorted[mid:]
    y_left=[]
    y_right=[]
    for point in y_sorted:
        if point[0]<=mid:
            y_left.append(point)
        else:
            y_right.append(point)

    (p1_left,p1_right,deltaP1)=closestpair(x_left,y_left)
    (p2_left,p2_right,deltaP2)=closestpair(x_right,y_right)
    if deltaP1<deltaP2:
        (p1,p2,delta)=(p1_left,p1_right,deltaP1)
    else:
        (p1,p2,delta)=(p2_left,p2_right,deltaP2)
    band=[]
    for points in y_sorted:
        if points[0]<mid+delta and points[0]>mid-delta:
            band.append(points)

    for i in range(len(band)):
        for j in range(i+1,min(i+7,len(band))):
            d=dist(band[i],band[j])
            if d<delta:
                (p1,p2,delta)=(band[i],band[j],d)
    return p1,p2,delta

