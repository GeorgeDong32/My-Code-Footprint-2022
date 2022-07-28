# string format
# %
print("""Both sides of the %s get the same amount of sunlight,
but only one side is seen from %s because
the %s rotates around its own axis when it orbits %s.""" % ("Moon", "Earth", "Moon", "Earth"))
# .format()
mass_percentage = "1 / 6"
print("""You are lighter on the {0}, because on the {0} 
	you would weigh about {1} of your weight on Earth""".format("Moon", mass_percentage))
# f-string
print(
    f"On the Moon, you would weigh about {mass_percentage} of your weight on Earth")
round(100/6, 1)
