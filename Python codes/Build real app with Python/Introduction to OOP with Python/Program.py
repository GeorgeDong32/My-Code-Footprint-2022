# # create class
# class Elevator:
#     def __init__(self, starting_floor):
#         self.make = "The elevator company"
#         self.floor = starting_floor


# # To create the object
# elevator = Elevator(1)
# print(elevator.make)  # "The Elevator company"
# print(elevator.floor)  # 1

# test _ & __

class Square:
    def __init__(self):
        self.__height = 2
        self.__width = 2

    def set_side(self, new_side):
        self.__height = new_side
        self.__width = new_side


square = Square()
square.__height = 3  # raises AttributeError
print(square.__height)
print(square.__width)
