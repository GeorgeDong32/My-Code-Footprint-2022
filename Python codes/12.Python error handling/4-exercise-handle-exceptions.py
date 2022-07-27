#!/usr/bin/env python
# coding: utf-8

# # Exercise: Handle exceptions
# 
# With the knowledge of tracebacks and how exceptions are raised and handled, it's time to practice some of these concepts by using this notebook. We'll use a similar scenario where a program must read configuration values. Sometimes there can be errors in how the values are configured, which your program must be able to handle.
# 
# This exercise is broken into a series of steps. For each step you will be presented with the goal for the step, followed by an empty cell. Enter your Python into the cell and run it. The solution for each step will follow each cell.
# 
# ## Loading configuration
# 
# Imagine you are creating a program which will read configuration information from another source, such as a file. Because the contents are stored external to your program, there may be unexpected formatting or other mistakes.
# 
# Run the cell below to simulate loading the configuration information.

# Start by creating a function which opens and reads the contents of the configuration file. Add a parameter to the function named `path` for the path to the configuration file.

# In[ ]:


loaded_config = """# Rocket Ship Configuration File!
fuel_tanks=4
oxygen_tanks=3
initial_propulsion_level=84
$ End of file"""


# ## Parse the configuration information
# 
# For this scenario, you want to load any key/value information. The expected format is `key=value`. In Python you can use `split` to separate text based on a character, such as `split('=')`.
# 
# If you look at `loaded_config`, you will notice not all lines follow this format. As a result, we need to ensure the code gracefully handles any errors. If the character used for `split` isn't found, a `ValueError` is raised.
# 
# In the cell below, add the code to parse `loaded_config`. Start by creating an empty dictionary using `{ }` named `parsed_config` to store the parsed information. Use a `for` loop to split over each line using `split('\n')`. Then use `try` to parse the line as mentioned above (using `split('=')`). If the parse succeeds, store the key/value pair in `loaded_config`. If `ValueError` is raised, display a message saying `Unable to parse: ` and the line with the incorrect format. Finish by displaying `parsed_config`.

# In[ ]:


# Enter code below


# Your code should resemble the following:
# 
# ```python
# parsed_config = {}
# for line in loaded_config.split('\n'):
#     try:
#         key, value = line.split('=')
#         parsed_config[key] = value
#     except ValueError:
#         print(f'Unable to parse {line}')
# print(parsed_config)
# ```
# 
# ## Desired output
# 
# When run, the result should look like the following:
# 
# ```
# Unable to parse # Rocket Ship Configuration File!
# Unable to parse $ End of file
# {'fuel_tanks': '4', 'oxygen_tanks': '3', 'initial_propulsion_level': '84'}
# ```
