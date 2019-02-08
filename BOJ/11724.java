import java.util.*;

public class Main {

    static class Graph {

        int size;
        List<List<Integer>> adj = new ArrayList<>();
        List<Boolean> visited = new ArrayList<>();

        Graph(int n) {
            size = n;

            for(int i=0; i<size; i++) {
                adj.add(new ArrayList<>());
            }
        }

        void addEdge(int u, int v) {
            List<Integer> temp;

            temp = adj.get(u);
            temp.add(v);
            adj.set(u, temp);

            temp = adj.get(v);
            temp.add(u);
            adj.set(v, temp);
        }

        int dfs() {
            int components = 0;
            for(int i=0; i<size; i++) visited.add(false);
            for(int i=0; i<size; i++) {
                if(!visited.get(i)) {
                    dfs(i);
                    components++;
                }
            }
            return components;
        }

        void dfs(int curr) {
            visited.set(curr, true);
            for(int next: adj.get(curr)) {
                if(!visited.get(next))
                    dfs(next);
            }
        }
    }

    public static void main(String[] args) {

        int N, M;
        int u, v;
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();

        Graph g = new Graph(N);

        for(int m=0; m<M; m++) {
            u = scanner.nextInt();
            v = scanner.nextInt();
            g.addEdge(u-1, v-1);
        }
//        for(int i=0; i<=N; i++) {
//            for(int next: g.adj.get(i)) {
//                System.out.print(next);
//            }
//            System.out.print("\n");
//        }

        int components = g.dfs();
        System.out.println(components);
    }
}