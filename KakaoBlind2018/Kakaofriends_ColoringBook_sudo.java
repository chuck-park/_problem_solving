class Solution {
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        int currentColor = picture[0][0]; // 사진의 첫번째 색깔
        int nextColor = picture[0][1];
        int maxSizeOfThisArea = 0; // maxSizeOfOneArea와 비교를 위한 임시변수

        // 처음부터 쭉 지나가다가
        for(int low=0; low < m; low++) {
            for(int col=0; col < n; col++) {
                if(low == 0) {
                    if(col == 0) { // 좌상 모서리
//                        System.out.println("["+low+"]"+"["+col+"]" + picture[low][col]);
                    } else if(col == n-1){ // 우상 모서리
//                        System.out.println("["+low+"]"+"["+col+"]" + picture[low][col]);
                    } else { // 위쪽 사이드
//                        System.out.println("["+low+"]"+"["+col+"]" + picture[low][col]);
                    }
                } else if(low == m-1) {
                    if(col == 0) { // 좌하 모서리
//                        System.out.println("["+low+"]"+"["+col+"]" + picture[low][col]);
                    } else if(col == n-1) { // 우하 모서리
//                        System.out.println("["+low+"]"+"["+col+"]" + picture[low][col]);
                    } else { // 아래쪽 사이드
//                        System.out.println("["+low+"]"+"["+col+"]" + picture[low][col]);
                    }
                } else if(col == 0 && low != 0 && low != m-1) { // 왼쪽 사이드
//                    System.out.println("["+low+"]"+"["+col+"]" + picture[low][col]);

                } else if(col == n-1 && low != 0 && low != m-1) { // 오른쪽 사이드
//                    System.out.println("["+low+"]"+"["+col+"]" + picture[low][col]);
                } else {
//                    System.out.println("["+low+"]"+"["+col+"]" + "모서리 or 사이드 아님");

                }
//                else if(currentColor != nextColor) { // 다른 색깔을 만나면 상하 좌우를 살펴본다(모서리가 아닌 경우)
//                    System.out.println(picture[low][col]);
//                }

                currentColor = nextColor;
                nextColor = picture[low][col];
            }
        }

//        if(lastColor != currentColor) { // 다른 색깔을 만나면 상하 좌우를 살펴본다(모서리가 아닌 경우)
//            if(currentColor == picture[i][j+1]) { // 상하좌우 살펴보기
//                // 그 색을 기준으로 계속 상하좌우 탐색(재귀 사용)
//                maxSizeOfthisArea +1 // 상하좌우 중에 같은 색을 만나면
//            } else if(같은 색이다가 한 영역이 끝나면) {
//                numberOfArea +1
//            }
//            else if(상하좌우가 다 다른색이면(점이면)) {
//                numberOfArea +1
//            }
//            // 더 이상 같은 색이 없으면 maxSizeOfThisArea 갱신
//            maxSizeOfOneArea < maxSizeOfThisArea ? maxSizeOfThisArea : maxSizeOfOneArea
//        }


        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[][] picture = {
                {1, 1, 1, 0},
                {1, 2, 2, 0},
                {1, 0, 0, 1},
                {0, 0, 0, 1},
                {0, 0, 0, 3},
                {0, 0, 0, 3}
        };
        solution.solution(6, 4, picture); // [4, 5]
    }
}

