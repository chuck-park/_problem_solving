import java.io.*;
import java.util.*;

public class Main {

    static int N, map[][] = new int[26][26];

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        for(int i=0; i<N; i++) {
            String str = br.readLine();

            for(int j=0; j<N; j++) {
                map[i][j] = str.charAt(j) - '0';
            }
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.print("\n");
        }
    }
}
