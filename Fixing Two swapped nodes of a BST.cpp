class Solution {

  public:
    void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    // This function does inorder traversal to find out the two swapped nodes.
    // It sets three pointers, first, middle and last.  If the swapped nodes are
    // adjacent to each other, then first and middle contain the resultant nodes
    // Else, first and last contain the resultant nodes
    void correctBSTUtil(struct Node* root, struct Node** first,
                        struct Node** middle, struct Node** last,
                        struct Node** prev) {
        if (root) {
            // Recur for the left subtree
            correctBSTUtil(root->left, first, middle, last, prev);

            // If this node is smaller than the previous node, it's violating
            // the BST rule.
            if (*prev && root->data < (*prev)->data) {

                // If this is first violation, mark these two nodes as
                // 'first' and 'middle'
                if (!*first) {
                    *first = *prev;
                    *middle = root;
                }

                // If this is second violation, mark this node as last
                else
                    *last = root;
            }

            // Mark this node as previous
            *prev = root;

            // Recur for the right subtree
            correctBSTUtil(root->right, first, middle, last, prev);
        }
    }

    // A function to fix a given BST where two nodes are swapped.  This
    // function uses correctBSTUtil() to find out two nodes and swaps the
    // nodes to fix the BST
    struct Node* correctBST(struct Node* root) {
        // Initialize pointers needed for correctBSTUtil()
        struct Node* first, *middle, *last, *prev;
        first = middle = last = prev = NULL;

        // Set the poiters to find out two nodes
        correctBSTUtil(root, &first, &middle, &last, &prev);

        // Fix (or correct) the tree
        if (first && last)
            swap(&(first->data), &(last->data));
        else if (first && middle) // Adjacent nodes swapped
            swap(&(first->data), &(middle->data));

        // else nodes have not been swapped, passed tree is really BST.
        return root;
    }
};
