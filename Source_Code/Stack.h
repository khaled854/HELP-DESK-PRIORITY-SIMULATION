/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: Stack.h
 * Header file for Stack data structure
 * Used for tracking recent escalations (LIFO - Last In First Out)
 * 
 * Required Operations:
 * - push(): Add escalation to top of stack
 * - pop(): Remove and return top escalation
 * - peek(): View top escalation without removing
 * - isEmpty(): Check if stack is empty
 * - isFull(): Check if stack is full (if using array)
 * - size(): Return number of escalations
 * - display(): Show all escalations in stack
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;

// Structure for Escalation Record
struct Escalation {
    int requestId;           // ID of escalated request
    string agentName;        // Name of agent who escalated
    string reason;           // Reason for escalation
    string timestamp;        // Time of escalation
    int priorityLevel;       // Priority level (1=Low, 2=Medium, 3=High, 4=Critical)
};

class Stack {
private:
    static const int MAX_SIZE = 100;  // Maximum stack size
    Escalation data[MAX_SIZE];        // Array to store escalations
    int top;                          // Index of top element (-1 if empty)

public:
    /*
     * Constructor
     * Purpose: Initialize empty stack
     * Parameters: None
     * Returns: None
     */
    Stack();

    /*
     * Destructor
     * Purpose: Clean up resources
     * Parameters: None
     * Returns: None
     */
    ~Stack();

    /*
     * Function: push
     * Purpose: Add new escalation to top of stack
     * Parameters:
     *   - requestId: ID of request being escalated
     *   - agentName: Name of agent escalating
     *   - reason: Reason for escalation
     *   - timestamp: Current time
     *   - priorityLevel: Urgency level
     * Returns: bool - true if successful, false if stack is full
     */
    bool push(int requestId, string agentName, string reason, string timestamp, int priorityLevel);

    /*
     * Function: pop
     * Purpose: Remove and return top escalation from stack
     * Parameters: None
     * Returns: Escalation - the removed escalation (check isEmpty first!)
     */
    Escalation pop();

    /*
     * Function: peek
     * Purpose: View top escalation without removing it
     * Parameters: None
     * Returns: Escalation - copy of top escalation
     */
    Escalation peek();

    /*
     * Function: isEmpty
     * Purpose: Check if stack has no elements
     * Parameters: None
     * Returns: bool - true if empty, false otherwise
     */
    bool isEmpty();

    /*
     * Function: isFull
     * Purpose: Check if stack is at maximum capacity
     * Parameters: None
     * Returns: bool - true if full, false otherwise
     */
    bool isFull();

    /*
     * Function: size
     * Purpose: Get current number of escalations in stack
     * Parameters: None
     * Returns: int - number of elements
     */
    int size();

    /*
     * Function: display
     * Purpose: Print all escalations in stack (top to bottom)
     * Parameters: None
     * Returns: void
     */
    void display();

    /*
     * Function: clear
     * Purpose: Remove all escalations from stack
     * Parameters: None
     * Returns: void
     */
    void clear();
};

#endif // STACK_H
