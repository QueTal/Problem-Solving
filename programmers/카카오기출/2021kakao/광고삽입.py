def convert(time):
    h, m, s = time.split(":")
    return int(h) * 3600 + int(m) * 60 + int(s)

def solution(play_time, adv_time, logs):
    answer = ''
    play_sec = convert(play_time)
    adv_sec = convert(adv_time)
    
    total = [0 for _ in range(0, play_sec + 1)]
    
    for log in logs:
        start, end = log.split("-")
        start = convert(start)
        end = convert(end)
        total[start] += 1
        total[end] -= 1
    
    for i in range(1, play_sec):
        total[i] += total[i-1]
    
    cs = sum(total[:adv_sec])
    ms = cs
    mi = 0
    for i in range(adv_sec, play_sec):
        cs = cs + total[i] - total[i-adv_sec]
        if cs > ms:
            mi = i - adv_sec + 1
            ms = cs
    return '%02d:%02d:%02d' % (mi // 3600, mi//60%60, mi%60)