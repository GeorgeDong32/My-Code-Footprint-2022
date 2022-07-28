# # Calculating values
# 
# In this scenario, you will calculate both the total number of moons in the solar system and the average number of moons a planet has. You will do this by using a dictionary object.
# 
# This exercise is broken into a series of steps. For each step you will be presented with the goal for the step, followed by an empty cell. Enter your Python into the cell and run it. The solution for each step will follow each cell.
# 
# Start by creating a variable named `planet_moons` as a dictionary with the following key/values:
# 
# ```
# mercury: 0,
# venus: 0,
# earth: 1,
# mars: 2,
# jupiter: 79,
# saturn: 82,
# uranus: 27,
# neptune: 14,
# pluto: 5,
# haumea: 2,
# makemake: 1,
# eris: 1
# ```

# In[ ]:


# Enter the code below
planet_moons = {
    'mercury': 0,
    'venus': 0,
    'earth': 1,
    'mars': 2,
    'jupiter': 79,
    'saturn': 82,
    'uranus': 27,
    'neptune': 14,
    'pluto': 5,
    'haumea': 2,
    'makemake': 1,
    'eris': 1
}

# Your code should look like the following:
# 
# ```python
# planet_moons = {
#     'mercury': 0,
#     'venus': 0,
#     'earth': 1,
#     'mars': 2,
#     'jupiter': 79,
#     'saturn': 82,
#     'uranus': 27,
#     'neptune': 14,
#     'pluto': 5,
#     'haumea': 2,
#     'makemake': 1,
#     'eris': 1
# }
# ```

# ## Obtain a list of moons and number of planets
# 
# Python dictionaries allow you to retrieve all the values and keys by using the `values` and `keys` methods, respectively. Each method returns a list containing the data, which can then be used like a regular Python list. You can determine the number of items by using `len`, and iterate through it by using `for` loops. In the dictionary you created, the planet names are keys and the number of moons are the values.
# 
# Start by retrieving a list with the number of moons, and store this in a variable named `moons`. Then obtain the total number of planets and store that value in a variable named `total_planets`.

# In[ ]:


# Enter code below
moons = planet_moons.values()
total_planets = len(planet_moons.keys())

# Your code should look like the following:
# 
# ```python
# moons = planet_moons.values()
# total_planets = len(planet_moons.keys())
# ```

# ## Determine the average number of moons
# 
# You will finish this exercise by determining the average number of moons. Start by creating a variable named `total_moons`; this will be your counter for the total number of moons. Then add a `for` loop to loop through the list of `moons`, adding each value to `total_moons`. Finally, calculate the average by dividing `total_moons` by `total_planets` and displaying the value.

# In[ ]:


# Enter code below
total_moons = 0
for moon in moons:
    total_moons = total_moons + moon

average = total_moons / total_planets

print(f'Each planet as an average of {average} moons')

# Your code should look like the following:
# 
# ```python
# total_moons = 0
# for moon in moons:
#     total_moons = total_moons + moon
# 
# average = total_moons / total_planets
# 
# print(f'Each planet as an average of {average} moons')
# ````
# 
# ## Desired output
# 
# When you run the notebook you should see the following result:
# 
# ```
# Each planet as an average of 17.833333333333332 moons
# ```
