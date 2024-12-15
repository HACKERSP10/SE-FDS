def deposit(balance, amount):
    balance += amount
    print(f"Deposited : Rs. {amount}, New Balance : Rs.{balance}")
    return balance


def withdraw(balance, amount):
    if amount > balance:
        print(f"Insuffucient Balance! Your current balance is {balance}")
    else:
        balance -= amount
        print(f"Withdrew : Rs. {amount}, Current balance : Rs.{balance}")
    return balance


balance = 0
transaction_log = input("Enter the transaction log ").split(" , ")

for transaction in transaction_log:
    action, amount_str = transaction.split()
    amount = int(amount_str)

    if action == "D":
        balance = deposit(balance, amount)
    elif action =="W":
        balance = withdraw(balance, amount)
    else:
        print("Invalid Action. Please try again")

print(f"Final Balance = {balance}")

