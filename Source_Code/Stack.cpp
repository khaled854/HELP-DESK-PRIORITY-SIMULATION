/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: Stack.cpp
 * Implementation: Stack data structure
 * 
 * SKELETON VERSION - Function bodies are intentionally empty
 * Team members will implement their assigned functions
 */

#include "Stack.h"

// ========================================
// SECTION 1: عمر محمد (Functions 1-5)
// ========================================

/*
 * Constructor
 * Owner: Omar Mohamed
 * Purpose: Initialize empty stack
 */
Stack::Stack() {
    // TODO: Implemented by Omar Mohamed
    // Initialize top to -1 (empty stack)
}

/*
 * Function: push
 * Owner: Omar Mohamed
 * Purpose: Add escalation to stack
 */
bool Stack::push(int requestId, string agentName, string reason, string timestamp, int priorityLevel) {
    // TODO: Implemented by Omar Mohamed
    // 1. Check if stack is full using isFull()
    // 2. If full, return false
    // 3. Increment top
    // 4. Create new Escalation and assign values
    // 5. Add to data[top]
    // 6. Return true
    return false;  // Placeholder
}

/*
 * Function: pop
 * Owner: Omar Mohamed
 * Purpose: Remove and return top escalation
 */
Escalation Stack::pop() {
    // TODO: Implemented by Omar Mohamed
    // 1. Check if empty
    // 2. If empty, display error and return empty Escalation
    // 3. Get escalation at data[top]
    // 4. Decrement top
    // 5. Return the escalation
    Escalation empty;
    empty.requestId = -1;
    return empty;  // Placeholder
}

/*
 * Function: peek
 * Owner: Omar Mohamed
 * Purpose: View top without removing
 */
Escalation Stack::peek() {
    // TODO: Implemented by Omar Mohamed
    // 1. Check if empty
    // 2. If empty, return empty Escalation
    // 3. Return copy of data[top]
    Escalation empty;
    empty.requestId = -1;
    return empty;  // Placeholder
}

/*
 * Function: isEmpty
 * Owner: Omar Mohamed
 * Purpose: Check if stack is empty
 */
bool Stack::isEmpty() {
    // TODO: Implemented by Omar Mohamed
    // Return true if top == -1
    return true;  // Placeholder
}

// ========================================
// SECTION 2: خالد طه (Functions 6-10)
// ========================================

/*
 * Destructor
 * Owner: Khaled Taha
 * Purpose: Clean up resources
 */
Stack::~Stack() {
    // TODO: Implemented by Khaled Taha
    // Array-based: nothing to clean
}

/*
 * Function: isFull
 * Owner: Khaled Taha
 * Purpose: Check if stack is full
 */
bool Stack::isFull() {
    // TODO: Implemented by Khaled Taha
    // Return true if top == MAX_SIZE-1
    return false;  // Placeholder
}

/*
 * Function: size
 * Owner: Khaled Taha
 * Purpose: Get current size
 */
int Stack::size() {
    // TODO: Implemented by Khaled Taha
    // Return top + 1
    return 0;  // Placeholder
}

/*
 * Function: display
 * Owner: Khaled Taha
 * Purpose: Display all escalations
 */
void Stack::display() {
    // TODO: Implemented by Khaled Taha
    // 1. Check if empty
    // 2. Print header
    // 3. Loop from top to 0
    // 4. Display each escalation details
}

/*
 * Function: clear
 * Owner: Khaled Taha
 * Purpose: Clear all escalations
 */
void Stack::clear() {
    // TODO: Implemented by Khaled Taha
    // Set top to -1
}
