# 在 Python 中使用函数参数
def distance_from_earth(destination):
    if destination == "Moon":
        return "238,855"
    else:
        return "Unable to compute to that destination"


print(distance_from_earth("Moon"))
print(distance_from_earth("Saturn"))


def days_to_complete(distance, speed):
    hours = distance/speed
    return hours/24


print(days_to_complete(238855, 75))
print(round(days_to_complete(238855, 75)))
