'''
    1396. Design Underground System
    https://leetcode.com/problems/design-underground-system/
'''

class UndergroundSystem:

    def __init__(self):
        self.average_list = {}
        self.check_in_list = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.check_in_list[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start_station, time = self.check_in_list[id]
        del self.check_in_list[id]
        travel_time = t - time
        
        if (start_station, stationName) in self.average_list:
            self.average_list[(start_station, stationName)][0] += travel_time
            self.average_list[(start_station, stationName)][1] += 1
        else:
            self.average_list[(start_station, stationName)] = [travel_time, 1]

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        time, cnt = self.average_list[(startStation, endStation)]
        return time / cnt
        