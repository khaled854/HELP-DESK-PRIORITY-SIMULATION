/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: Queue.cpp
 * Implementation: Priority Queue data structure
 * 
 * SKELETON VERSION - Function bodies are intentionally empty
 * Team members will implement their assigned functions
 */

#include "Queue.h"

// ========================================
// SECTION 1: عمر محمد (Functions 1-5)
// ========================================

/*
 * Constructor
 * Owner: Omar Mohamed
 * Purpose: Initialize empty queue
 */
Queue::Queue() {
    // TODO: Implemented by Omar Mohamed
    // Initialize frontIndex, rearIndex, count
}

/*
 * Function: enqueue
 * Owner: Omar Mohamed
 * Purpose: Add request to queue
 */
bool Queue::enqueue(int requestId, string customerName, string issueType,
                    string description, int priority, string timestamp) {
    // TODO: Implemented by Omar Mohamed
    // 1. Check if full
    // 2. If full, return false
    // 3. Add to queue (consider priority)
    // 4. Update indices and count
    // 5. Return true
    return false;  // Placeholder
}

/*
 * Function: front
 * Owner: Omar Mohamed
 * Purpose: View front request
 */
ServiceRequest Queue::front() {
    // TODO: Implemented by Omar Mohamed
    // 1. Check if empty
    // 2. Return front request
    ServiceRequest empty;
    empty.requestId = -1;
    return empty;  // Placeholder
}

/*
 * Function: isEmpty
 * Owner: Omar Mohamed
 * Purpose: Check if empty
 */
bool Queue::isEmpty() {
    // TODO: Implemented by Omar Mohamed
    // Return true if count == 0
    return true;  // Placeholder
}

/*
 * Function: size
 * Owner: Omar Mohamed
 * Purpose: Get current size
 */
int Queue::size() {
    // TODO: Implemented by Omar Mohamed
    // Return count
    return 0;  // Placeholder
}

// ========================================
// SECTION 2: خالد طه (Functions 6-11)
// ========================================

/*
 * Destructor
 * Owner: Khaled Taha
 * Purpose: Clean up resources
 */
Queue::~Queue() {
    // TODO: Implemented by Khaled Taha
    // Array-based: nothing to clean
}

/*
 * Function: dequeue
 * Owner: Khaled Taha
 * Purpose: Remove highest priority request
 * NOTE: This is the MOST COMPLEX queue function
 */
ServiceRequest Queue::dequeue() {
    // TODO: Implemented by Khaled Taha
    // 1. Check if empty
    // 2. Find highest priority using getHighestPriority()
    // 3. Remove that request
    // 4. Shift elements if needed
    // 5. Update count
    // 6. Return the request
    ServiceRequest empty;
    empty.requestId = -1;
    return empty;  // Placeholder
}

/*
 * Function: isFull
 * Owner: Khaled Taha
 * Purpose: Check if full
 */
bool Queue::isFull() {
    // TODO: Implemented by Khaled Taha
    // Return true if count == MAX_SIZE
    return false;  // Placeholder
}

/*
 * Function: display
 * Owner: Khaled Taha
 * Purpose: Display all requests
 */
void Queue::display() {
    // TODO: Implemented by Khaled Taha
    // 1. Check if empty
    // 2. Print header
    // 3. Loop through queue
    // 4. Display each request with priority
}

/*
 * Function: clear
 * Owner: Khaled Taha
 * Purpose: Clear all requests
 */
void Queue::clear() {
    // TODO: Implemented by Khaled Taha
    // Reset frontIndex, rearIndex, count
}

/*
 * Function: getHighestPriority
 * Owner: Khaled Taha
 * Purpose: Find index of highest priority request
 * NOTE: Helper for dequeue - complex priority logic
 */
int Queue::getHighestPriority() {
    // TODO: Implemented by Khaled Taha
    // 1. Loop through queue
    // 2. Find request with highest priority (4=Critical is highest)
    // 3. Return its index
    return -1;  // Placeholder
}
