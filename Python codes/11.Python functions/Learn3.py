# 在 Python 中使用关键字参数
from datetime import timedelta, datetime


def arrival_time(hours=51):
    now = datetime.now()
    arrival = now + timedelta(hours=hours)
    return arrival.strftime("Arrival: %A %H:%M")
