def solution(id_list, report_list, kk):
    answer = []
    report_list = list(set(report_list))  # 동일 신고 처리

    report_detail_dict = dict()
    for report in report_list:
        a, b = report.split(' ')
        res = report_detail_dict.get(b)
        if res:
            report_detail_dict[b].append(a)
        else:
            report_detail_dict[b] = [a]
    
    count = dict()
    for ids in id_list:
        count[ids] = 0
        
    for k, v in report_detail_dict.items():
        if len(v) < kk:
            continue
        for vv in v:
            count[vv] += 1
            
        
    for ids in id_list:
        answer.append(count[ids])
        
    return answer