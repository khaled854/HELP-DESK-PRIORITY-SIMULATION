/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: HelpDesk.h
 * Header file for main HelpDesk system class
 * Integrates Stack, Queue, LinkedList, and BST
 * Manages overall help desk operations
 * 
 * Required Operations:
 * - createRequest(): Create new service request
 * - escalateRequest(): Move request to escalation stack
 * - assignAgent(): Assign available agent to request
 * - resolveRequest(): Mark request as resolved
 * - displayStatistics(): Show system statistics
 * - searchAndSort(): Implement searching/sorting algorithm
 */

#ifndef HELPDESK_H
#define HELPDESK_H

#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "BST.h"
#include <iostream>
#include <string>
using namespace std;

class HelpDesk {
private:
    Stack escalationStack;        // For escalated requests
    Queue requestQueue;           // For pending requests
    LinkedList agentList;         // For agent management
    BST requestTree;              // For fast request lookup
    int nextRequestId;            // Auto-increment ID counter
    int totalRequests;            // Total requests created
    int resolvedRequests;         // Total resolved requests
    int escalatedRequests;        // Total escalated requests

public:
    /*
     * Constructor
     * Purpose: Initialize help desk system
     * Parameters: None
     * Returns: None
     */
    HelpDesk();

    /*
     * Destructor
     * Purpose: Clean up resources
     * Parameters: None
     * Returns: None
     */
    ~HelpDesk();

    /*
     * Function: createRequest
     * Purpose: Create new service request and add to queue
     * Parameters:
     *   - customerName: Customer's name
     *   - issueType: Type of issue (Hardware/Software/Network/Other)
     *   - description: Detailed description
     *   - priority: Priority level (1-4)
     * Returns: int - Request ID of created request
     */
    int createRequest(string customerName, string issueType, 
                      string description, int priority);

    /*
     * Function: processNextRequest
     * Purpose: Dequeue highest priority request and assign to agent
     * Parameters: None
     * Returns: bool - true if request processed, false if queue empty
     */
    bool processNextRequest();

    /*
     * Function: escalateRequest
     * Purpose: Move request to escalation stack
     * Parameters:
     *   - requestId: ID of request to escalate
     *   - agentName: Name of agent escalating
     *   - reason: Reason for escalation
     * Returns: bool - true if escalated, false if request not found
     */
    bool escalateRequest(int requestId, string agentName, string reason);

    /*
     * Function: resolveRequest
     * Purpose: Mark request as resolved
     * Parameters:
     *   - requestId: ID of request to resolve
     * Returns: bool - true if resolved, false if not found
     */
    bool resolveRequest(int requestId);

    /*
     * Function: addAgent
     * Purpose: Add new agent to system
     * Parameters:
     *   - agentId: Unique agent ID
     *   - name: Agent's name
     *   - specialization: Area of expertise
     *   - email: Contact email
     *   - phoneNumber: Contact phone
     * Returns: bool - true if added, false if ID exists
     */
    bool addAgent(int agentId, string name, string specialization,
                  string email, string phoneNumber);

    /*
     * Function: removeAgent
     * Purpose: Remove agent from system
     * Parameters:
     *   - agentId: ID of agent to remove
     * Returns: bool - true if removed, false if not found
     */
    bool removeAgent(int agentId);

    /*
     * Function: viewRequest
     * Purpose: Display details of specific request
     * Parameters:
     *   - requestId: ID of request to view
     * Returns: void
     */
    void viewRequest(int requestId);

    /*
     * Function: viewAllRequests
     * Purpose: Display all requests in system (using BST inorder)
     * Parameters: None
     * Returns: void
     */
    void viewAllRequests();

    /*
     * Function: viewPendingRequests
     * Purpose: Display all requests waiting in queue
     * Parameters: None
     * Returns: void
     */
    void viewPendingRequests();

    /*
     * Function: viewEscalations
     * Purpose: Display all escalated requests in stack
     * Parameters: None
     * Returns: void
     */
    void viewEscalations();

    /*
     * Function: viewAllAgents
     * Purpose: Display all agents in system
     * Parameters: None
     * Returns: void
     */
    void viewAllAgents();

    /*
     * Function: displayStatistics
     * Purpose: Show system statistics and metrics
     * Parameters: None
     * Returns: void
     * Statistics to show:
     *   - Total requests created
     *   - Pending requests (in queue)
     *   - In-progress requests
     *   - Resolved requests
     *   - Escalated requests
     *   - Total agents
     *   - Available agents
     *   - Busy agents
     */
    void displayStatistics();

    /*
     * Function: searchRequestById
     * Purpose: Search for request using BST (O(log n) average)
     * Parameters:
     *   - requestId: ID to search for
     * Returns: bool - true if found, false otherwise
     */
    bool searchRequestById(int requestId);

    /*
     * Function: sortRequestsByPriority
     * Purpose: Implement sorting algorithm (Bubble/Insertion/Selection sort)
     *          Sort pending requests by priority
     * Parameters: None
     * Returns: void
     * Note: This demonstrates sorting algorithm requirement
     */
    void sortRequestsByPriority();

    /*
     * Function: linearSearchAgent
     * Purpose: Search agent by name using linear search
     * Parameters:
     *   - name: Agent name to search
     * Returns: void - Display agent if found
     * Note: This demonstrates searching algorithm requirement
     */
    void linearSearchAgent(string name);

    /*
     * Function: assignAgentToRequest
     * Purpose: Manually assign specific agent to request
     * Parameters:
     *   - requestId: ID of request
     *   - agentId: ID of agent to assign
     * Returns: bool - true if assigned, false on error
     */
    bool assignAgentToRequest(int requestId, int agentId);

    /*
     * Function: processEscalation
     * Purpose: Pop escalation from stack and handle it
     * Parameters: None
     * Returns: bool - true if escalation processed, false if stack empty
     */
    bool processEscalation();

    /*
     * Function: getCurrentTimestamp
     * Purpose: Get current date/time as string
     * Parameters: None
     * Returns: string - formatted timestamp
     * Note: Helper function for timestamps
     */
    string getCurrentTimestamp();

    /*
     * Function: getNextRequestId
     * Purpose: Generate next unique request ID
     * Parameters: None
     * Returns: int - next ID
     */
    int getNextRequestId();
};

#endif // HELPDESK_H
