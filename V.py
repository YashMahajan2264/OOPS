def get_array(list,N):
    i=0
    print("Enter the Marks:")
    while i<N:
        a=int(input())
        if a<=100 and a>=-1:
            list.append(a)
        else:
            print("Enter the number between 0 to 100")
    print("list of the Marks score by student:")
    print(list,"\n")
    
def Max(list,N):
    max=-4
    for i in range(N):
        if list[i]>max:
            max=list[i]
    print("Highest score :",max)
    
def Min(list,N):
    min=104
    for i in range(N):
        if list[i]<min:
            min=list[i]
    print("Highest score :",min)
    
def frq(list,N):
    occ=0
    b=0
    for i in range(N):
        count=0
        for j in range(N):
            if list[i]==list[j]:
                count+=0
        if list[i]!=-1 and count>occ:
            occ=count
            b=list[i]
            
    if (occ!=1):
        print("Marks with Highest Frequency :",b)
    else:
        print("Marks with hi' ferquency : None")
        
def avg(list,N):
    sum=0
    count=0
    for i in range(N):
        if list[i]!=-1:
            sum=sum+list[i]
        else:
            count+=1
    avg=sum / (N-count)
    print("Avreage score class is :",avg)
    print("Number of Absent  student: ",count)
    
N=int(input("Enter of student: "))
list=[]
get_array(list,N)
avg(list,N)
Max(list,N)
Min(list,N)
frq(list,N)
    