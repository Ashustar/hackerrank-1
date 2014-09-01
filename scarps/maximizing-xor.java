import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static class Node {
        Node l, r;
        
        public Node() {
            l = r = null;
        }
    };
    
    public static Node root;
    
    static void insert(int val) {
        Node cur = root;
        for (int i = 0; i < 10; ++i) {
            int c = ((val >> (9 - i)) & 1);
            if (c == 0) {
                if (cur.l == null) {
                    cur.l = new Node();
                }
                cur = cur.l;
            } else {
                if (cur.r == null) {
                    cur.r = new Node();
                }
                cur = cur.r;
            }
        }
    }
    
    static int calc(int val) {
        Node cur = root;
        int res = 0;
        for (int i = 0; i < 10; ++i) {
            int c = ((val >> (9 - i)) & 1);
            if (c == 0) {
                if (cur.r == null) {
                    res = (res << 1);
                    cur = cur.l;
                } else {
                    res = (res << 1) + 1;
                    cur = cur.r;
                }
            } else {
                if (cur.l == null) {
                    res = (res << 1);
                    cur = cur.r;
                } else {
                    res = (res << 1) + 1;
                    cur = cur.l;
                }
            }
        }
        return res;
    }
    
    static int maxXor(int l, int r) {
        for (int i = l; i <= r; ++i) {
            insert (i);
        }
        int ans = 0;
        for (int i = l; i <= r; ++i) {
            ans = Math.max(ans, calc(i));
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int res;
        int _l;
        _l = Integer.parseInt(in.nextLine());
        
        int _r;
        _r = Integer.parseInt(in.nextLine());
        
        res = maxXor(_l, _r);
        System.out.println(res);
    }
}
