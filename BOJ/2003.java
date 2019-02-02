import java.io.*;
import java.util.*;

/*
N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 이 수열의 i번째 수부터 j번째 수까지의 합
A[i]+A[i+1]+…+A[j-1]+A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 N(1≤N≤10,000), M(1≤M≤300,000,000)이 주어진다.
다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다.
각각의 A[x]는 30,000을 넘지 않는 자연수이다.
 */

public class Main {

    static int n,m,data[] = new int[10001];
    static int right, sum, cnt;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++) {
            data[i] = Integer.parseInt(st.nextToken());
        }

        for(int i=1; i<=n; i++) {
            while(right<n && sum<m) sum += data[++right];

            // i ~ right의 합이 m이면 cnt++
            if(sum == m) cnt++;

            // i ~ right의 합 -> i+1 ~ right의 합
            sum -= data[i];
        }
        System.out.println(cnt);
    }
}
