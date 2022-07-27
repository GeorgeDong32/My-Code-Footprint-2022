# 使用字典进行动态编程
# 检索所有键和值
rainfall = {
    'october': 3.5,
    'november': 4.2,
    'december': 2.1
}
for key in rainfall.keys():
    print(f'{key}: {rainfall[key]}cm')
# Output:
# october: 3.5cm
# november: 4.2cm
# december: 2.1cm

# 确定字典中是否存在某个键
if 'december' in rainfall:
    rainfall['december'] = rainfall['december'] + 1
else:
    rainfall['december'] = 1
# Because december exists, the value will be 3.1
for key in rainfall.keys():
    print(f'{key}: {rainfall[key]}cm')

# 检索所有值
total_rainfall = 0
for value in rainfall.values():
    total_rainfall = total_rainfall + value

print(f'There was {total_rainfall}cm in the last quarter')
# Output:
# There was 10.8cm in the last quarter