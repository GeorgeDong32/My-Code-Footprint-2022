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


# Define a function to find the truth by shifting the letter by the specified amount
def lasso_letter(letter, shift_amount):
    # Invoke the ord function to translate the letter to its ASCII code
    # Save the code to the letter_code variable
    letter_code = ord(letter.lower())

    # The ASCII number representation of lowercase letter 'a'
    a_ascii = ord('a')

    # The number of letters in the alphabet
    alphabet_size = 26

    # The formula to calculate the ASCII number for the decoded letter
    # Take into account looping around the alphabet
    true_letter_code = a_ascii + \
        (((letter_code - a_ascii) + shift_amount) % alphabet_size)

    # Convert the ASCII number to the character or letter
    decoded_letter = chr(true_letter_code)

    # Send the decoded letter back
    return decoded_letter


print(lasso_letter('a', 2))
print(lasso_letter('N', 13))
