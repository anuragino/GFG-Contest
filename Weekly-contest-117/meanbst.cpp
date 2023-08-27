/*
    Geek has a list of integers and a value key. He is trying to find the mean of 
the element just less than or equal to the given key and
the element just greater than or equal to the given key
If either of them does not exist, take the value as -1. Both the values may even be the same.  
He has recently discovered the concept of Binary Search Tree. He is curious to see if he can use BST to solve this problem. Can you help him?

The mean of two numbers x and y is defined as ceil((x+y)/2).
For example,
if the numbers are 2 and 3 then mean is ceil(5/2) = ceil(2.5) = 3.
Here ceil(x) denotes the smallest integer that is not smaller than x.

Example 1:
Input:
     3
    /  \
   1    5
key = 2
Output: 2
Explaination : 
Here 1 is just less than 2 and3 is just greater than 2. Required mean is (1+3)/2 = 2.

Example 2:
Input:
  2
   \
    5
   /  \
 3     7
key = 5
Output: 5
Explaination : 
Here we take both keys equal to given key i.e 5 , thus mean = (5 + 5)/2 = 5
*/




/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    int min = -1; // To store the value just lesser than or equal to the key
    int max = -1; // To store the value just greater than or equal to the key
    
    // Function to find the element just less than or equal to the given key
    void justLesserthan(Node* root, int target) {
        if (root == NULL)
            return;
        
        if (root->data <= target) {
            min = root->data; // Update min if the current data is valid
            justLesserthan(root->right, target); // Traverse to the right subtree
        } else {
            justLesserthan(root->left, target); // Traverse to the left subtree
        }
    }
    
    // Function to find the element just greater than or equal to the given key
    void justGreaterthan(Node* root, int target) {
        if (root == NULL)
            return;
        
        if (root->data >= target) {
            max = root->data; // Update max if the current data is valid
            justGreaterthan(root->left, target); // Traverse to the left subtree
        } else {
            justGreaterthan(root->right, target); // Traverse to the right subtree
        }
    }
    
    // Function to calculate the mean of the two elements found
    int mean(Node* root, int key) {
        justGreaterthan(root, key); // Find the element just greater than or equal to the key
        justLesserthan(root, key); // Find the element just less than or equal to the key
        
        // Calculate the mean of the two elements using ceiling division
        return (int)ceil((min + max) / 2.0);
    }
};
