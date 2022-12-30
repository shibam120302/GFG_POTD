class Count
{
    int count = 0;
}
class Solution
{
    Node root; 
    Count ct = new Count();
    boolean countSingleRec(Node node, Count c)
    {
        // Return false to indicate NULL
        if (node == null)
            return true;
          
        // Recursively count in left and right subtrees also
        boolean left = countSingleRec(node.left, c);
        boolean right = countSingleRec(node.right, c);
  
        // If any of the subtrees is not singly, then this
        // cannot be singly.
        if (left == false || right == false)
            return false;
  
        // If left subtree is singly and non-empty, but data
        // doesn't match
        if (node.left != null && node.data != node.left.data)
            return false;
  
        // Same for right subtree
        if (node.right != null && node.data != node.right.data)
            return false;
  
        // If none of the above conditions is true, then
        // tree rooted under root is single valued, increment
        // count and return true.
        c.count++;
        return true;
    }
    int singlevalued()
    {
        return singlevalued(root);
    }
  
    public int singlevalued(Node root)
    {
        //code here
        countSingleRec(root, ct);
        return ct.count;
    }
}
