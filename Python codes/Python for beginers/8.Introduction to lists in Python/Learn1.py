# python list
# create

planets = ["Mercury", "Venus", "Earth", "Mars",
           "Jupiter", "Saturn", "Uranus", "Neptune"]
print("The first planet is", planets[0])
print("The second planet is", planets[1])
print("The third planet is", planets[2])
# Output
# The first planet is Mercury
# The second planet is Venus
# The third planet is Earth

planets[3] = "Red Planet"
print("Mars is also known as", planets[3])
# Output
# Mars is also known as Red Planet


# method

number_of_planets = len(planets)
print("There are", number_of_planets, "planets in the solar system.")
# Output:
# There are 8 planets in the solar system

planets.append("Pluto")
number_of_planets = len(planets)
print("There are actually", number_of_planets, "planets in the solar system.")
# Output:
# There are actually 9 planets in the solar system.

planets.pop()  # Goodbye, Pluto
number_of_planets = len(planets)
print("No, there are definitely", number_of_planets,
      "planets in the solar system.")

print("The first planet is", planets[0])
# Output:
# The first planet is Mercury

print("The last planet is", planets[-1])
print("The penultimate planet is", planets[-2])
# Output
# The last planet is Neptune
# The penultimate planet is Uranus

jupiter_index = planets.index("Jupiter")
print("Jupiter is the", jupiter_index + 1, "planet from the sun")
# Output
# Jupiter is the 5 planet from the sun
