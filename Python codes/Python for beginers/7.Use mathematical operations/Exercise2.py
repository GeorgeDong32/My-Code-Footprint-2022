# Create an application to work with numbers and user input
first_planet_input = input(
    'Enter the distance from the sun for the first planet in KM')
second_planet_input = input(
    'Enter the distance from the sun for the second planet in KM')
# Convert
first_planet = int(first_planet_input)
second_planet = int(second_planet_input)
# result
distance_km = second_planet - first_planet
print(abs(distance_km))
