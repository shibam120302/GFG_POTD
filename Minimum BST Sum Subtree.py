class Solution:
    def minSubtreeSumBST(self, target, root):
        res = float(inf)
        def traverse(node):
            nonlocal res
            if not node:
                return float(inf), float(-inf), 0, 0
            left = traverse(node.left)
            right = traverse(node.right)
            if not left or not right:
                return
            leftMin, leftMax, leftSum, leftSumNode = left[0], left[1], left[2], left[3]
            rightMin, rightMax, rightSum, rightSumNode = right[0], right[1], right[2], right[3]
            if node.data > leftMax and node.data < rightMin:
                nodeMax = max(rightMax,node.data)
                nodeMin = min(leftMin, node.data)
                nodeSum = leftSum + rightSum + node.data
                if nodeSum == target:
                    res = min(res, leftSumNode + rightSumNode + 1)
                return nodeMin, nodeMax, nodeSum, leftSumNode + rightSumNode + 1
        traverse(root)
        return res if res != float(inf) else -1
