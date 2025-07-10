import hashlib

users_db = {}  # Simulated database: {username: {pin_hash: ..., balance: ...}}

def hash_pin(pin):
    return hashlib.sha256(pin.encode()).hexdigest()

def create_account(username, pin):
    users_db[username] = {
        "pin_hash": hash_pin(pin),
        "balance": 0.0
    }

def verify_login(username, pin):
    user = users_db.get(username)
    if user and user["pin_hash"] == hash_pin(pin):
        return True
    return False

def update_pin(username, new_pin):
    users_db[username]["pin_hash"] = hash_pin(new_pin)
