class Solution {
    static int ans;
    public static int findLargestSubtreeSum(Node root) {
        // code here
        ans=Integer.MIN_VALUE;
        fun(root);
        return ans;
    }
    public static int fun(Node root)
    {
        if(root==null)return 0;
        int p1=fun(root.left);
        int p2=fun(root.right);
        ans=Math.max(ans,root.data+p1+p2);
        return root.data+p1+p2;
    }
}
