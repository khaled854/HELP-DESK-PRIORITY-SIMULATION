/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: BST.cpp
 * Implementation file for Binary Search Tree
 * Complete all function bodies below
 */

#include "BST.h"

// ========================================
// SECTION 1: نور محمد (Functions 1-7)
// Work on these FIRST, then commit
// ========================================

// Constructor
BST::BST() {
    // TODO:
    // Set root = NULL
    // Set count = 0
}

// Destructor
BST::~BST() {
    // TODO:
    // Call clear() to delete all nodes
}

// Public insert function
bool BST::insert(int requestId, string customerName, string issueType,
                 string assignedAgent, string status, string createdTime) {
    // TODO:
    // 1. Check if requestId already exists using search()
    // 2. If exists, return false
    // 3. Create RequestRecord and fill all fields
    // 4. Set resolvedTime to empty string
    // 5. Call insertHelper(root, record)
    // 6. Update root with returned value
    // 7. Increment count
    // 8. Return true
}

// Private recursive insert helper
BSTNode* BST::insertHelper(BSTNode* node, RequestRecord record) {
    // TODO:
    // 1. If node == NULL:
    //    - Create new BSTNode
    //    - Set data = record
    //    - Set left = NULL, right = NULL
    //    - Return new node
    // 2. If record.requestId < node->data.requestId:
    //    - node->left = insertHelper(node->left, record)
    // 3. Else:
    //    - node->right = insertHelper(node->right, record)
    // 4. Return node
}

// Public search function
BSTNode* BST::search(int requestId) {
    // TODO:
    // Return searchHelper(root, requestId)
}

// Private recursive search helper
BSTNode* BST::searchHelper(BSTNode* node, int requestId) {
    // TODO:
    // 1. If node == NULL or node->data.requestId == requestId:
    //    - Return node
    // 2. If requestId < node->data.requestId:
    //    - Return searchHelper(node->left, requestId)
    // 3. Else:
    //    - Return searchHelper(node->right, requestId)
}

// Public delete function
bool BST::deleteRequest(int requestId) {
    // TODO:
    // 1. If tree is empty, return false
    // 2. If search(requestId) returns NULL, return false
    // 3. root = deleteHelper(root, requestId)
    // 4. Decrement count
    // 5. Return true
}

// Private recursive delete helper
BSTNode* BST::deleteHelper(BSTNode* node, int requestId) {
    // TODO:
    // 1. If node == NULL, return NULL
    // 2. If requestId < node->data.requestId:
    //    - node->left = deleteHelper(node->left, requestId)
    // 3. Else if requestId > node->data.requestId:
    //    - node->right = deleteHelper(node->right, requestId)
    // 4. Else (found the node to delete):
    //    - Case 1: No left child -> return node->right
    //    - Case 2: No right child -> return node->left
    //    - Case 3: Two children:
    //      * Find minimum in right subtree using findMinNode(node->right)
    //      * Copy that node's data to current node
    //      * Delete the minimum node from right subtree
    //      * node->right = deleteHelper(node->right, minNode->data.requestId)
    // 5. Return node
}

// Find minimum node (leftmost)
BSTNode* BST::findMinNode(BSTNode* node) {
    // TODO:
    // 1. If node == NULL, return NULL
    // 2. While node->left != NULL:
    //    - node = node->left
    // 3. Return node
}

// Public inorder traversal
void BST::inorderTraversal() {
    // TODO:
    // 1. Check if tree is empty
    // 2. If empty, display "No requests"
    // 3. Print header
    // 4. Call inorderHelper(root)
}

// Private inorder helper (Left-Root-Right)
void BST::inorderHelper(BSTNode* node) {
    // TODO:
    // 1. If node == NULL, return
    // 2. inorderHelper(node->left)
    // 3. Display node data:
    //    - Request ID
    //    - Customer Name
    //    - Issue Type
    //    - Assigned Agent
    //    - Status
    //    - Created Time
    // 4. inorderHelper(node->right)
}

// Public preorder traversal
void BST::preorderTraversal() {
    // TODO:
    // 1. Check if tree is empty
    // 2. If empty, display "No requests"
    // 3. Print header
    // 4. Call preorderHelper(root)
}

// Private preorder helper (Root-Left-Right)
void BST::preorderHelper(BSTNode* node) {
    // TODO:
    // 1. If node == NULL, return
    // 2. Display node data (same format as inorder)
    // 3. preorderHelper(node->left)
    // 4. preorderHelper(node->right)
}

// Find minimum (public)
BSTNode* BST::findMin() {
    // TODO:
    // Return findMinNode(root)
}

// Find maximum (rightmost)
BSTNode* BST::findMax() {
    // TODO:
    // 1. If root == NULL, return NULL
    // 2. BSTNode* current = root
    // 3. While current->right != NULL:
    //    - current = current->right
    // 4. Return current
}

// Check if empty
bool BST::isEmpty() {
    // TODO:
    // Return true if root == NULL, false otherwise
}

// Get count
int BST::getCount() {
    // TODO:
    // Return count
}

// Update status
bool BST::updateStatus(int requestId, string newStatus) {
    // TODO:
    // 1. Search for request
    // 2. If not found, return false
    // 3. Update node->data.status = newStatus
    // 4. Return true
}

// Update resolved time
bool BST::updateResolvedTime(int requestId, string resolvedTime) {
    // TODO:
    // 1. Search for request
    // 2. If not found, return false
    // 3. Update node->data.resolvedTime = resolvedTime
    // 4. Return true
}

// Clear tree
void BST::clear() {
    // TODO:
    // 1. Call clearHelper(root)
    // 2. Set root = NULL
    // 3. Set count = 0
}

// Private clear helper (postorder deletion)
void BST::clearHelper(BSTNode* node) {
    // TODO:
    // 1. If node == NULL, return
    // 2. clearHelper(node->left)
    // 3. clearHelper(node->right)
    // 4. delete node
}
