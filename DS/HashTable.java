import java.util.LinkedList;

class HashTable {
    class Node {
        String key;
        String value;

        public Node(String key, String value) {
            this.key = key;
            this.value = value;
        }

        String value() {
            return value;
        }

        void value(String value) {
            this.value = value;
        }
    }

    LinkedList<Node>[] data;

    HashTable(int size) {
        data = new LinkedList[size];
    }

    int getHashCode(String key) {
        int hashcode = 0;
        for (char c : key.toCharArray()) {
            hashcode += c;
        }
        return hashcode;
    }

    int convertToIndex(int hashcode) {
        return hashcode % data.length;
    }

    // index로 배열을 찾은 후, 배열에 노드가 여러개 존재하는 경우 key를 이용해서 해당 노드를 찾아오는 함수
    Node searchKey(LinkedList<Node> list, String key) {
        if (list == null) return null;
        for (Node n : list) {
            if (n.key.equals(key)) {
                return n;
            }
        }
        return null;
    }

    // 데이터를 받아서 저장하는 함수
    void put(String key, String value) {
        int hashcode = getHashCode(key);
        int index = convertToIndex(hashcode);
        System.out.println(key + ", hashcode(" + hashcode + "), index(" + index + ")");
        LinkedList<Node> list = data[index];
        // 특정 index의 리스트가 null이면
        if (list == null) {
            list = new LinkedList<Node>();
            data[index] = list;
        }
        Node node = searchKey(list, key);
        // 특정 list의 node가 null이면
        if (node == null) {
            list.addLast(new Node(key, value));
        } else {
            node.value(value);
        }
    }

    // key를 가지고 데이터를 가져오는 함수
    String get(String key) {
        int hashcode = getHashCode(key);
        int index = convertToIndex(hashcode);
        LinkedList<Node> list = data[index];
        Node node = searchKey(list, key);
        return node == null ? "Not found" : node.value();
    }
}

public class Test {
    public static void main(String[] args) {
        HashTable h = new HashTable(3);

        h.put("Chuck", "he is pretty");
        h.put("Song", "she is a beautiful");
        h.put("Kim", "he is an nice");
        h.put("Derick", "he is warm");
        h.put("Rachel", "she is friendly");
        System.out.println(h.get("Chuck"));
        System.out.println(h.get("Song"));
        System.out.println(h.get("Kim"));
        System.out.println(h.get("Derick"));
        System.out.println(h.get("Rachel"));
        System.out.println(h.get("John"));
    }
}
