def solution(arrangement):
    answer = 0
    stack = []
    
    for idx, i in enumerate(arrangement):
        if i == "(":
            stack.append(i)

        elif i == ")":
            poped = stack.pop()
            if arrangement[idx-1] == "(": # 레이저인 경우
                answer += len(stack)
            elif arrangement[idx-1] == ")": # 모서리인 경우
                answer += 1
    return answer

    # https://programmers.co.kr/learn/courses/30/lessons/42585