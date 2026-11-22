/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: HelpDesk.cpp
 * Implementation file for HelpDesk system
 * Complete all function bodies below
 */

#include "HelpDesk.h"
#include <ctime>

// Constructor
HelpDesk::HelpDesk() {
    // TODO:
    // Initialize nextRequestId = 1001
    // Initialize totalRequests = 0
    // Initialize resolvedRequests = 0
    // Initialize escalatedRequests = 0
}

// Destructor
HelpDesk::~HelpDesk() {
    // TODO:
    // Clean up if needed (data structures have their own destructors)
}

// Create new service request
int HelpDesk::createRequest(string customerName, string issueType, 
                            string description, int priority) {
    // TODO:
    // 1. Get current timestamp using getCurrentTimestamp()
    // 2. Get new request ID using getNextRequestId()
    // 3. Add request to queue using requestQueue.enqueue()
    // 4. Add request to BST using requestTree.insert()
    //    - Set status to "Waiting"
    //    - Set assignedAgent to "None"
    // 5. Increment totalRequests
    // 6. Display success message with request ID
    // 7. Return request ID
}

// Process next request from queue
bool HelpDesk::processNextRequest() {
    // TODO:
    // 1. Check if queue is empty
    // 2. If empty, display message and return false
    // 3. Dequeue request from requestQueue
    // 4. Find available agent with matching specialization
    //    - Use agentList.findAvailableAgent()
    // 5. If agent found:
    //    - Update request status to "InProgress" in BST
    //    - Assign agent to request
    //    - Call agentList.assignRequest()
    //    - Display assignment details
    // 6. If no agent available:
    //    - Display "No available agents" message
    //    - Re-enqueue the request
    // 7. Return true
}

// Escalate request
bool HelpDesk::escalateRequest(int requestId, string agentName, string reason) {
    // TODO:
    // 1. Search for request in BST
    // 2. If not found, return false
    // 3. Get request priority from BST node
    // 4. Get timestamp
    // 5. Push to escalationStack with details
    // 6. Update request status to "Escalated" in BST
    // 7. Increment escalatedRequests
    // 8. Display escalation confirmation
    // 9. Return true
}

// Resolve request
bool HelpDesk::resolveRequest(int requestId) {
    // TODO:
    // 1. Search for request in BST
    // 2. If not found, return false
    // 3. Get assigned agent name from request
    // 4. Update request status to "Resolved"
    // 5. Set resolved time using getCurrentTimestamp()
    // 6. If agent was assigned, call agentList.unassignRequest()
    // 7. Increment resolvedRequests
    // 8. Display resolution confirmation
    // 9. Return true
}

// Add new agent
bool HelpDesk::addAgent(int agentId, string name, string specialization,
                        string email, string phoneNumber) {
    // TODO:
    // 1. Try to insert agent using agentList.insertAgent()
    // 2. If successful, display confirmation
    // 3. If failed (duplicate ID), display error
    // 4. Return result
}

// Remove agent
bool HelpDesk::removeAgent(int agentId) {
    // TODO:
    // 1. Check if agent has assigned requests
    // 2. If yes, display warning and ask for confirmation
    // 3. Try to delete agent using agentList.deleteAgent()
    // 4. Display result message
    // 5. Return result
}

// View specific request
void HelpDesk::viewRequest(int requestId) {
    // TODO:
    // 1. Search in BST using requestTree.search()
    // 2. If not found, display "Request not found"
    // 3. If found, display all request details:
    //    - Request ID
    //    - Customer Name
    //    - Issue Type
    //    - Assigned Agent
    //    - Status
    //    - Created Time
    //    - Resolved Time (if resolved)
}

// View all requests (sorted by ID)
void HelpDesk::viewAllRequests() {
    // TODO:
    // 1. Check if BST is empty
    // 2. If empty, display "No requests in system"
    // 3. Display header
    // 4. Call requestTree.inorderTraversal()
}

// View pending requests in queue
void HelpDesk::viewPendingRequests() {
    // TODO:
    // Call requestQueue.display()
}

// View escalations in stack
void HelpDesk::viewEscalations() {
    // TODO:
    // Call escalationStack.display()
}

// View all agents
void HelpDesk::viewAllAgents() {
    // TODO:
    // Call agentList.displayAgents()
}

// Display system statistics
void HelpDesk::displayStatistics() {
    // TODO:
    // Calculate and display:
    // 1. Total requests created (totalRequests)
    // 2. Requests in queue (requestQueue.size())
    // 3. Resolved requests (resolvedRequests)
    // 4. Escalated requests (escalatedRequests)
    // 5. In-progress requests (calculate from BST or track separately)
    // 6. Total agents (agentList.getCount())
    // 7. Available agents (loop through agents and count)
    // 8. Busy agents (total - available)
    // 
    // Display in organized format with labels
}

// Search request by ID (BST search - O(log n))
bool HelpDesk::searchRequestById(int requestId) {
    // TODO:
    // 1. Call requestTree.search(requestId)
    // 2. If found, display request details
    // 3. If not found, display "Request not found"
    // 4. Return true if found, false otherwise
}

// Sort requests by priority (Sorting Algorithm Requirement)
void HelpDesk::sortRequestsByPriority() {
    // TODO:
    // Implement one of: Bubble Sort, Insertion Sort, or Selection Sort
    // 
    // 1. Get all pending requests from queue into array
    // 2. Apply sorting algorithm to sort by priority (highest first)
    // 3. Display sorted list
    // 4. Optionally: reconstruct queue in sorted order
    //
    // Example: Bubble Sort
    // - Compare adjacent elements
    // - Swap if priority[i] < priority[i+1]
    // - Repeat until sorted
    //
    // Display Big-O complexity: O(n²) for bubble/insertion/selection sort
}

// Linear search for agent (Searching Algorithm Requirement)
void HelpDesk::linearSearchAgent(string name) {
    // TODO:
    // Implement Linear Search algorithm
    // 
    // 1. Traverse agentList from head to end
    // 2. Compare each agent name with search name
    // 3. If match found:
    //    - Display agent details
    //    - Note: found at position X
    // 4. If not found, display "Agent not found"
    // 5. Display Big-O complexity: O(n) for linear search
}

// Assign specific agent to request
bool HelpDesk::assignAgentToRequest(int requestId, int agentId) {
    // TODO:
    // 1. Search for request in BST
    // 2. If not found, return false
    // 3. Search for agent in linked list
    // 4. If not found, return false
    // 5. Check if agent is available
    // 6. If not available, display warning
    // 7. Update request with agent name
    // 8. Call agentList.assignRequest(agentId)
    // 9. Update status to "InProgress"
    // 10. Return true
}

// Process escalation from stack
bool HelpDesk::processEscalation() {
    // TODO:
    // 1. Check if escalation stack is empty
    // 2. If empty, return false
    // 3. Pop escalation from stack
    // 4. Display escalation details
    // 5. Assign to senior agent or handle specially
    // 6. Update request status in BST
    // 7. Return true
}

// Get current timestamp
string HelpDesk::getCurrentTimestamp() {
    // TODO:
    // Use C++ time functions to get current date and time
    // Format: "YYYY-MM-DD HH:MM:SS" or similar
    // 
    // Example implementation:
    // time_t now = time(0);
    // tm* ltm = localtime(&now);
    // Format and return as string
    //
    // For now, you can return a placeholder like "2026-11-22 10:30:00"
}

// Get next request ID
int HelpDesk::getNextRequestId() {
    // TODO:
    // Return nextRequestId and increment it
    // return nextRequestId++;
}
