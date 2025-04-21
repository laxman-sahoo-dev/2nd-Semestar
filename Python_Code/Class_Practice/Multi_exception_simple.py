class MyException(Exception):
    def __init__(self, arg):
        self.arg = arg
def check(bank):
    for key, value in bank.items():
        print("Name={}, Balance={}".format(key, value))
        if value < 2000:
            raise MyException("Balance amount is less than 2000")

bank = {'abc': 5000, 'xyz': 3000, 'pqr': 1800}

try:
    check(bank)
except MyException as me:
    print("Custom Exception:", me)
