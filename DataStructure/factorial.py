def factorial(num):
    if num == 0:
        return 1
    else:
        return num * factorial(num-1)


if __name__ == '__main__':
    for i in range(1,11):
        print '%d! = %d' % (i, factorial(i))
