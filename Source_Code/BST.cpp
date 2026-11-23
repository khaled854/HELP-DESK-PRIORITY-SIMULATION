/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: BST.cpp
 * Implementation: Binary Search Tree data structure
 * 
 * SKELETON VERSION - Function bodies are intentionally empty
 * Team members will implement their assigned functions
 */

#include "BST.h"

// ========================================
// SECTION 1: نور محمد (Functions 1-7)
// ========================================

/*
 * Constructor
 * Owner: Nour Mohamed
 * Purpose: Initialize empty BST
 */
BST::BST() {
    // TODO: Implemented by Nour Mohamed
    // Initialize root to NULL, count to 0
}

/*
 * Function: insert (public)
 * Owner: Nour Mohamed
 * Purpose: Add new request to BST
 */
bool BST::insert(int requestId, string customerName, string issueType,
                 string assignedAgent, string status, string createdTime) {
    // TODO: Implemented by Nour Mohamed
    // 1. Create RequestRecord
    // 2. Call insertHelper with root
    // 3. Update root and count
    // 4. Return true if inserted
    return false;  // Placeholder
}

/*
 * Function: insertHelper (private recursive)
 * Owner: Nour Mohamed
 * Purpose: Recursive insert helper
 * NOTE: Core BST insertion algorithm
 */
BSTNode* BST::insertHelper(BSTNode* node, RequestRecord record) {
    // TODO: Implemented by Nour Mohamed
    // 1. If node is NULL, create new node
    // 2. If record.requestId < node->data.requestId, go left
    // 3. If record.requestId > node->data.requestId, go right
    // 4. If equal, duplicate - return node
    // 5. Return node
    return NULL;  // Placeholder
}

/*
 * Function: search (public)
 * Owner: Nour Mohamed
 * Purpose: Find request by ID
 */
BSTNode* BST::search(int requestId) {
    // TODO: Implemented by Nour Mohamed
    // Call searchHelper with root
    return NULL;  // Placeholder
}

/*
 * Function: searchHelper (private recursive)
 * Owner: Nour Mohamed
 * Purpose: Recursive search helper
 * NOTE: O(log n) average case
 */
BSTNode* BST::searchHelper(BSTNode* node, int requestId) {
    // TODO: Implemented by Nour Mohamed
    // 1. If node is NULL, not found
    // 2. If requestId == node->data.requestId, found
    // 3. If requestId < node->data.requestId, go left
    // 4. If requestId > node->data.requestId, go right
    return NULL;  // Placeholder
}

/*
 * Function: isEmpty
 * Owner: Nour Mohamed
 * Purpose: Check if BST is empty
 */
bool BST::isEmpty() {
    // TODO: Implemented by Nour Mohamed
    // Return true if root == NULL
    return true;  // Placeholder
}

/*
 * Function: getCount
 * Owner: Nour Mohamed
 * Purpose: Get total number of requests
 */
int BST::getCount() {
    // TODO: Implemented by Nour Mohamed
    // Return count
    return 0;  // Placeholder
}

// ========================================
// SECTION 2: هبه رجب (Functions 8-14)
// ========================================

/*
 * Destructor
 * Owner: Heba Ragab
 * Purpose: Delete all nodes and free memory
 * NOTE: CRITICAL - Must prevent memory leaks!
 */
BST::~BST() {
    // TODO: Implemented by Heba Ragab
    // Call clearHelper to delete all nodes
}

/*
 * Function: deleteRequest (public)
 * Owner: Heba Ragab
 * Purpose: Remove request from BST
 */
bool BST::deleteRequest(int requestId) {
    // TODO: Implemented by Heba Ragab
    // 1. Call deleteHelper
    // 2. Update count if deleted
    // 3. Return true if successful
    return false;  // Placeholder
}

/*
 * Function: deleteHelper (private recursive)
 * Owner: Heba Ragab
 * Purpose: Recursive delete helper
 * NOTE: MOST COMPLEX BST FUNCTION - 3 cases!
 *       Case 1: Node with no children (leaf)
 *       Case 2: Node with one child
 *       Case 3: Node with two children (use inorder successor)
 */
BSTNode* BST::deleteHelper(BSTNode* node, int requestId) {
    // TODO: Implemented by Heba Ragab
    // 1. If node is NULL, not found
    // 2. If requestId < node->data.requestId, go left
    // 3. If requestId > node->data.requestId, go right
    // 4. If equal, found - handle 3 cases:
    //    a. No children: delete node, return NULL
    //    b. One child: return that child
    //    c. Two children: find inorder successor, copy data, delete successor
    return NULL;  // Placeholder
}

/*
 * Function: findMinNode (private)
 * Owner: Heba Ragab
 * Purpose: Find minimum node in subtree
 * NOTE: Used for finding inorder successor in delete
 */
BSTNode* BST::findMinNode(BSTNode* node) {
    // TODO: Implemented by Heba Ragab
    // 1. Go left until leftmost node
    // 2. Return that node
    return NULL;  // Placeholder
}

/*
 * Function: findMin (public)
 * Owner: Heba Ragab
 * Purpose: Find request with smallest ID
 */
BSTNode* BST::findMin() {
    // TODO: Implemented by Heba Ragab
    // Call findMinNode with root
    return NULL;  // Placeholder
}

/*
 * Function: findMax (public)
 * Owner: Heba Ragab
 * Purpose: Find request with largest ID
 */
BSTNode* BST::findMax() {
    // TODO: Implemented by Heba Ragab
    // 1. Start at root
    // 2. Go right until rightmost node
    // 3. Return that node
    return NULL;  // Placeholder
}

/*
 * Function: clear (public)
 * Owner: Heba Ragab
 * Purpose: Remove all requests
 */
void BST::clear() {
    // TODO: Implemented by Heba Ragab
    // Call clearHelper, set root to NULL, count to 0
}

// ========================================
// SECTION 3: نور وائل (Functions 15-21)
// NEW: Nour Wael gets MEANINGFUL BST work!
// ========================================

/*
 * Function: inorderTraversal (public)
 * Owner: Nour Wael
 * Purpose: Display all requests in sorted order
 * NOTE: Demonstrates tree traversal algorithm
 */
void BST::inorderTraversal() {
    // TODO: Implemented by Nour Wael
    // 1. Check if empty
    // 2. Print header
    // 3. Call inorderHelper with root
}

/*
 * Function: inorderHelper (private recursive)
 * Owner: Nour Wael
 * Purpose: Recursive inorder traversal (Left-Root-Right)
 * NOTE: Core traversal algorithm - recursive
 */
void BST::inorderHelper(BSTNode* node) {
    // TODO: Implemented by Nour Wael
    // 1. If node is NULL, return
    // 2. Recursively visit left subtree
    // 3. Display current node
    // 4. Recursively visit right subtree
}

/*
 * Function: preorderTraversal (public)
 * Owner: Nour Wael
 * Purpose: Display all requests in preorder
 */
void BST::preorderTraversal() {
    // TODO: Implemented by Nour Wael
    // 1. Check if empty
    // 2. Print header
    // 3. Call preorderHelper with root
}

/*
 * Function: preorderHelper (private recursive)
 * Owner: Nour Wael
 * Purpose: Recursive preorder traversal (Root-Left-Right)
 * NOTE: Different traversal order than inorder
 */
void BST::preorderHelper(BSTNode* node) {
    // TODO: Implemented by Nour Wael
    // 1. If node is NULL, return
    // 2. Display current node
    // 3. Recursively visit left subtree
    // 4. Recursively visit right subtree
}

/*
 * Function: updateStatus
 * Owner: Nour Wael
 * Purpose: Update request status
 */
bool BST::updateStatus(int requestId, string newStatus) {
    // TODO: Implemented by Nour Wael
    // 1. Search for request
    // 2. If found, update status
    // 3. Return true if successful
    return false;  // Placeholder
}

/*
 * Function: updateResolvedTime
 * Owner: Nour Wael
 * Purpose: Set resolved time for request
 */
bool BST::updateResolvedTime(int requestId, string resolvedTime) {
    // TODO: Implemented by Nour Wael
    // 1. Search for request
    // 2. If found, set resolvedTime
    // 3. Return true if successful
    return false;  // Placeholder
}

/*
 * Function: clearHelper (private recursive)
 * Owner: Nour Wael
 * Purpose: Recursive helper to delete all nodes
 * NOTE: Post-order traversal for deletion (Left-Right-Root)
 */
void BST::clearHelper(BSTNode* node) {
    // TODO: Implemented by Nour Wael
    // 1. If node is NULL, return
    // 2. Recursively delete left subtree
    // 3. Recursively delete right subtree
    // 4. Delete current node
}
