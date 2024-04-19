def is_positive(num):
    if num > 0:
        return True
    else:
        return False

def factorial(n):
    if n < 2:
        return 1
    else:
        return n*factorial(n-1)

print(is_positive(7))
print(is_positive(-1))

print(factorial(4))
print(factorial(5))
