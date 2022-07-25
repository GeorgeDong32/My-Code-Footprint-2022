# String in python
# value of string
'''
>> > fact = "The Moon has no atmosphere."
>> > two_facts = fact + "No sound can be heard on the Moon."
>> > two_facts
'The Moon has no atmosphere.No sound can be heard on the Moon.'
'''
# multiline string
'''
multiline = "Facts about the Moon:\n There is no atmosphere.\n There is no sound."
print(multiline)
multiline = """Facts about the Moon:
...  There is no atmosphere.
...  There is no sound."""
print(multiline)
'''
# String method
"temperatures and facts about the moon".title()
mars_temperature = "The highest temperature on Mars is about 30 C"
for item in mars_temperature.split():
    if item.isnumeric():
        print(item)
