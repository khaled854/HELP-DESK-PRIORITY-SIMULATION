/*
 * CS212 - Data Structures Project
 * Help Desk Priority Simulation
 * 
 * File: Queue.h
 * Header file for Priority Queue data structure
 * Used for managing service requests by priority (FIFO with priority)
 * 
 * Required Operations:
 * - enqueue(): Add request to queue based on priority
 * - dequeue(): Remove and return highest priority request
 * - front(): View front request without removing
 * - isEmpty(): Check if queue is empty
 * - isFull(): Check if queue is full
 * - size(): Return number of requests
 * - display(): Show all requests in queue
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

// Structure for Service Request
struct ServiceRequest {
    int requestId;           // Unique request ID
    string customerName;     // Name of customer
    string issueType;        // Type of issue (Hardware, Software, Network, Other)
    string description;      // Detailed description
    int priority;            // Priority: 1=Low, 2=Medium, 3=High, 4=Critical
    string timestamp;        // Time request was created
    string status;           // Status: Waiting, InProgress, Resolved
};

class Queue {
private:
    static const int MAX_SIZE = 100;  // Maximum queue size
    ServiceRequest data[MAX_SIZE];    // Array to store requests
    int frontIndex;                   // Index of front element
    int rearIndex;                    // Index of rear element
    int count;                        // Number of elements in queue

public:
    /*
     * Constructor
     * Purpose: Initialize empty queue
     * Parameters: None
     * Returns: None
     */
    Queue();

    /*
     * Destructor
     * Purpose: Clean up resources
     * Parameters: None
     * Returns: None
     */
    ~Queue();

    /*
     * Function: enqueue
     * Purpose: Add new service request to queue based on priority
     *          Higher priority requests should be processed first
     * Parameters:
     *   - requestId: Unique ID for request
     *   - customerName: Customer's name
     *   - issueType: Category of issue
     *   - description: Details of problem
     *   - priority: Urgency level (1-4)
     *   - timestamp: Current time
     * Returns: bool - true if successful, false if queue is full
     */
    bool enqueue(int requestId, string customerName, string issueType, 
                 string description, int priority, string timestamp);

    /*
     * Function: dequeue
     * Purpose: Remove and return highest priority request from queue
     * Parameters: None
     * Returns: ServiceRequest - the removed request
     */
    ServiceRequest dequeue();

    /*
     * Function: front
     * Purpose: View front request without removing it
     * Parameters: None
     * Returns: ServiceRequest - copy of front request
     */
    ServiceRequest front();

    /*
     * Function: isEmpty
     * Purpose: Check if queue has no elements
     * Parameters: None
     * Returns: bool - true if empty, false otherwise
     */
    bool isEmpty();

    /*
     * Function: isFull
     * Purpose: Check if queue is at maximum capacity
     * Parameters: None
     * Returns: bool - true if full, false otherwise
     */
    bool isFull();

    /*
     * Function: size
     * Purpose: Get current number of requests in queue
     * Parameters: None
     * Returns: int - number of elements
     */
    int size();

    /*
     * Function: display
     * Purpose: Print all requests in queue (front to rear)
     *          Show priority order
     * Parameters: None
     * Returns: void
     */
    void display();

    /*
     * Function: clear
     * Purpose: Remove all requests from queue
     * Parameters: None
     * Returns: void
     */
    void clear();

    /*
     * Function: getHighestPriority
     * Purpose: Find index of highest priority request in queue
     * Parameters: None
     * Returns: int - index of highest priority request
     * Note: This is a helper function for priority queue behavior
     */
    int getHighestPriority();
};

#endif // QUEUE_H
