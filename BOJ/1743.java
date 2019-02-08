import java.util.*;

public class Main {

    static int n, m, k;
    static int[][] map = new int[101][101];
    static int nextR, nextC;
    static int[] directionR = {0, 0, 1, -1};
    static int[] directionC = {1, -1, 0, 0};
    static int cnt;
    static int result;

    static int max(int a, int b) {
        return (a>b)? a: b;
    }

    static int dfs(int r, int c) {
        map[r][c] = 0; // 체크한 곳은 0으로 변경

        for(int i=0; i<4; i++) {
            nextR = r + directionR[i];
            nextC = c + directionC[i];

            // 경계선을 넘어갈 경우 cf) n 범위에 조심
            if((nextR < 0 || nextR > n || nextC < 0 || nextC > m)) continue;
            if(map[nextR][nextC] == 1) {
                cnt++;
                dfs(nextR, nextC);
            }

        }
        return cnt;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        k = scanner.nextInt();

        for(int i=0; i<k; i++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            map[r-1][c-1] = 1;
        }

//        // printAll
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                System.out.print(map[i][j]);
//            }
//            System.out.println("");
//        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // 쓰레기가 있는 곳이면 dfs
                if(map[i][j] == 1) {
                    cnt = 1;
                    result = max(result, dfs(i, j));
                }
            }
        }

        System.out.println(result);
    }
}