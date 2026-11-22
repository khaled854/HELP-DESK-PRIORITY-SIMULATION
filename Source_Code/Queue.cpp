/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: Queue.cpp
 * Implementation file for Priority Queue data structure
 * Complete all function bodies below
 */

#include "Queue.h"

// ========================================
// SECTION 1: عمر محمد (Functions 1-5)
// Work on these FIRST, then commit
// ========================================

// Constructor - Initialize empty queue
Queue::Queue() {
    // TODO: 
    // Initialize frontIndex = 0
    // Initialize rearIndex = -1
    // Initialize count = 0
}

// Destructor
Queue::~Queue() {
    // TODO: Clean up if needed (not required for array-based queue)
}

// Add request to queue with priority
bool Queue::enqueue(int requestId, string customerName, string issueType, 
                    string description, int priority, string timestamp) {
    // TODO:
    // 1. Check if queue is full using isFull()
    // 2. If full, return false
    // 3. Increment rearIndex (use circular: rearIndex = (rearIndex + 1) % MAX_SIZE)
    // 4. Create new ServiceRequest and assign all values
    // 5. Set status to "Waiting"
    // 6. Add to data[rearIndex]
    // 7. Increment count
    // 8. Return true
    //
    // Note: For priority queue, you may want to insert in sorted order
    // or find highest priority when dequeueing
}

// Remove and return highest priority request
ServiceRequest Queue::dequeue() {
    // TODO:
    // 1. Check if queue is empty
    // 2. If empty, display error and return empty ServiceRequest
    // 3. Find highest priority request using getHighestPriority()
    // 4. Get the request at that index
    // 5. Shift elements or mark as removed
    // 6. Update frontIndex (circular: frontIndex = (frontIndex + 1) % MAX_SIZE)
    // 7. Decrement count
    // 8. Return the request
}

// View front request without removing
ServiceRequest Queue::front() {
    // TODO:
    // 1. Check if queue is empty
    // 2. If empty, display error and return empty ServiceRequest
    // 3. Find highest priority request
    // 4. Return copy of that request
}

// Check if queue is empty
bool Queue::isEmpty() {
    // TODO: Return true if count == 0, false otherwise
}

// Check if queue is full
bool Queue::isFull() {
    // TODO: Return true if count == MAX_SIZE, false otherwise
}

// Get current size
int Queue::size() {
    // TODO: Return count
}

// Display all requests in queue
void Queue::display() {
    // TODO:
    // 1. Check if empty and display message
    // 2. Print header
    // 3. Loop through all requests (use circular index)
    // 4. Display each request with details:
    //    - Request ID
    //    - Customer Name
    //    - Issue Type
    //    - Description
    //    - Priority (show as text: Low/Medium/High/Critical)
    //    - Timestamp
    //    - Status
    // 5. Sort or indicate priority order
}

// Clear all requests
void Queue::clear() {
    // TODO:
    // Reset frontIndex = 0
    // Reset rearIndex = -1
    // Reset count = 0
}

// Helper: Find highest priority request
int Queue::getHighestPriority() {
    // TODO:
    // 1. If empty, return -1
    // 2. Loop through all requests in queue
    // 3. Find request with highest priority value (4 = Critical is highest)
    // 4. If same priority, use FIFO (first one added)
    // 5. Return index of highest priority request
}
