a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())
temp1 = f - d * c / a
temp2 = e - d * b / a
y = temp1 / temp2
x = (c - b * y) / a
print(x, y)