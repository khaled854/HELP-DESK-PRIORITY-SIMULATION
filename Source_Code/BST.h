/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: BST.h
 * Header file for Binary Search Tree data structure
 * Used for fast lookup of service requests by ID
 * 
 * Required Operations:
 * - insert(): Add request to BST
 * - search(): Find request by ID
 * - delete(): Remove request from BST
 * - inorderTraversal(): Visit nodes in sorted order (Left-Root-Right)
 * - preorderTraversal(): Visit nodes (Root-Left-Right)
 * - findMin(): Find request with minimum ID
 * - findMax(): Find request with maximum ID
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

// Structure for Request Record in BST
struct RequestRecord {
    int requestId;           // Unique ID (key for BST)
    string customerName;     // Customer name
    string issueType;        // Type of issue
    string assignedAgent;    // Name of assigned agent
    string status;           // Status: Waiting, InProgress, Resolved
    string createdTime;      // Creation timestamp
    string resolvedTime;     // Resolution timestamp (empty if not resolved)
};

// BST Node structure
struct BSTNode {
    RequestRecord data;      // Request information
    BSTNode* left;           // Left child (smaller IDs)
    BSTNode* right;          // Right child (larger IDs)
};

class BST {
private:
    BSTNode* root;           // Root of the tree
    int count;               // Total number of nodes

    /*
     * Helper Functions (Private - Recursive)
     * These are called by public functions
     */

    // Recursive insert helper
    BSTNode* insertHelper(BSTNode* node, RequestRecord record);

    // Recursive search helper
    BSTNode* searchHelper(BSTNode* node, int requestId);

    // Recursive delete helper
    BSTNode* deleteHelper(BSTNode* node, int requestId);

    // Find minimum node in subtree
    BSTNode* findMinNode(BSTNode* node);

    // Recursive inorder traversal helper
    void inorderHelper(BSTNode* node);

    // Recursive preorder traversal helper
    void preorderHelper(BSTNode* node);

    // Recursive clear helper
    void clearHelper(BSTNode* node);

public:
    /*
     * Constructor
     * Purpose: Initialize empty BST
     * Parameters: None
     * Returns: None
     */
    BST();

    /*
     * Destructor
     * Purpose: Delete all nodes and free memory
     * Parameters: None
     * Returns: None
     */
    ~BST();

    /*
     * Function: insert
     * Purpose: Add new request to BST
     * Parameters:
     *   - requestId: Unique ID (must be unique!)
     *   - customerName: Customer's name
     *   - issueType: Type of issue
     *   - assignedAgent: Assigned agent name
     *   - status: Current status
     *   - createdTime: Creation time
     * Returns: bool - true if inserted, false if ID already exists
     */
    bool insert(int requestId, string customerName, string issueType,
                string assignedAgent, string status, string createdTime);

    /*
     * Function: search
     * Purpose: Find request by ID
     * Parameters:
     *   - requestId: ID to search for
     * Returns: BSTNode* - pointer to node if found, NULL otherwise
     */
    BSTNode* search(int requestId);

    /*
     * Function: deleteRequest
     * Purpose: Remove request from BST by ID
     * Parameters:
     *   - requestId: ID of request to delete
     * Returns: bool - true if deleted, false if not found
     */
    bool deleteRequest(int requestId);

    /*
     * Function: inorderTraversal
     * Purpose: Display all requests in sorted order by ID (ascending)
     * Parameters: None
     * Returns: void
     */
    void inorderTraversal();

    /*
     * Function: preorderTraversal
     * Purpose: Display all requests in preorder (Root-Left-Right)
     * Parameters: None
     * Returns: void
     */
    void preorderTraversal();

    /*
     * Function: findMin
     * Purpose: Find request with smallest ID
     * Parameters: None
     * Returns: BSTNode* - node with minimum ID, NULL if tree empty
     */
    BSTNode* findMin();

    /*
     * Function: findMax
     * Purpose: Find request with largest ID
     * Parameters: None
     * Returns: BSTNode* - node with maximum ID, NULL if tree empty
     */
    BSTNode* findMax();

    /*
     * Function: isEmpty
     * Purpose: Check if BST has no nodes
     * Parameters: None
     * Returns: bool - true if empty, false otherwise
     */
    bool isEmpty();

    /*
     * Function: getCount
     * Purpose: Get total number of requests in BST
     * Parameters: None
     * Returns: int - number of nodes
     */
    int getCount();

    /*
     * Function: updateStatus
     * Purpose: Update status of a request
     * Parameters:
     *   - requestId: ID of request
     *   - newStatus: New status value
     * Returns: bool - true if updated, false if not found
     */
    bool updateStatus(int requestId, string newStatus);

    /*
     * Function: updateResolvedTime
     * Purpose: Set resolved time for a request
     * Parameters:
     *   - requestId: ID of request
     *   - resolvedTime: Resolution timestamp
     * Returns: bool - true if updated, false if not found
     */
    bool updateResolvedTime(int requestId, string resolvedTime);

    /*
     * Function: clear
     * Purpose: Remove all requests from BST
     * Parameters: None
     * Returns: void
     */
    void clear();
};

#endif // BST_H
