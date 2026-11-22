/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: LinkedList.h
 * Header file for Linked List data structure
 * Used for storing and managing agent records
 * 
 * Required Operations:
 * - insertAgent(): Add new agent to list
 * - deleteAgent(): Remove agent by ID
 * - searchAgent(): Find agent by ID
 * - displayAgents(): Show all agents
 * - updateAgent(): Modify agent information
 * - traverseList(): Visit all nodes
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

// Structure for Agent Information
struct Agent {
    int agentId;              // Unique agent ID
    string name;              // Agent's full name
    string specialization;    // Area of expertise (Hardware, Software, Network)
    int assignedRequests;     // Number of currently assigned requests
    bool isAvailable;         // Availability status
    string email;             // Contact email
    string phoneNumber;       // Contact phone
};

// Node structure for linked list
struct Node {
    Agent data;               // Agent information
    Node* next;               // Pointer to next node
};

class LinkedList {
private:
    Node* head;               // Pointer to first node
    int count;                // Number of agents in list

public:
    /*
     * Constructor
     * Purpose: Initialize empty linked list
     * Parameters: None
     * Returns: None
     */
    LinkedList();

    /*
     * Destructor
     * Purpose: Delete all nodes and free memory
     * Parameters: None
     * Returns: None
     */
    ~LinkedList();

    /*
     * Function: insertAgent
     * Purpose: Add new agent to the linked list
     *          Can insert at beginning, end, or sorted by ID
     * Parameters:
     *   - agentId: Unique ID for agent
     *   - name: Agent's name
     *   - specialization: Area of expertise
     *   - email: Contact email
     *   - phoneNumber: Contact phone
     * Returns: bool - true if successful, false if ID already exists
     */
    bool insertAgent(int agentId, string name, string specialization, 
                     string email, string phoneNumber);

    /*
     * Function: deleteAgent
     * Purpose: Remove agent from list by ID
     * Parameters:
     *   - agentId: ID of agent to remove
     * Returns: bool - true if found and deleted, false if not found
     */
    bool deleteAgent(int agentId);

    /*
     * Function: searchAgent
     * Purpose: Find agent by ID
     * Parameters:
     *   - agentId: ID to search for
     * Returns: Node* - pointer to node containing agent, NULL if not found
     */
    Node* searchAgent(int agentId);

    /*
     * Function: displayAgents
     * Purpose: Print information of all agents in list
     * Parameters: None
     * Returns: void
     */
    void displayAgents();

    /*
     * Function: updateAgent
     * Purpose: Modify agent information
     * Parameters:
     *   - agentId: ID of agent to update
     *   - name: New name (optional, pass "" to keep current)
     *   - specialization: New specialization (optional)
     *   - email: New email (optional)
     *   - phoneNumber: New phone (optional)
     * Returns: bool - true if agent found and updated, false otherwise
     */
    bool updateAgent(int agentId, string name, string specialization, 
                     string email, string phoneNumber);

    /*
     * Function: getCount
     * Purpose: Get total number of agents
     * Parameters: None
     * Returns: int - number of agents in list
     */
    int getCount();

    /*
     * Function: isEmpty
     * Purpose: Check if list has no agents
     * Parameters: None
     * Returns: bool - true if empty, false otherwise
     */
    bool isEmpty();

    /*
     * Function: assignRequest
     * Purpose: Increment assigned requests count for an agent
     * Parameters:
     *   - agentId: ID of agent
     * Returns: bool - true if successful, false if agent not found
     */
    bool assignRequest(int agentId);

    /*
     * Function: unassignRequest
     * Purpose: Decrement assigned requests count for an agent
     * Parameters:
     *   - agentId: ID of agent
     * Returns: bool - true if successful, false if agent not found
     */
    bool unassignRequest(int agentId);

    /*
     * Function: setAvailability
     * Purpose: Change agent availability status
     * Parameters:
     *   - agentId: ID of agent
     *   - available: New availability status
     * Returns: bool - true if successful, false if agent not found
     */
    bool setAvailability(int agentId, bool available);

    /*
     * Function: findAvailableAgent
     * Purpose: Find first available agent with matching specialization
     * Parameters:
     *   - specialization: Required expertise area
     * Returns: Node* - pointer to available agent, NULL if none found
     */
    Node* findAvailableAgent(string specialization);

    /*
     * Function: clear
     * Purpose: Remove all agents from list
     * Parameters: None
     * Returns: void
     */
    void clear();
};

#endif // LINKEDLIST_H
