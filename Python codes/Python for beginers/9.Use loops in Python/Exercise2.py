# # Exercise - Loop over a list
#
# In the previous exercise, you created code to prompt users to enter a list of planet names. In this exercise, you'll complete the application by writing code that displays the planet names one by one.
#
# This exercise is broken into a series of steps. For each step you will be presented with the goal for the step, followed by an empty cell. Enter your Python into the cell and run it. The solution for each step will follow each cell.
#
# The first cell contains the code from the prior exercise, without the `print` statement. Run the cell and provide a list of planets.
# In[1]:
# Run this cell and provide a list of planets
new_planet = ''
planets = []

while new_planet.lower() != 'done':
    if new_planet:
        planets.append(new_planet)
    new_planet = input('Enter a new planet or done if done')


# ## Display the list of planets
#
# The `planets` variable stores the planet names that a user entered. You'll now use a `for` loop to display those entries.
#
# Create a `for` loop to iterate over the `planets` name list. You can use `planet` as the name of the variable for each planet. Inside the `for` loop, use `print` to display each `planet` name.

# In[ ]:
# Enter code below
for planet in planets:
    print(planet)

# Your code should look like this:
#
# ```python
# for planet in planets:
#     print(planet)
# ```
#
# ## Desired output
#
# When you run the notebook you will be presented for a list of planets. After you enter **done** you should see a list of planets on separate lines.
