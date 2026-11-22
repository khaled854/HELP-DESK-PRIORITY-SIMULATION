/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: Stack.cpp
 * Description: Implementation of Stack data structure
 */

#include "Stack.h"

// ========================================
// SECTION 1: عمر محمد (Functions 1-5)
// Work on these FIRST, then commit
// ========================================

// Constructor - Initialize empty stack
Stack::Stack() {
    // TODO: Initialize top to -1 (empty stack)
}

// Destructor
Stack::~Stack() {
    // TODO: Clean up if needed (not required for array-based stack)
}

// Push new escalation to stack
bool Stack::push(int requestId, string agentName, string reason, string timestamp, int priorityLevel) {
    // TODO: 
    // 1. Check if stack is full using isFull()
    // 2. If full, return false
    // 3. Increment top
    // 4. Create new Escalation and assign values
    // 5. Add to data[top]
    // 6. Return true
}

// Pop top escalation from stack
Escalation Stack::pop() {
    // TODO:
    // 1. Check if stack is empty using isEmpty()
    // 2. If empty, display error and return empty Escalation
    // 3. Get escalation at data[top]
    // 4. Decrement top
    // 5. Return the escalation
}

// Peek at top escalation without removing
Escalation Stack::peek() {
    // TODO:
    // 1. Check if stack is empty
    // 2. If empty, display error and return empty Escalation
    // 3. Return copy of data[top]
}

// Check if stack is empty
bool Stack::isEmpty() {
    // TODO: Return true if top == -1, false otherwise
}

// ========================================
// END OF SECTION 1 (عمر محمد)
// Commit your work before continuing!
// ========================================


// ========================================
// SECTION 2: خالد طه (Functions 6-10)
// Work on these AFTER عمر commits
// ========================================

// Destructor
Stack::~Stack() {
    // TODO: Clean up if needed (not required for array-based stack)
}

// Check if stack is full
bool Stack::isFull() {
    // TODO: Return true if top == MAX_SIZE-1, false otherwise
}

// Get current size of stack
int Stack::size() {
    // TODO: Return top + 1 (number of elements)
}

// Display all escalations in stack
void Stack::display() {
    // TODO:
    // 1. Check if empty and display message
    // 2. Print header
    // 3. Loop from top to 0
    // 4. Display each escalation with details:
    //    - Request ID
    //    - Agent Name
    //    - Reason
    //    - Timestamp
    //    - Priority Level
}

// Clear all escalations from stack
void Stack::clear() {
    // TODO: Set top to -1
}

// ========================================
// END OF SECTION 2 (خالد طه)
// All Stack functions complete!
// ========================================
