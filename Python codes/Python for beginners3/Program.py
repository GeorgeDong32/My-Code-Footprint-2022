# program.py
from datetime import date
sum = 1 + 2
print(sum)
product = sum * 2
print("show this in the console")
print(product)
# data type
planets_in_solar_system = 8  #  int, pluto used to be the 9th planet, but is too small
distance_to_alpha_centauri = 4.367  #  float, lightyears
can_liftoff = True
shuttle_landed_on_the_moon = "Apollo 11"  # string
# date
print(date.today())
# Convert
print("Today's date is: " + str(date.today()))

# input
print("Welcome to the greeter program")
name = input("Enter your name ")
print("Greetings: " + name)

# input number
print("calculator program")
first_number = input("first number: ")
second_number = input("second number: ")
print(first_number + second_number)
print(int(first_number) + int(second_number))
