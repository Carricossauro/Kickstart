def addSession(schedule, N):
    maxInterval = -1
    maxI = -1
    for i in range(N-1):
        dif = schedule[i+1] - schedule[i]
        if dif > maxInterval and dif > 1:
            maxInterval = dif
            maxI = i
    if maxInterval == -1:
        schedule.append(schedule[-1] + 1)
    else:
        minToAdd = schedule[maxI] + maxInterval//2
        schedule.insert(maxI+1, minToAdd)
    return schedule

def main():
    T = int(input())
    for case in range(1, T+1):
        [N, K] = map(int, input().split())
        schedule = list(map(int,input().split()))
        for _ in range(K):
            schedule = addSession(schedule, N)
            N+=1

        maxDif = -1
        for i in range(N-1):
            dif = schedule[i+1] - schedule[i]
            if dif > maxDif:
                maxDif = dif
        print("Case #{}: {}".format(case, maxDif))

main()