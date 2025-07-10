def get_input(prompt, validator=None):
    while True:
        value = input(prompt)
        if validator is None or validator(value):
            return value
        print("Invalid input. Please try again.")

def is_valid_pin(pin):
    return pin.isdigit() and len(pin) == 5

def is_valid_amount(amount):
    try:
        return float(amount) > 0
    except ValueError:
        return False
