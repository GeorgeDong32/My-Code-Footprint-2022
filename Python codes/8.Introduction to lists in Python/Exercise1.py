# Exercise: Use lists to store planet names
planets = ["Mercury", "Venus", "Earth",
           "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"]
print(planets)
# len
print(f"There are {len(planets)} planets in solar system")
# add
planets.append("Pluto")
print("Actually, there are", len(planets), "planets")
print(planets[-1], "is the last planet")
