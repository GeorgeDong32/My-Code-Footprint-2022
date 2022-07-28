'''
print("Hello, Contosoville!")
# This is a comment that won't be interpreted as a command.

# Associate variable town with the value "Contosoville"
town = "Contosoville"

# Print a message about the secret location
print("The town I am looking for is " + town)

# Define a power (function) to chant a phrase


def chant(phrase):
    # Glue three copies together and print it as a message
    print(phrase + phrase + phrase)


# Invoke the power to chant on the phrase "Contosoville!"
chant("Contosoville!")
'''


def lasso_letter(letter, shift_amount):
    letter_code = ord(letter.lower())
    decoded_letter_code = letter_code + shift_amount
    decoded_letter = chr(decoded_letter_code)
    return decoded_letter


print(lasso_letter('a', 2))
print(lasso_letter('N', 13))
