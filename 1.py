n = int(input())

for i in range(n):
    x = input()
    yek=0
    sef=0
    slesn=0
    javab=0
    vmin='0'
    for j in range(len(x)):
        if x[j]=='1':
            yek+=1
        else:
            sef+=1
    slen=2*min(yek,sef)
    javab+=len(x)-slen
    if javab==0:
        print(0)
        continue
    if sef<yek:
        vmin='0'
    else:
        vmin='1'
    for k in range(slen,len(x)):
        if x[k]==vmin:
            javab+=1
    print(javab)
        
