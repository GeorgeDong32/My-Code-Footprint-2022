# Use slices to retrieve portions of a list
planets = ["Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Neptune"]
user_planet = input(
    "Please enter the name of the planet (with a capital letter to start)")
planet_index = planets.index(user_planet)
print("Here are the planets that close to the sun than your select:")
print(planets[0:planet_index])
