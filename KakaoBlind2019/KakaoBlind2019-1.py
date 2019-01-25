# 1. 오픈 채팅방

def solution(record):
    db_users = {}
    answer = []
    splited_record = []
    for item in record:
        splited_record = item.split(" ")

        if splited_record[0] == "Enter" or splited_record[0] == "Change":
            db_users[splited_record[1]] = splited_record[2]

    for item in record:
        splited_record = item.split(" ")

        if splited_record[0] == "Enter":
            answer.append(db_users[splited_record[1]] + "님이 들어왔습니다.")

        elif splited_record[0] == "Leave":
            answer.append(db_users[splited_record[1]] + "님이 나갔습니다.")

    return answer

input_record = ["Enter uid1234 Muzi","Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
# 출력 예: ["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]

# input_record = ["Enter uid1434 Muzi", "Enter uid4567 Prodo", "Leave uid1434", "Enter uid1234 Prodo", "Change uid4567 Ryan", "Enter uid4067 AAA"]
# 출력 예: ["Muzi님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Muzi님이 나갔습니다.", "Prodo님이 나갔습니다.", "AAA님이 들어왔습니다."]
print("최종 결과: ", solution(input_record))
