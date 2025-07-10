f=open("Message.txt",'w')
tpl=('Array','Laxman',342,'\n')
lst={23,24,25,67,445}
msg='Laxman\nDarrling\n dipu'
d={'name':'Dilip','age':25}
f.write(str(tpl))
f.write(str(lst))
f.write(msg)
f.close()
f=open("Message.txt",'r')
f.seek(51,0)
data=f.read()
print(data)
f.close()