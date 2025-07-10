import auth

def deposit(username, amount):
    auth.users_db[username]["balance"] += amount
    return auth.users_db[username]["balance"]

def withdraw(username, amount):
    if auth.users_db[username]["balance"] >= amount:
        auth.users_db[username]["balance"] -= amount
        return auth.users_db[username]["balance"]
    else:
        raise ValueError("Insufficient funds")

def check_balance(username):
    return auth.users_db[username]["balance"]

def get_interest_rate(amount):
    if amount > 50000:
        return 3
    elif amount > 30000:
        return 2
    return 1.5

def calculate_interest(principal, rate, time):
    import math
    return principal * math.exp(rate * time)
