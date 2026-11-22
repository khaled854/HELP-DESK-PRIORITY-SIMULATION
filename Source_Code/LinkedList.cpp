/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: LinkedList.cpp
 * Implementation file for Linked List data structure
 * Complete all function bodies below
 */

#include "LinkedList.h"

// ========================================
// SECTION 1: نور محمد (Functions 1-7)
// Work on these FIRST, then commit
// ========================================

// Constructor - Initialize empty list
LinkedList::LinkedList() {
    // TODO:
    // Set head = NULL
    // Set count = 0
}

// Destructor - Delete all nodes
LinkedList::~LinkedList() {
    // TODO:
    // Call clear() to delete all nodes
}

// Insert new agent
bool LinkedList::insertAgent(int agentId, string name, string specialization, 
                             string email, string phoneNumber) {
    // TODO:
    // 1. Check if agent ID already exists using searchAgent()
    // 2. If exists, return false
    // 3. Create new Node
    // 4. Fill agent data:
    //    - agentId
    //    - name
    //    - specialization
    //    - email
    //    - phoneNumber
    //    - assignedRequests = 0
    //    - isAvailable = true
    // 5. Insert at beginning (or sorted by ID):
    //    - Set newNode->next = head
    //    - Set head = newNode
    // 6. Increment count
    // 7. Return true
}

// Delete agent by ID
bool LinkedList::deleteAgent(int agentId) {
    // TODO:
    // 1. Check if list is empty
    // 2. If empty, return false
    // 3. If head node has the ID:
    //    - temp = head
    //    - head = head->next
    //    - delete temp
    //    - decrement count
    //    - return true
    // 4. Otherwise, traverse list:
    //    - Keep previous and current pointers
    //    - When found: previous->next = current->next
    //    - delete current
    //    - decrement count
    //    - return true
    // 5. If not found, return false
}

// Search for agent by ID
Node* LinkedList::searchAgent(int agentId) {
    // TODO:
    // 1. Start from head
    // 2. Traverse list while current != NULL
    // 3. If current->data.agentId == agentId, return current
    // 4. Move to next: current = current->next
    // 5. If not found, return NULL
}

// Display all agents
void LinkedList::displayAgents() {
    // TODO:
    // 1. Check if list is empty
    // 2. If empty, display "No agents available"
    // 3. Print header
    // 4. Traverse from head to end
    // 5. For each node, display:
    //    - Agent ID
    //    - Name
    //    - Specialization
    //    - Email
    //    - Phone Number
    //    - Assigned Requests count
    //    - Availability status (Available/Busy)
}

// Update agent information
bool LinkedList::updateAgent(int agentId, string name, string specialization, 
                            string email, string phoneNumber) {
    // TODO:
    // 1. Search for agent using searchAgent()
    // 2. If not found, return false
    // 3. Update fields (only if new value is not empty string):
    //    - if name != "", update name
    //    - if specialization != "", update specialization
    //    - if email != "", update email
    //    - if phoneNumber != "", update phoneNumber
    // 4. Return true
}

// Get number of agents
int LinkedList::getCount() {
    // TODO: Return count
}

// Check if list is empty
bool LinkedList::isEmpty() {
    // TODO: Return true if head == NULL, false otherwise
}

// Assign request to agent
bool LinkedList::assignRequest(int agentId) {
    // TODO:
    // 1. Search for agent
    // 2. If not found, return false
    // 3. Increment assignedRequests
    // 4. If assignedRequests >= 5, set isAvailable = false
    // 5. Return true
}

// Unassign request from agent
bool LinkedList::unassignRequest(int agentId) {
    // TODO:
    // 1. Search for agent
    // 2. If not found, return false
    // 3. If assignedRequests > 0, decrement it
    // 4. If assignedRequests < 5, set isAvailable = true
    // 5. Return true
}

// Set agent availability
bool LinkedList::setAvailability(int agentId, bool available) {
    // TODO:
    // 1. Search for agent
    // 2. If not found, return false
    // 3. Set isAvailable = available
    // 4. Return true
}

// Find available agent with specialization
Node* LinkedList::findAvailableAgent(string specialization) {
    // TODO:
    // 1. Traverse list from head
    // 2. Look for agent where:
    //    - isAvailable == true
    //    - agent specialization matches parameter
    // 3. Return first match
    // 4. If none found, return NULL
}

// Clear all agents
void LinkedList::clear() {
    // TODO:
    // 1. While head != NULL:
    //    - temp = head
    //    - head = head->next
    //    - delete temp
    // 2. Set count = 0
}
