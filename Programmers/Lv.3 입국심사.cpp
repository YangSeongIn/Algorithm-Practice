def solution(n, times):
    answer = 0
    times.sort()
    end = times[-1] * n
    start = times[0]
    while start <= end:
        mid = (start + end) // 2
        total = 0
        for i in times:
            total += mid // i
            if total >= n:
                break

        if total < n:
            start = mid + 1
        else:
            answer = mid
            end = mid - 1
    return answer
