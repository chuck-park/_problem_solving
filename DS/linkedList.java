import java.util.*;
import java.io.*;

// linkedList
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        List<Integer> list = new ArrayList<>();
        for (int i=0; i < n; i++) {
            String command = scanner.next();

            // push, get, size, count, clear
            if (command.charAt(0) == 'p') {
                int value = scanner.nextInt();
                list.add(value);
            }
            else if (command.charAt(0) == 'g') {
                int idx = scanner.nextInt();
                System.out.println(list.get(idx));
            }
            else if (command.charAt(0) == 's') {
                System.out.println(list.size());
            }
            else if (command.charAt(1) == 'o') {
                int target = scanner.nextInt(), count=0;
                for(int j=0; j<list.size(); j++) {
                    if(list.get(j) == target) {
                        count++;
                    }
                }
                System.out.println(count);
            }
            else if (command.charAt(1) == 'l') {
                list.clear();
            }
        }
    }
}

