import java.util.*;

public class Main {

    static int T, n, next, cnt;
    static int[] s = new int[100000];
    static boolean[] visited = new boolean[100000];
    static boolean[] finished = new boolean[100000];

    static void dfs(int curr) {
        visited[curr] = true;
        next = s[curr];
        if(visited[next]) {
            if(!finished[next]) { // 현재 정점과 next가 하나의 싸이클에 속함
                for(int temp=next; temp!=curr; temp=s[temp]) cnt++;
                cnt++; // 자기자신
            }
        }
        // 이미 모든 탐색이 끝난 정점
        else dfs(next);
        finished[curr] = true;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        T = scanner.nextInt();

        while(T-- != 0) {
            n = scanner.nextInt(); // 학생의 수
            for(int i=0; i<n; i++) {
                s[i] = scanner.nextInt();
                s[i]--; // 0부터 시작하게 맞춰줌
            }
            for(int i=0; i<n; i++) {
                visited[i] = false;
                finished[i] = false;
            }
            cnt = 0;
            for(int i=0; i<n; i++) {
                if(!visited[i]) dfs(i);
            }
            System.out.println(n-cnt);
        }
    }
}