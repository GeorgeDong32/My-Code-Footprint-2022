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
    def __init__(self, w, h):
        self.height = h
        self.__width = w

    def set_side(self, new_side):
        self.__height = new_side
        self.__width = new_side

    @property
    def height(self):
        return self.__height

    @height.setter
    def height(self, new_value):
        if new_value >= 0:
            self.__height = new_value
        else:
            raise Exception("Value must be larger than 0")


square = Square(3, 4)
print(square.height)

print(square.height)
