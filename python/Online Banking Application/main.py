import utils
import auth
import banking

def main():
    print("Welcome to the Online Banking App")
    username = input("Enter your username: ")

    if username not in auth.users_db:
        print("Creating new account")
        pin = utils.get_input("Set a 5-digit PIN: ", utils.is_valid_pin)
        auth.create_account(username, pin)

    for _ in range(3):
        pin = input("Enter your PIN: ")
        if auth.verify_login(username, pin):
            break
        else:
            print("Incorrect PIN.")
    else:
        print("Too many attempts. Exiting.")
        return

    while True:
        print("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Calculate Interest\n5. Change PIN\n6. Exit")
        choice = input("Choose an option: ")

        if choice == '1':
            amount = float(utils.get_input("Enter deposit amount: ", utils.is_valid_amount))
            new_balance = banking.deposit(username, amount)
            print(f"Deposited successfully. New balance: {new_balance}")

        elif choice == '2':
            try:
                amount = float(utils.get_input("Enter withdrawal amount: ", utils.is_valid_amount))
                new_balance = banking.withdraw(username, amount)
                print(f"Withdrawn successfully. New balance: {new_balance}")
            except ValueError as e:
                print(e)

        elif choice == '3':
            print(f"Your balance is: {banking.check_balance(username)}")

        elif choice == '4':
            principal = float(utils.get_input("Enter deposit amount: ", utils.is_valid_amount))
            rate = banking.get_interest_rate(principal) / 100
            time = float(utils.get_input("Enter time in years: ", lambda x: float(x) > 0))
            interest = banking.calculate_interest(principal, rate, time)
            print(f"Future amount after interest: {interest:.2f}")

        elif choice == '5':
            new_pin = utils.get_input("Enter new 5-digit PIN: ", utils.is_valid_pin)
            auth.update_pin(username, new_pin)
            print("PIN updated successfully.")

        elif choice == '6':
            print("Goodbye!")
            break

        else:
            print("Invalid option. Try again.")

if __name__ == "__main__":
    main()
