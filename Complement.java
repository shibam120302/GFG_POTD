class Solve {

    Vector<Integer> findRange(String str, int n) {
        int max_so_far = Integer.MIN_VALUE, max_ending_here = 0, start = 0,
            end = 0, s = 0;
        boolean allOne = true;
        for (int i = 0; i < n; i++) {
            if (str.charAt(i) == '0') allOne = false;
        }
        Vector<Integer> ans = new Vector<Integer>();
        if (allOne) {
            ans.add(-1);
            return ans;
        }

        for (int i = 0; i < n; i++) {
            max_ending_here += (str.charAt(i) == '1' ? -1 : 1);

            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }

            if (max_ending_here < 0) {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        ans.add(start + 1);
        ans.add(end + 1);
        return ans;
    }
}
