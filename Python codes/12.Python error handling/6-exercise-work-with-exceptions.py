#!/usr/bin/env python
# coding: utf-8

# # Exercise: Raise exceptions
# 
# Exceptions allow a few patterns when they're used effectively. In this exercise, you'll ignore certain exceptions and fix problems where exceptions weren't used. Finally, you'll make a multiple-function program work better by handling exceptions and making decisions based on errors.
# 
# This exercise is broken into a series of steps. For each step you will be presented with the goal for the step, followed by an empty cell. Enter your Python into the cell and run it. The solution for each step will follow each cell.
# 
# ## Creating a utility to convert strings to boolean values
# 
# Imagine you are creating a program which will prompt the user for yes or no, which will be converted true or false. Because people will enter different values, you need to ensure the different possibilities are handled correctly. If an unknown response is given, the program should raise an error.
# 
# For purposes of this exercise, you'll use the values below for true and false. Run the cell to load the variables.

# In[ ]:


true_values = ['yes', 'y']
false_values = ['no', 'n']


# ## Create the function to test for true or false
# 
# You will use `true_values` and `false_values` to create a function named `str_to_bool` to convert strings to Boolean values. `str_to_bool` will accept one parameter named `value`.
# 
# Create the function `str_to_bool`. Convert `value` to lower case letters. If `value` matches an entry in `true_values` the function should return `True`. If `value` matches an entry in `false_values` it should return `False`. If it doesn't match any of the values, it should raise a `ValueError`, with a message of **Invalid entry**.

# In[ ]:


# Enter code below


# Your code should resemble the following:
# 
# ```python
# def str_to_bool(value):
#     value = value.lower()
#     if value in true_values:
#         return True
#     elif value in false_values:
#         return False
#     else:
#         raise ValueError('Invalid entry')
# ```
# 
# ## Desired output
# 
# In the cell below, call `str_to_bool` with different values. When you use **y** or **yes** it should display `True`. When you use **n** or **no** it should display `False`. For any other value an error should be raised.

# In[ ]:


# Test function here

