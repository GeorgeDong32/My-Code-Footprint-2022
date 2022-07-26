# 关于“while”循环
user_input = ''

while user_input.lower() != 'done':
    user_input = input('Enter a new value, or done when done')

# Create the variable for user input
user_input = ''
# Create the list to store the values
inputs = []

# The while loop
while user_input.lower() != 'done':
    # Check if there's a value in user_input
    if user_input:
        # Store the value in the list
        inputs.append(user_input)
    # Prompt for a new value
    user_input = input('Enter a new value, or done when done')

print(inputs)
