/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: LinkedList.cpp
 * Implementation: Linked List data structure
 * 
 * SKELETON VERSION - Function bodies are intentionally empty
 * Team members will implement their assigned functions
 */

#include "LinkedList.h"

// ========================================
// SECTION 1: نور محمد (Functions 1-7)
// ========================================

/*
 * Constructor
 * Owner: Nour Mohamed
 * Purpose: Initialize empty list
 */
LinkedList::LinkedList() {
    // TODO: Implemented by Nour Mohamed
    // Initialize head to NULL, count to 0
}

/*
 * Function: insertAgent
 * Owner: Nour Mohamed
 * Purpose: Add new agent to list
 */
bool LinkedList::insertAgent(int agentId, string name, string specialization,
                              string email, string phoneNumber) {
    // TODO: Implemented by Nour Mohamed
    // 1. Create new node
    // 2. Fill agent data
    // 3. Insert at appropriate position
    // 4. Update count
    // 5. Return true
    return false;  // Placeholder
}

/*
 * Function: searchAgent
 * Owner: Nour Mohamed
 * Purpose: Find agent by ID
 */
Node* LinkedList::searchAgent(int agentId) {
    // TODO: Implemented by Nour Mohamed
    // 1. Traverse list from head
    // 2. Compare each agent's ID
    // 3. Return node if found, NULL otherwise
    return NULL;  // Placeholder
}

/*
 * Function: displayAgents
 * Owner: Nour Mohamed
 * Purpose: Display all agents
 */
void LinkedList::displayAgents() {
    // TODO: Implemented by Nour Mohamed
    // 1. Check if empty
    // 2. Print header
    // 3. Traverse list
    // 4. Display each agent's information
}

/*
 * Function: isEmpty
 * Owner: Nour Mohamed
 * Purpose: Check if list is empty
 */
bool LinkedList::isEmpty() {
    // TODO: Implemented by Nour Mohamed
    // Return true if head == NULL
    return true;  // Placeholder
}

/*
 * Function: getCount
 * Owner: Nour Mohamed
 * Purpose: Get total number of agents
 */
int LinkedList::getCount() {
    // TODO: Implemented by Nour Mohamed
    // Return count
    return 0;  // Placeholder
}

/*
 * Function: assignRequest
 * Owner: Nour Mohamed
 * Purpose: Increment assigned requests for an agent
 */
bool LinkedList::assignRequest(int agentId) {
    // TODO: Implemented by Nour Mohamed
    // 1. Search for agent
    // 2. If found, increment assignedRequests
    // 3. Return true if successful
    return false;  // Placeholder
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
LinkedList::~LinkedList() {
    // TODO: Implemented by Heba Ragab
    // 1. Traverse list
    // 2. Delete each node
    // 3. Free all memory
}

/*
 * Function: deleteAgent
 * Owner: Heba Ragab
 * Purpose: Remove agent by ID
 * NOTE: Handle head, middle, tail cases + memory management
 */
bool LinkedList::deleteAgent(int agentId) {
    // TODO: Implemented by Heba Ragab
    // 1. Find agent
    // 2. Handle different cases (head/middle/tail)
    // 3. Update pointers
    // 4. Delete node and free memory
    // 5. Update count
    // 6. Return true if deleted
    return false;  // Placeholder
}

/*
 * Function: updateAgent
 * Owner: Heba Ragab
 * Purpose: Modify agent information
 */
bool LinkedList::updateAgent(int agentId, string name, string specialization,
                              string email, string phoneNumber) {
    // TODO: Implemented by Heba Ragab
    // 1. Search for agent
    // 2. If found, update fields (if not empty)
    // 3. Return true if successful
    return false;  // Placeholder
}

/*
 * Function: unassignRequest
 * Owner: Heba Ragab
 * Purpose: Decrement assigned requests for an agent
 */
bool LinkedList::unassignRequest(int agentId) {
    // TODO: Implemented by Heba Ragab
    // 1. Search for agent
    // 2. If found, decrement assignedRequests (check > 0)
    // 3. Return true if successful
    return false;  // Placeholder
}

/*
 * Function: setAvailability
 * Owner: Heba Ragab
 * Purpose: Change agent availability
 */
bool LinkedList::setAvailability(int agentId, bool available) {
    // TODO: Implemented by Heba Ragab
    // 1. Search for agent
    // 2. If found, set isAvailable
    // 3. Return true if successful
    return false;  // Placeholder
}

/*
 * Function: findAvailableAgent
 * Owner: Heba Ragab
 * Purpose: Find available agent with matching specialization
 */
Node* LinkedList::findAvailableAgent(string specialization) {
    // TODO: Implemented by Heba Ragab
    // 1. Traverse list
    // 2. Find agent where isAvailable == true AND specialization matches
    // 3. Return node if found, NULL otherwise
    return NULL;  // Placeholder
}

/*
 * Function: clear
 * Owner: Heba Ragab
 * Purpose: Remove all agents
 * NOTE: Must free all memory!
 */
void LinkedList::clear() {
    // TODO: Implemented by Heba Ragab
    // 1. Traverse list
    // 2. Delete each node
    // 3. Free memory
    // 4. Set head to NULL, count to 0
}
