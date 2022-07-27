# python 字典
planet = {
    'name': 'Earth',
    'moons': 1
}

# get
print(planet.get('name'))
# Displays Earth

# planet['name'] is identical to using planet.get('name')
print(planet['name'])
# Displays Earth

# update
# Using update
planet.update({
    'name': 'Jupiter',
    'moons': 79
})
print(planet['name'])
print(planet['moons'])

# Using square brackets
planet['name'] = 'Jupiter'
planet['moons'] = 79
print(planet['name'])
print(planet['moons'])
