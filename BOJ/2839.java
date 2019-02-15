import java.util.*;

class Main {

    public static void main(String[] args) {

        int n, result = 0;

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        while(n > 0) {
            if(n%5 == 0) {
                n -= 5;
                result++;
            }
            else if(n%3 == 0) {
                n -= 3;
                result++;
            }
            else if(n > 5) {
                n -= 5;
                result++;
            }
            else {
                result = -1;
                break;
            }
        }

        System.out.println(result);
    }
}