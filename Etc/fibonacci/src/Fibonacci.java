import java.util.ArrayList;
import java.util.Scanner;

public class Fibonacci {

    static ArrayList<Integer> call = new ArrayList<>();

    int fibonacci(int n) {
        call.set(n, call.get(n) + 1);
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fibonacci(n - 2) + fibonacci(n - 1);
    }

    public static void main(String[] args) {
        Fibonacci fibonacci = new Fibonacci();
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.close();

        while (call.size() < N + 1) {
            call.add(0);
        }
        System.out.println(fibonacci.fibonacci(N));
        System.out.println("호출 횟수");
        for(int i = 0; i <= N; i++) {
            System.out.printf("F(%d): %d회 호출\n", i, call.indexOf(i));
        }
    }
}