# Awesome code #
def solution(a, b):
    months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    days = ['FRI', 'SAT', 'SUN', 'MON', 'TUE', 'WED', 'THU']

    answer = days[(sum(months[:a-1])+b-1)%7]
    print(answer)

solution(5, 24)



# my code #
# def solution(a, b):
#     answer = ''
#     day = 0
        
#     month_dic = {1:31, 2:29, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
#     day_dic = {1:'FRI', 2:'SAT', 3:'SUN', 4:'MON', 5:'TUE', 6:'WED', 0:'THU'}

#     for i in range(a):
#         if(i != 0):
#             day = day + month_dic[i]

#     day = day + b
#     print(day)
#     answer = day%7
#     print(answer)
#     answer = day_dic[answer]
#     print(answer)
    

# solution(5, 24)

