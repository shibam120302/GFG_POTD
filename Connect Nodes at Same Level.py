class Solution:
    def connect(self, root):
        '''
        :param root: root of the given tree
        :return: none, just connect accordingly.
        '''
        q = [] # our queue to be used
        q.append(root)
    
        while len(q):
            curr_level_size = len(q) # no of nodes in current level
            for i in range(curr_level_size):
                curr_node = q[0]
                if i != curr_level_size-1:     # if this is not the last node at this level, update its nextRight
                    curr_node.nextRight = q[1]
    
                if curr_node.left:  # put left child in queue
                    q.append(curr_node.left)
                if curr_node.right:  # put right child in queue
                    q.append(curr_node.right)
    
                q.pop(0) # pop from queue

