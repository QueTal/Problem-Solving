from math import ceil

def time_to_int(time):
    hours, minutes = time.split(':')
    return int(hours)*60 + int(minutes)


def get_fee(inout_list, fee):
    diff = 0
    for inout in inout_list:
        diff += inout[1] - inout[0]
    
    if diff <= fee[0]:
        return fee[1]
    else:
        return fee[1] + ceil((diff-fee[0])/fee[2]) * fee[3]


def solution(fees, records):
    answer = []
    car_inout_dict = dict()
    last = time_to_int('23:59')
    
    for record in records:
        time, car, status = record.split(' ')
        time = time_to_int(time)
        
        if status == 'IN':
            if car not in car_inout_dict.keys():
                car_inout_dict[car] = []
            car_inout_dict[car].append([time, last])
        else: # out
            old = car_inout_dict[car].pop()
            old[1] = time
            car_inout_dict[car].append(old)
            
    car_inout_dict = sorted(car_inout_dict.items())
    for _, value in car_inout_dict:
        answer.append(get_fee(value, fees))
        
    return answer