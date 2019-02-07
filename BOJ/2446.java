import java.util.*;

public class Main {

    public static void main(String[] args) {

        int n;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        for(int i=n; i>=1; i--) {
            // (i != 1)일 때만 *을 찍는다
            if(i != 1) {
                for(int j=0; j<Math.abs(i-n); j++) {
                    System.out.print(" ");
                }
                for(int j=i*2-1; j>0; j--) {
                    System.out.print("*");
                }
                System.out.print("\n");
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=0; j<Math.abs(i-n); j++) {
                System.out.print(" ");
            }
            for(int j=i*2-1; j>0; j--) {
                System.out.print("*");
            }
            System.out.print("\n");
        }
    }
}