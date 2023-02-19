class Solution:
    # Utility function to track the nodes
    # that we have to swap
    def correctBSTUtil(self, root, first, middle,
                       last, prev):
                             
        if(root):
              
            # Recur for the left sub tree
            self.correctBSTUtil(root.left, first,
                           middle, last, prev)
                             
            # If this is the first violation, mark these 
            # two nodes as 'first and 'middle'
            if(prev[0] and root.data < prev[0].data):
                if(not first[0]):
                    first[0] = prev[0]
                    middle[0] = root
                else:
                      
                    # If this is the second violation,
                    # mark this node as last
                    last[0] = root
                      
            prev[0] = root
              
            # Recur for the right subtree
            self.correctBSTUtil(root.right, first, 
                           middle, last, prev)
          
    # A function to fix a given BST where 
    # two nodes are swapped. This function
    # uses correctBSTUtil() to find out two
    # nodes and swaps the nodes to fix the BST 
    def correctBST(self, root):
          
        # Followed four lines just for forming
        # an array with only index 0 filled 
        # with None and we will update it accordingly.
        # we made it null so that we can fill 
        # node data in them.
        first = [None]
        middle = [None]
        last = [None]
        prev = [None]
          
        # Setting arrays (having zero index only) 
        # for capturing the requird node
        self.correctBSTUtil(root, first, middle,
                       last, prev)
      
        # Fixing the two nodes
        if(first[0] and last[0]):
              
            # Swapping for first and last key values
            first[0].data, last[0].data = (last[0].data, 
                                        first[0].data)
      
        elif(first[0] and middle[0]):
          
            # Swapping for first and middle key values
            first[0].data, middle[0].data = (middle[0].data,
                                            first[0].data)
          
        # else tree will be fine 
        return root
