'''
스테이지의 개수 N은 1 이상 500 이하의 자연수이다.
stages의 길이는 1 이상 200,000 이하이다.
stages에는 1 이상 N + 1 이하의 자연수가 담겨있다.
각 자연수는 사용자가 현재 도전 중인 스테이지의 번호를 나타낸다.
단, N + 1 은 마지막 스테이지(N 번째 스테이지) 까지 클리어 한 사용자를 나타낸다.
만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다.

입출력 예
N	stages	result
5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
4	[4,4,4,4,4]	[4,1,2,3]
'''

# N: 전체 스테이지의 개수
# stages: 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 
def solution(N, stages):
    answer = []
    num_user = len(stages) # 도전한 사용자 수
    stage = [0] * (N+1) # 스테이지에 도달했지만 클리어하지 못한 사용자 수
    num_hitted_user = num_user # 스테이지에 도달한 사용자 수
    failure_rate = [0] * N # 실패율: 스테이지에 도달했으나 아직 클리어하지 못한 사용자 수 / 스테이지에 도달한 사용자 수

    for i in stages:
        stage[i-1] += 1 # 각 스테이지 별 도전 중인 사용자 수 = [1, 3, 2, 1, 0, 1]

    for i in range(N):
        failure_rate[i] = stage[i] / num_hitted_user # [0.125, 0.42857142857142855, 0.5, 0.5, 0]
        # print(failure_rate[i], '=', stage[i], '/', num_hitted_user)
        num_hitted_user -= stage[i] # 다음 스테이지에 도달한 사용자 수

        if(num_hitted_user == 0): # 아무도 이 스테이지 이상 넘어가지 못했으면 
            num_hitted_user = 1 # 분모를 1로 하여 zero devision error를 해결

    # failure_rate list에 순서대로 번호를 부여
    # cf) 번호 순으로 정렬했기 때문에 역순으로 했을 때 같은 실패율이라면 작은 번호의 스테이지가 먼저온다
    temp = 0
    temp = tuple(zip(range(1, N+1), failure_rate)) # [(0, 0.125), (1, 0.42857142857142855), (2, 0.5), (3, 0.5), (4, 0)]
    # zip된 순번과 failure_rate을 순번을 기준으로 정렬
    temp = sorted(temp, key=lambda x: x[1], reverse=True) # [(3, 0.5), (4, 0.5), (2, 0.42857142857142855), (1, 0.125), (5, 0.0)]
    for i in temp:
        answer.append(i[0])

    return answer

# test input
N = 5
stages = [2, 1, 2, 6, 2, 4, 3, 3]

print(solution(N, stages))
