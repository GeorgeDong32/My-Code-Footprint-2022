# Python 函数的基本知识
def rocket_parts():
    print("payload, propellant, structure")


rocket_parts()


def rocket_parts():
    return "payload, propellant, structure"


output = rocket_parts()
print(f"output is {output}")
