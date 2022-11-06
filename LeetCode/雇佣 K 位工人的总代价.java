class Solution {
    boolean[] st = new boolean[100010];
    public long totalCost(int[] costs, int k, int candidates) {
        int n = costs.length;
        PriorityQueue<Integer> q1 = new PriorityQueue<>();
        PriorityQueue<Integer> q2 = new PriorityQueue<>();
        for (int i = 0; i < candidates; i++) {
            q1.add(costs[i]);
            st[i] = true;
        }
        for (int i = n - 1; i >= n - candidates; i--) {
            if (!st[i]) q2.add(costs[i]);
            st[i] = true;
        }
        long s = 0;
        int l = candidates-1, r = n - candidates;
        //System.out.println(l+" "+r);
        while (k-- > 0) {
            int a = (int) 1e9, b = (int) 1e9;
            if (!q1.isEmpty()) a = q1.poll();
            if (!q2.isEmpty()) b = q2.poll();
            //System.out.println(a+" "+b);
            if (a <= b) {
                s += a;
                l++;
                if (l<r) {
                    q1.add(costs[l]);
                }
                q2.add(b);
            } else {
                s += b;
                r--;
                if (r>l) {
                    q2.add(costs[r]);
                }
                q1.add(a);
            }
            //System.out.println(s);
        }
        return s;
    }
}
